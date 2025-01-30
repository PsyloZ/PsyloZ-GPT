class RA_BoxKit_Base: ItemBase
{
	#ifdef SERVER
	override void OnPlacementComplete(Man player, vector position = "0 0 0", vector orientation = "0 0 0")
	{
		super.OnPlacementComplete(player, position, orientation);

		//TurnItemIntoItemLambdaNoPlayer lambda = new TurnItemIntoItemLambdaNoPlayer(this, GetType().Substring(0,GetType().Length() - 4));
		//lambda.Execute();

		ItemBase baseitem = ItemBase.Cast(g_Game.CreateObjectEx(RA_GetItem(), position, ECE_SETUP | ECE_CREATEPHYSICS | ECE_NOLIFETIME));
		if(!baseitem) {
			Print("Kowalski "+RA_GetItem()+" at "+position+" failed to be placed!!");
		}

		baseitem.SetOrientation(orientation);

		if(baseitem.HasQuantity()) {
			baseitem.SetQuantityMax();
		}

		TerritoryHQ hq = TerritoryHQ.Cast(baseitem);
		if (hq) {
			hq.SetPlacementTimestamp(CF_Date.Now(true).DateToEpoch());

			PlayerBase gamer = PlayerBase.Cast(player)
			LBGroup grp = gamer.GetLBGroup();
			string tagLower = "";
			if (grp) {
				tagLower = grp.shortname + "";
				tagLower.ToLower();
			}
			int groupTagHash = tagLower.Hash();
			hq.ApplyPlayerGroup(tagLower, groupTagHash);
		}
	}
	#endif

	override bool IsDeployable()
	{
		return true;
	}

	override bool IsBasebuildingKit()
	{
		return true;
	}

	override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
    }
};

class TurnItemIntoItemLambdaNoPlayer: ReplaceItemWithNewLambdaBase
{
	bool m_TransferAgents;
	bool m_TransferVariables;
	bool m_TransferHealth;
	bool m_ExcludeQuantity;
	float m_quantity_override;
	
	void TurnItemIntoItemLambdaNoPlayer(EntityAI old_item, string new_item_type)
	{
		SetTransferParams();
	}
	
	void SetTransferParams (bool transfer_agents = true, bool transfer_variables = true, bool transfer_health = true, bool exclude_quantity = false, float quantity_override = -1)
	{
		m_TransferAgents = transfer_agents;
		m_TransferVariables = transfer_variables; 
		m_TransferHealth = transfer_health;
		m_ExcludeQuantity = exclude_quantity;
		m_quantity_override = quantity_override;
	}
	
	override void CopyOldPropertiesToNew (notnull EntityAI old_item, EntityAI new_item)
	{
		super.CopyOldPropertiesToNew(old_item, new_item);

		if (new_item) {
			MiscGameplayFunctions.TransferItemProperties(old_item, new_item, m_TransferAgents, m_TransferVariables, m_TransferHealth, m_ExcludeQuantity);
			
			array<EntityAI> children = new array<EntityAI>;
			old_item.GetInventory().EnumerateInventory(InventoryTraversalType.LEVELORDER, children);
			int count = children.Count();
			for (int i = 0; i < count; i++) {
				EntityAI child = children.Get(i);
				if (child) {
					InventoryLocation child_src = new InventoryLocation;
					child.GetInventory().GetCurrentInventoryLocation( child_src );
					
					InventoryLocation child_dst = new InventoryLocation;
					child_dst.Copy( child_src );
					child_dst.SetParent( new_item );
	
					bool drop = false;
					if (GameInventory.LocationCanAddEntity(child_dst)) {
						// try to move it to the same exact place in dst
						new_item.GetInventory().TakeToDst(InventoryMode.LOCAL, child_src, child_dst);
					} else {
						drop = true; // or drop otherwise
					}
	
					if (drop) {
						old_item.LocalDropEntity(child);
						g_Game.RemoteObjectTreeCreate(child);
					}
				}
			}
			
			
			//quantity override
			if (ItemBase.Cast(new_item) && m_quantity_override != -1) {
				m_quantity_override = Math.Max(m_quantity_override,0);
				ItemBase.Cast(new_item).SetQuantity(m_quantity_override);
			}
		}
		else
		{
			Debug.LogError("TurnItemIntoItemLambda: failed to create new item","static");
		}
	}
	
	//! if attaching from att.slot to att.slot, skips the change to "ground" version. Allows for correct property transfers.
	override void VerifyItemTypeBySlotType ()
	{
		if (m_NewLocation.GetType() == InventoryLocationType.ATTACHMENT && m_OldItem.ConfigIsExisting("ChangeIntoOnAttach"))
		{
			string str;
			int idx = -1;
			TStringArray inventory_slots = new TStringArray;
			TIntArray inventory_slots_idx = new TIntArray;
			TStringArray attach_types = new TStringArray;
			
			m_OldItem.ConfigGetTextArray("ChangeInventorySlot",inventory_slots);
			if (inventory_slots.Count() < 1) //is string
			{
				inventory_slots_idx.Insert(InventorySlots.GetSlotIdFromString(m_OldItem.ConfigGetString("ChangeInventorySlot")));
				attach_types.Insert(m_OldItem.ConfigGetString("ChangeIntoOnAttach"));
			}
			else //is array
			{
				inventory_slots_idx.Clear();
				for (int i = 0; i < inventory_slots.Count(); i++)
				{
					inventory_slots_idx.Insert(InventorySlots.GetSlotIdFromString(inventory_slots.Get(i)));
				}
				m_OldItem.ConfigGetTextArray("ChangeIntoOnAttach",attach_types);
			}
		
			idx = m_NewLocation.GetSlot();
			str = attach_types.Get(inventory_slots_idx.Find(idx));
			if (str != "")
			{
				m_NewItemType = str;
			}
		}
	}
}
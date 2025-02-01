modded class PlayerBase
{
	protected bool m_IsOnLadder;
	protected BaseBuilding_Ladder_Memory m_Ladder;
	
    bool m_IsAdminModeON;

    void SetAdminMode(bool value)
    {
        m_IsAdminModeON = value;
    }

    bool GetIsAdminModeON()
    {
        return m_IsAdminModeON;
    }


	override void OnRaiseChanged(bool state)
	{
		super.OnRaiseChanged(state);
		
		ItemBase item_in_hands = GetItemInHands();
		if (item_in_hands) {
			item_in_hands.OnRaiseChanged(state);
		}
	}
	
	bool HasMaterials(BaseBuildingItemEntry material)
	{
#ifdef DIAG_DEVELOPER
	return true;
#else
#ifdef REARMED_DEATHMATCH
	return true;
#endif
#endif
		if(m_IsAdminModeON)
		{
			return true;
		}

		array<EntityAI> entities = {};
		GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, entities);
		
		int total_quantity;
		foreach (EntityAI entity: entities) {
			ItemBase item = ItemBase.Cast(entity);
			if (item && item.IsKindOf(material.Item)) {
				total_quantity += item.GetQuantity();
			}
		}

		return material.Quantity <= total_quantity;
	}
	
	bool RemoveMaterials(BaseBuildingItemEntry material)
	{
#ifdef DIAG_DEVELOPER
	return true;
#else
#ifdef REARMED_DEATHMATCH
	return true;
#endif
#endif
		if(m_IsAdminModeON)
		{
			return true;
		}
		if (!HasMaterials(material)) {
			return false;
		}
		
		array<EntityAI> entities = {};
		GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, entities);
		
		int quantity_remaining = material.Quantity;
		foreach (EntityAI entity: entities) {
			ItemBase item = ItemBase.Cast(entity);
			if (!item || !item.IsKindOf(material.Item)) {
				continue;
			}
			
			if (quantity_remaining > item.GetQuantity()) {
				quantity_remaining -= item.GetQuantity();
				item.SetQuantity(0.0);
			} else {
				item.AddQuantity(-quantity_remaining);
				quantity_remaining = 0.0;
			}
		}
		
		return true;
	}

	void SetLadder(BaseBuilding_Ladder_Memory ladder)
	{
		if (!g_Game.IsServer()) {
			Error("SetLadder must be called on server");
			return;
		}

		m_Ladder = ladder;
		//SetSynchDirty();
	}

	BaseBuilding_Ladder_Memory GetLadder()
	{
		return m_Ladder;
	}

	void SetRAIsOnLadder(bool state)
	{
		if (!g_Game.IsServer()) {
			Error("SetRAIsOnLadder must be called on server");
			return;
		}

		m_IsOnLadder = state;
		//SetSynchDirty();
	}

	bool GetRAIsOnLadder()
	{
		return m_IsOnLadder;
	}

	override void OnCommandLadderFinish()
	{
		super.OnCommandLadderFinish();
		#ifdef SERVER
		SetRAIsOnLadder(false);
		#endif
		if (m_Ladder)
		{
			SetLadder(NULL);
		}
	}
}

#ifdef SERVER
modded class ActionEnterLadder
{
	override void Start(ActionData action_data)
	{
		BaseBuilding_Ladder_Memory m_Ladder = BaseBuilding_Ladder_Memory.Cast(action_data.m_Target.GetObject());
		PlayerBase player = PlayerBase.Cast(action_data.m_Player);
		if (player) {
			player.SetRAIsOnLadder(true); // just incase m_ladder is null we want to avoid server crash
		}
		if (m_Ladder && player)
		{
			m_Ladder.SetPlayer(player);
			player.SetLadder(m_Ladder);
		}

		super.Start(action_data);
	}
}
#endif
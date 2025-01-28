modded class PermissionManager
{
	void PermissionManager()
	{
		GetRPCManager().AddRPC("RPC_PermitManager", "PermitRABaseBuilding", this, SingeplayerExecutionType.Server);
	}

	void PermitRABaseBuilding(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
	{
		if( type == CallType.Server )
        {
			Param1<bool> data;

        	if (!ctx.Read(data))
        		return;

			bool state = data.param1;

			PlayerBase pb = GetPermissionManager().GetPlayerBaseByID(sender.GetPlainId());

			pb.SetAdminMode(state);
		}
	}
}

modded class PlayerBase
{
    bool m_IsAdminModeON;

    void SetAdminMode(bool value)
    {
        m_IsAdminModeON = value;
    }

    bool GetIsAdminModeON()
    {
        return m_IsAdminModeON;
    }

	override bool HasMaterials(BaseBuildingItemEntry material)
	{
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
	
	override bool RemoveMaterials(BaseBuildingItemEntry material)
	{
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
}

modded class ActionPlaceHologram
{

    override void OnStartServer(ActionData action_data)
	{
		if (action_data.m_Player.GetIsAdminModeON())
        {
			PlaceHologramActionData place_hologram_data = PlaceHologramActionData.Cast(action_data);
			BaseBuilding building_base = CreateObject(place_hologram_data);
			if (!building_base) {
				return;
			}
			
			building_base.SetPosition(place_hologram_data.Position);
			building_base.SetOrientation(place_hologram_data.Orientation);
			building_base.Update();


			UpgradeBaseLambda(building_base, building_base.GetUpgradeType(), action_data.m_Player).Execute();
            return;
        }

		super.OnStartServer(action_data);
	}



    override bool ActionConditionContinue(ActionData action_data)
	{
		if (!super.ActionConditionContinue(action_data)) {
			return false;
		}
		
		#ifndef SERVER
		BaseBuildingHologram hologram = GetHologram(action_data.m_MainItem);
		BaseBuilding preview_item = hologram.GetPreviewItem();
		if (!hologram || !preview_item) {
			return false;
		}

		if (action_data.m_Player.GetIsAdminModeON())
        {
			return true;
        }
		
		// Only putting CanPlaceCurrently in condition continue, that way text shows up properly
		if (!hologram.CanPlaceCurrently()) {
			return false;
		}

		BaseBuildingItemEntry upgrade = preview_item.GetUpgradeCost();		
		if (!upgrade) {
			return false;
		}
		
		switch (BaseBuilding.CheckBuildCondition(action_data.m_Player, preview_item, upgrade)) {
			case ConstructFailType.TERRITORY: 				
			case ConstructFailType.NOBUILDZONE: 				
			case ConstructFailType.MATERIALS: 
			case ConstructFailType.HEIGHT: 
				return false;
		}
		#endif
		
		return true;
	}

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!super.ActionCondition(player, target, item)) {
			return false;
		}
		
		#ifndef SERVER		
		BaseBuildingHologram hologram = GetHologram(item);
		if (!hologram) {
			return false;
		}
		
		BaseBuilding preview_item = hologram.GetPreviewItem();
		if (!preview_item) {
			return false;
		}
					
		BaseBuildingItemEntry upgrade = preview_item.GetUpgradeCost();		

        #ifdef AVPPAdminTools
		if (player.GetIsAdminModeON())
        {
        	string display_name_Admin = g_Game.ConfigGetTextOut(string.Format("CfgVehicles %1 displayName", preview_item.GetUpgradeType()));
			m_Text = string.Format("[ADMIN] Place %1", display_name_Admin);
			return true;
        }
		#endif


		switch (BaseBuilding.CheckBuildCondition(player, preview_item, upgrade)) {
			case ConstructFailType.TERRITORY: {
				m_Text = "Cannot Build (Enemy Territory)";
				break;
			}
			
			case ConstructFailType.NOBUILDZONE: {
				m_Text = "Cannot Build (No Build Zone)";
				break;
			}
			
			case ConstructFailType.MATERIALS: {
				m_Text = "Cannot Build (Insufficient Materials)";
				break;
			}
			
			case ConstructFailType.HEIGHT: {
				m_Text = "Cannot Build (Height Limit)";
				break;
			}
			
			default: {
				string display_name = g_Game.ConfigGetTextOut(string.Format("CfgVehicles %1 displayName", preview_item.GetUpgradeType()));
				m_Text = string.Format("Place %1", display_name);
				break;
			}
		}
		#endif
		
		return true;
	}

    void CompleteBuildPart(BaseBuilding building_base, ActionData action_data)
    {
        building_base.OnPlacementComplete(action_data.m_Player, building_base.GetPosition(), building_base.GetOrientation());
		
		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(action_data.m_Player);
		rpc.Write(building_base.GetPosition());
		rpc.Write(building_base.GetOrientation());
		rpc.Send(building_base, BaseBuilding.RPC_PLACING_COMPLETE, true);
    }
}

modded class ActionUpgradeBase
{
	override bool SetupAction(PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = null)
	{
		if (!super.SetupAction(player, target, item, action_data, extra_data)) {
			return false;
		}

		BaseBuilding base_building = BaseBuilding.Cast(action_data.m_Target.GetObject());
		if (!base_building) {
			return false;
		}
		
		BaseBuildingItemEntry upgrade = base_building.GetUpgradeCost();
		if (!upgrade) {
			return false;
		}

		if (player.GetIsAdminModeON())
        {
            return true;
        }
		
		RA_CodeLock code_lock = RA_CodeLock.Cast(base_building.FindAttachmentBySlotName("CodeLock"));
		if (code_lock && code_lock.IsLocked() && !code_lock.IsAuthorized(action_data.m_Player.GetIdentity())) {
			return false;
		}
		
		switch (BaseBuilding.CheckBuildCondition(action_data.m_Player, base_building, upgrade)) {
			case ConstructFailType.TERRITORY: 			
			case ConstructFailType.NOBUILDZONE: 
			case ConstructFailType.MATERIALS:
			case ConstructFailType.HEIGHT:
			case ConstructFailType.LOCKED: {
				return false;
			}
		}
		
		return true;
	}

	#ifndef SERVER
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		BaseBuilding base_building = BaseBuilding.Cast(target.GetObject());
		if (!base_building) {
			return false;
		}

        #ifdef AVPPAdminTools
		if (player.GetIsAdminModeON())
        {
			MaterialLevel upgrade_material_level_Admin = g_Game.ConfigGetInt(string.Format("CfgVehicles %1 materialLevel", base_building.GetUpgradeType()));
			if (!upgrade_material_level_Admin || upgrade_material_level_Admin == 0) {
				return false;
			}
			m_Text = string.Format("[ADMIN] Upgrade %1", upgrade_material_level_Admin.GetFormattedName());
            return true;
        }
		#endif

		BaseBuildingItemEntry upgrade = base_building.GetUpgradeCost();
		switch (BaseBuilding.CheckBuildCondition(player, base_building, upgrade)) {
			case ConstructFailType.TERRITORY: {
				m_Text = "#STR_RA_CANNOTUPGRADE_ENEMYTERRITORIES";
				break;
			}
			
			case ConstructFailType.NOBUILDZONE: {
				m_Text = "#STR_RA_CANNOTUPGRADE_NOBUILDZONE";
				break;
			}
			
			case ConstructFailType.MATERIALS: {
				m_Text = "#STR_RA_CANNOTUPGRADE_NOMATERIALS";
				break;
			}
		
			case ConstructFailType.HEIGHT: {
				m_Text = "#STR_RA_CANNOTUPGRADE_HEIGHTLIMIT";
				break;
			}

			case ConstructFailType.LOCKED: {
				m_Text = "#STR_RA_CANNOTUPGRADE_LOCKED";
				break;
			}
			
			default: {
				MaterialLevel upgrade_material_level = g_Game.ConfigGetInt(string.Format("CfgVehicles %1 materialLevel", base_building.GetUpgradeType()));
				if (!upgrade_material_level || upgrade_material_level == 0) {
					return false;
				}
				m_Text = string.Format("#STR_RA_UPGRADETO %1", upgrade_material_level.GetFormattedName());
				break;
			}
		}
		
		return true;
	}
	#endif
	
	override void OnFinishProgressServer(ActionData action_data)
	{
		BaseBuilding base_building = BaseBuilding.Cast(action_data.m_Target.GetObject());
		if (!base_building) {
			return;
		}
		
		BaseBuildingItemEntry upgrade = base_building.GetUpgradeCost();
		if (!upgrade) {
			return;
		}

		PlayerBase player = PlayerBase.Cast(action_data.m_Player);
		if (!player) {
			return;
		}

		if (action_data.m_Player.GetIsAdminModeON())
        {
            UpgradeBaseLambda(base_building, base_building.GetUpgradeType(), player).Execute();
            return;
        }

		if (BaseBuilding.CheckBuildCondition(player, base_building, upgrade) != ConstructFailType.NONE) {
			return;
		}
		
		if (player.RemoveMaterials(upgrade)) {
			UpgradeBaseLambda(base_building, base_building.GetUpgradeType(), player).Execute();
		}
	}

	override bool ActionConditionContinue(ActionData action_data)
	{
		BaseBuilding base_building = BaseBuilding.Cast(action_data.m_Target.GetObject());
		if (!base_building) {
			return false;
		}
		
		BaseBuildingItemEntry upgrade = base_building.GetUpgradeCost();
		if (!upgrade) {
			return false;
		}

        if (action_data.m_Player.GetIsAdminModeON())
        {
            return true;
        }

		RA_CodeLock code_lock = RA_CodeLock.Cast(base_building.FindAttachmentBySlotName("CodeLock"));
		if (code_lock && code_lock.IsLocked() && !code_lock.IsAuthorized(action_data.m_Player.GetIdentity())) {
			return false;
		}
		
		switch (BaseBuilding.CheckBuildCondition(action_data.m_Player, base_building, upgrade)) {
			case ConstructFailType.TERRITORY: 			
			case ConstructFailType.NOBUILDZONE: 
			case ConstructFailType.MATERIALS:
			case ConstructFailType.HEIGHT:
			case ConstructFailType.LOCKED: {
				return false;
			}
		}
		
		return true;
	}
}
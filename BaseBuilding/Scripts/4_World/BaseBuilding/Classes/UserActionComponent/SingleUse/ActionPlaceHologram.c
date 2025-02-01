class PlaceHologramActionData: ActionData
{
	string Type;
	vector Position;
	vector Orientation;
	PlacementMode Mode;
}

class PlaceBlueprintActionReciveData: ActionReciveData
{
	string Type;
	vector Position;
	vector Orientation;
	PlacementMode Mode;
}

class ActionPlaceHologram: ActionInstantBase
{	
	void ActionPlaceHologram()
	{
		m_Text = "Place Construction";
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
	}
	
	override void CreateConditionComponents() 
	{
		m_ConditionItem 	= new CCINonRuined;
		m_ConditionTarget 	= new CCTNone;
	}
	
	override ActionData CreateActionData()
	{
		return new PlaceHologramActionData();
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
	
	override bool SetupAction(PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = null)
	{
		if (!super.SetupAction(player, target, item, action_data, extra_data)) {
			return false;
		}

		#ifndef SERVER
		PlaceHologramActionData place_blueprint_data = PlaceHologramActionData.Cast(action_data);
		BaseBuildingHologram hologram = GetHologram(item);
		if (!hologram || !place_blueprint_data || !hologram.CanPlaceCurrently()) {
			return false;
		}
				
		place_blueprint_data.Type = hologram.GetBuildType();
		place_blueprint_data.Position = hologram.GetBuildPosition();
		place_blueprint_data.Orientation = hologram.GetBuildOrientation();
		place_blueprint_data.Mode = hologram.GetCurrentPlacingMode();
		#endif
		
		return true;
	}
	
	#ifdef LBmaster_GroupDLCPlotpole
		override bool Can(PlayerBase player, ActionTarget target, ItemBase item, int condition_mask) {
			if (!super.Can(player, target, item, condition_mask))
				return false;
			return LBTerritoryConfig.Get.CanExecuteAction(player, target, 1, item);
		}
	#endif

	override bool HasTarget()
	{
		return false;
	}
		
	override void WriteToContext(ParamsWriteContext ctx, ActionData action_data)
	{
		super.WriteToContext(ctx, action_data);
		
		PlaceHologramActionData place_blueprint_data = PlaceHologramActionData.Cast(action_data);
		ctx.Write(place_blueprint_data.Type);
		ctx.Write(place_blueprint_data.Position);
		ctx.Write(place_blueprint_data.Orientation);
		ctx.Write(place_blueprint_data.Mode);
	}
	
	override bool ReadFromContext(ParamsReadContext ctx, out ActionReciveData action_recive_data)
	{		
		if (!action_recive_data) {
			action_recive_data = new PlaceBlueprintActionReciveData();
		}
		
		super.ReadFromContext(ctx, action_recive_data);
		
		PlaceBlueprintActionReciveData blueprint_action_recieve_data = PlaceBlueprintActionReciveData.Cast(action_recive_data);
		if (!ctx.Read(blueprint_action_recieve_data.Type)) {
			return false;
		}
		
		if (!ctx.Read(blueprint_action_recieve_data.Position)) {
			return false;
		}
				
		if (!ctx.Read(blueprint_action_recieve_data.Orientation)) {
			return false;
		}
		
		if (!ctx.Read(blueprint_action_recieve_data.Mode)) {
			return false;
		}		
				
		return true;
	}
	
	override void HandleReciveData(ActionReciveData action_recive_data, ActionData action_data)
	{
		super.HandleReciveData(action_recive_data, action_data);
		Print("Inside reciveData : 113");
		// poorly engineered system but hey, its old
		PlaceBlueprintActionReciveData blueprint_action_recieve_data = PlaceBlueprintActionReciveData.Cast(action_recive_data);
		PlaceHologramActionData place_blueprint_data = PlaceHologramActionData.Cast(action_data);
		place_blueprint_data.Type = blueprint_action_recieve_data.Type;
		place_blueprint_data.Position = blueprint_action_recieve_data.Position;
		place_blueprint_data.Orientation = blueprint_action_recieve_data.Orientation;
		place_blueprint_data.Mode = blueprint_action_recieve_data.Mode;
	}
	
	override bool ActionConditionContinue(ActionData action_data)
	{
		Print("Inside ActionContinue : 140");
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
		Print("Inside ActionCondition : 173");
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
				Print("Inside ActionCondition : 198");
				string display_name = g_Game.ConfigGetTextOut(string.Format("CfgVehicles %1 displayName", preview_item.GetUpgradeType()));
				m_Text = string.Format("Place %1", display_name);
				break;
			}
		}
		#endif
		
		return true;
	}

	override void OnStartServer(ActionData action_data)
	{



		super.OnStartServer(action_data);
		
		PlaceHologramActionData place_hologram_data = PlaceHologramActionData.Cast(action_data);
		
		BaseBuilding building_base = CreateObject(place_hologram_data);
		if (!building_base) {
			return;
		}


		building_base.SetPosition(place_hologram_data.Position);
		building_base.SetOrientation(place_hologram_data.Orientation);
		building_base.Update();

		if (action_data.m_Player.GetIsAdminModeON())
        {
			UpgradeBaseLambda(building_base, building_base.GetUpgradeType(), action_data.m_Player).Execute();
            return;
        }


		//server side check to stop weird shenanigans
		if (!TerritoryHQ.HasPermissionsAtPosition(action_data.m_Player, building_base.GetPosition()) && !building_base.CanPlaceInEnemyTerritory()) {
			g_Game.ObjectDelete(building_base);
			return;
		}

		if (!NoBuildZone.HasPermissionsAtPosition(action_data.m_Player.GetPosition())) {
			g_Game.ObjectDelete(building_base);
			return;
		}
		
		vector mat[4];
		Math3D.YawPitchRollMatrix(place_hologram_data.Orientation, mat);
		mat[3] = place_hologram_data.Position;
						
		//@ Final check to evaluate placement condition, requires the item to be created
		//		this could be static and moved to ActionConditionContinue, if we want
		if (!building_base.EvaluatePlacementCondition(place_hologram_data.Mode, mat)) {
			g_Game.ObjectDelete(building_base);
			return;
		}

#ifdef DIAG_DEVELOPER
#else
#ifndef REARMED_DEATHMATCH
		// One last check for material consumption
		if (!action_data.m_Player.RemoveMaterials(BaseBuilding.GetConstructCost(building_base.GetType()))) {
			g_Game.ObjectDelete(building_base);
			return;
		}
#endif
#endif
		
		building_base.OnPlacementComplete(action_data.m_Player, building_base.GetPosition(), building_base.GetOrientation());
		// Stability disabled
		//set<BaseBuilding> stabilities_updated = new set<BaseBuilding>();
		//building_base.UpdateStability(-1, stabilities_updated);
		//PrintFormat("Updated %1 stabilities", stabilities_updated.Count());
		
		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(action_data.m_Player);
		rpc.Write(building_base.GetPosition());
		rpc.Write(building_base.GetOrientation());
		rpc.Send(building_base, BaseBuilding.RPC_PLACING_COMPLETE, true);
	}
	
	BaseBuilding CreateObject(PlaceHologramActionData place_hologram_data)
	{
		return null;
	}
	
	// Overwrite
	BaseBuildingHologram GetHologram(ItemBase item)
	{
		return null;
	}
}
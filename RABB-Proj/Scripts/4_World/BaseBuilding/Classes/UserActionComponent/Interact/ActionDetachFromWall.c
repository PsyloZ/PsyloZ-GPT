class ActionDetachFromBase: ActionInteractBase
{
	void ActionDetachFromBase()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_HUDCursorIcon = CursorIcons.OpenDoors;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTCursor;
	}

	override string GetText()
	{
		return "Take Camo Net";
	}
	
    #ifndef SERVER
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		BaseBuilding base = BaseBuilding.Cast(target.GetObject());		
		if (!base ) {
			return false;
		}

		if (!TerritoryHQ.HasPermissionsAtPosition(player, base.GetPosition())) {
			return false;
		}
		
		return base.FindAttachmentBySlotName("CamoNet") != NULL; //change if add more attachments to base
	}
    #endif
	
	override void OnExecuteClient(ActionData action_data)
	{
		BaseBuilding base = BaseBuilding.Cast(action_data.m_Target.GetObject());

		if (!base) {
			return;
		}

		ItemBase item = ItemBase.Cast(base.FindAttachmentBySlotName("CamoNet"));

		if (!item) {
			return;
		}

		ActionManagerClient am = ActionManagerClient.Cast(action_data.m_Player.GetActionManager());
		am.UnlockInventory(action_data);

		action_data.m_Player.PredictiveTakeEntityToHands(item);
	}
}
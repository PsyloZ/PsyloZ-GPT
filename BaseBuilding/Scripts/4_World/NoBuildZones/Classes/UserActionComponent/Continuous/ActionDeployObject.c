modded class ActionDeployObject
{
	override bool SetupAction(PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL)
	{
		if (!NoBuildZone.HasPermissionsAtPosition(item.GetPosition()) && !item.CanPlaceInEnemyTerritory()) {
			return false;
		}
		
		return super.SetupAction(player, target, item, action_data, extra_data);
	}
	
	override bool ActionConditionContinue(ActionData action_data)
	{
		if (!NoBuildZone.HasPermissionsAtPosition(action_data.m_Player.GetLocalProjectionPosition()) && !action_data.m_MainItem.CanPlaceInEnemyTerritory()) {
			return false;
		}
		
		return super.ActionConditionContinue(action_data);
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{		
		if (g_Game.IsDedicatedServer()) {			
			return super.ActionCondition(player, target, item);
		}
		
		if (!super.ActionCondition(player, target, item)) {
			return false;
		}
		
		// if no permission, change text
		Hologram hologram = player.GetHologramLocal();
		if (hologram && ItemBase.Cast(hologram.GetProjectionEntity())) {
			item = ItemBase.Cast(hologram.GetProjectionEntity());
		}
	
		if (item && !NoBuildZone.HasPermissionsAtPosition(player.GetLocalProjectionPosition()) && !item.CanPlaceInEnemyTerritory()) {
			m_Text = ActionTogglePlaceObject.NBZ_DENIED_TEXT;
		}	
		else {
			m_Text = "#place_object";
		}
		
		return true;
	}
}
modded class ActionAttach
{
	override bool SetupAction(PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL)
	{
		if (!TerritoryHQ.HasPermissionsAtPosition(player, item.GetPosition()) && !item.CanPlaceInEnemyTerritory()) {
			return false;
		}

		if (!NoBuildZone.HasPermissionsAtPosition(item.GetPosition()) && !item.CanPlaceInEnemyTerritory()) {
			return false;
		}
		
		return super.SetupAction(player, target, item, action_data, extra_data);
	}
	
	override bool ActionConditionContinue(ActionData action_data)
	{
		if (!TerritoryHQ.HasPermissionsAtPosition(action_data.m_Player, action_data.m_MainItem.GetPosition()) && !action_data.m_MainItem.CanPlaceInEnemyTerritory()) {
			return false;
		}

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
	
		if (!TerritoryHQ.HasPermissionsAtPosition(player, player.GetPosition())) {
			m_Text = ActionTogglePlaceObject.HQ_DENIED_TEXT;
		}	
		else if (!NoBuildZone.HasPermissionsAtPosition(player.GetPosition())) {
			m_Text = ActionTogglePlaceObject.NBZ_DENIED_TEXT;
		} else {
			m_Text = "#attach";
		}
		
		return true;
	}
	
	override bool IsIconDisabled()
	{
		return (GetText().Contains(ActionTogglePlaceObject.HQ_DENIED_TEXT)) || (GetText().Contains(ActionTogglePlaceObject.NBZ_DENIED_TEXT));
	}
}

modded class ActionAttachWithSwitch
{		
	override bool SetupAction(PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL)
	{
		if (!TerritoryHQ.HasPermissionsAtPosition(player, item.GetPosition()) && !item.CanPlaceInEnemyTerritory()) {
			return false;
		}

		if (!NoBuildZone.HasPermissionsAtPosition(item.GetPosition()) && !item.CanPlaceInEnemyTerritory()) {
			return false;
		}
		
		return super.SetupAction(player, target, item, action_data, extra_data);
	}
	
	override bool ActionConditionContinue(ActionData action_data)
	{
		if (!TerritoryHQ.HasPermissionsAtPosition(action_data.m_Player, action_data.m_MainItem.GetPosition()) && !action_data.m_MainItem.CanPlaceInEnemyTerritory()) {
			return false;
		}

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
	
		if (!TerritoryHQ.HasPermissionsAtPosition(player, player.GetPosition())) {
			m_Text = ActionTogglePlaceObject.HQ_DENIED_TEXT;
		}	
		else if (!NoBuildZone.HasPermissionsAtPosition(player.GetPosition())) {
			m_Text = ActionTogglePlaceObject.NBZ_DENIED_TEXT;
		} else {
			m_Text = "#attach";
		}
		
		return true;
	}
	
	override bool IsIconDisabled()
	{
		return (GetText().Contains(ActionTogglePlaceObject.HQ_DENIED_TEXT)) || (GetText().Contains(ActionTogglePlaceObject.NBZ_DENIED_TEXT));
	}
}
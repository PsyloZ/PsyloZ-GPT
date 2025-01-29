modded class ActionTogglePlaceObject
{
	static const string HQ_DENIED_TEXT = "Can't Build (Enemy Territory)";
	static const string NBZ_DENIED_TEXT = "Can't Build (No Build Zone)";
	static const string HQ_DENIED_HQ_TEXT = "Cannot place in HQ Range";
	
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		// if no permission, change text
		if (g_Game.IsDedicatedServer()) {
			return super.ActionCondition(player, target, item);
		}
		
		if (!super.ActionCondition(player, target, item)) {
			return false;
		}
		
		Hologram hologram = player.GetHologramLocal();
		if (hologram && ItemBase.Cast(hologram.GetProjectionEntity())) {
			item = ItemBase.Cast(hologram.GetProjectionEntity());
		}
	
		if (item && !TerritoryHQ.HasPermissionsAtPosition(player, item.GetPosition()) && !item.CanPlaceInEnemyTerritory()) {
			m_Text = HQ_DENIED_TEXT;
		}	
		else if (item && !NoBuildZone.HasPermissionsAtPosition(item.GetPosition()) && !item.CanPlaceInEnemyTerritory()) {
			m_Text = NBZ_DENIED_TEXT;
		} else {
			m_Text = "#toggle_placing";
		}
		
		return true;
	}
	
	override bool IsIconDisabled()
	{
		return (GetText().Contains(HQ_DENIED_TEXT)) || (GetText().Contains(NBZ_DENIED_TEXT));
	}
}
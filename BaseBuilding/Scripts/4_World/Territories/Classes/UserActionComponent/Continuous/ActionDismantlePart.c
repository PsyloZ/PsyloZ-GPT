// handle retiming of dismantling
modded class ActionDismantlePartCB
{	
	override float SetCallbackDuration(ItemBase item)
	{
		vector position = m_ActionData.m_Player.GetPosition();
		if (m_ActionData.m_Target.GetObject()) {
			position = m_ActionData.m_Target.GetObject().GetPosition();
		}
		
		if (!TerritoryHQ.HasPermissionsAtPosition(m_ActionData.m_Player, position)) {
			return RearmedConstants.BASE_DISMANTLE_NO_PERMISSION;
		}
		
		return RearmedConstants.BASE_DISMANTLE_PERMISSION;
	}
}
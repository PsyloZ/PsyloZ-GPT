modded class Hologram
{
	override void UpdateHologram(float timeslice)
	{		
		ItemBase item_projection = ItemBase.Cast(m_Projection);
		if (m_Player && m_Projection) {
			
			bool b = (!TerritoryHQ.HasPermissionsAtPosition(m_Player, m_Projection.GetPosition()) && ((item_projection && !item_projection.CanPlaceInEnemyTerritory()) || !item_projection));
			
			m_Projection.SetInvisible(b);
		}
		
		super.UpdateHologram(timeslice);
	}
}
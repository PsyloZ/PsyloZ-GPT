modded class Hologram
{
	override void UpdateHologram(float timeslice)
	{		
		ItemBase item_projection = ItemBase.Cast(m_Projection);
		if (m_Player && m_Projection) {
			
			bool b = (!NoBuildZone.HasPermissionsAtPosition(m_Projection.GetPosition()) && ((item_projection && !item_projection.CanPlaceInEnemyTerritory()) || !item_projection));
			
			vector project_pos = m_Projection.GetPosition();
			float y_level = project_pos[1] - g_Game.SurfaceY(project_pos[0], project_pos[2]);
			b = b && y_level < 30;
			
			m_Projection.SetInvisible(b);
		}
		
		super.UpdateHologram(timeslice);
	}
}
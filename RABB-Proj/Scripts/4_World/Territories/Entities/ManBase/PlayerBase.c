modded class PlayerBase
{
	// kick player out of all hq / locked buildings you are inside of
	override void OnPlayerLoaded()
    {		
        super.OnPlayerLoaded();
	
		if (!g_Game.IsServer() || !GetIdentity()) {
			return;
		}
	
		PositionWithRadius2D territory_check = LoadedEnemyTerritoryCheck();
		if (territory_check != PositionWithRadius2D.INVALID) {
			SetPosition(territory_check.GetRandomPointOnEdge(true));
			Update();
			return;
		}
    }
	
	protected PositionWithRadius2D LoadedEnemyTerritoryCheck()
	{
		array<TerritoryHQ> overlapped_hqs = {};
		if (TerritoryHQ.HasPermissionsAtPositionEx(this, GetPosition(), overlapped_hqs)) {
			return PositionWithRadius2D.INVALID;
		}
		
		array<ref PositionWithRadius2D> overlapped_positions = {};
		foreach (TerritoryHQ hq: overlapped_hqs) {
			overlapped_positions.Insert(hq.GetZoneInfo());
		}
		
		return PositionWithRadius2D.CalculateMean(overlapped_positions);
	}
}
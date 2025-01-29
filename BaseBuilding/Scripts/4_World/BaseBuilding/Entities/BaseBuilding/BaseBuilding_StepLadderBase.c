class BaseBuilding_StepLadderBase: BaseBuilding
{
	override float GetCostToUpkeep()
	{
		return 0.001;
	}

	override float GetSmallRotationStep()
	{
		return 10.0;
	}
	
	override float GetLargeRotationStep()
	{
		return 90.0;
	}
	
	override bool PlacementConformsToSurface()
	{
		return true;
	}

	override bool CanPlaceInEnemyTerritory()
	{
		return true;
	}
	
	override bool CanPermanentlyDismantle()
	{
		return true;
	}
}
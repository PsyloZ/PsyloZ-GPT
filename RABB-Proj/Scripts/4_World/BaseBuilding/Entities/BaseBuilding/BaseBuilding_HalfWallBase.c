class BaseBuilding_HalfWallBase: BaseBuilding_WallBase
{	
	override float GetSmallRotationStep()
	{
		return 0.0;
	}
	
	override float GetLargeRotationStep()
	{
		return 180.0;
	}
}
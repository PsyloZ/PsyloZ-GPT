class BaseBuilding_WallBase: BaseBuilding
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
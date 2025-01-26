class BaseBuilding_FloorBase: BaseBuilding
{
	override float GetSmallRotationStep()
	{
		return 0.0;
	}
	
	override float GetLargeRotationStep()
	{
		return 90.0;
	}
}
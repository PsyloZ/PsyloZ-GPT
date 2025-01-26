class BaseBuilding_TriangleFloorBase: BaseBuilding
{
	override float GetSmallRotationStep()
	{
		return 10.0;
	}
	
	override float GetLargeRotationStep()
	{
		return 120.0;
	}
}
class BaseBuilding_StairsBase: BaseBuilding
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

class BaseBuilding_StairsStraightBase: BaseBuilding_StairsBase
{
}
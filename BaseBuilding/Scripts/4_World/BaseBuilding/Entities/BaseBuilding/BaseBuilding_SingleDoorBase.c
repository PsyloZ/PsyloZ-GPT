class BaseBuilding_SingleDoorBase: BaseBuilding_OpenableBase
{
	override float GetSmallRotationStep()
	{
		return 0.0;
	}
	
	override float GetLargeRotationStep()
	{
		return 180.0;
	}
	
	override bool IsOccupancyExclusive()
	{
		return true;
	}
	
	override bool CanPermanentlyDismantle()
	{
		return true;
	}
}
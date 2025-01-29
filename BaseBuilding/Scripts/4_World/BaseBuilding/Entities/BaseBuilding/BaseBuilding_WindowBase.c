class BaseBuilding_WindowBase: BaseBuilding
{
	override float GetSmallRotationStep()
	{
		return 0.0;
	}
	
	override float GetLargeRotationStep()
	{
		return 180.0;
	}
	
	override bool CanPermanentlyDismantle()
	{
		return true;
	}
}
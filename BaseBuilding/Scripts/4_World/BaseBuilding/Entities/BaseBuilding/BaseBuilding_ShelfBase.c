class BaseBuilding_ShelfBase: BaseBuilding
{
	override float GetSmallRotationStep()
	{
		return 10.0;
	}
	
	override float GetLargeRotationStep()
	{
		return 90.0;
	}
	
	override bool CanPutIntoHands(EntityAI parent)
	{
		return true;
	}
	
	override bool DisableVicinityIcon()
	{
		return true;
	}
}
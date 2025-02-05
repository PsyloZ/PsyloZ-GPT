class BaseBuilding_DoubleDoorBase: BaseBuilding_OpenableBase
{
	override bool DisableVicinityIcon()
	{
		return false;
	}

	override bool IsInventoryVisible()
	{
		return true;
	}

	override int GetHideIconMask()
	{
		return EInventoryIconVisibility.ALWAYS;
	}

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
}
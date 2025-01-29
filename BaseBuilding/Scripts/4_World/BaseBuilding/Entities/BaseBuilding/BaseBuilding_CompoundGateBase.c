class BaseBuilding_CompoundGateBase: BaseBuilding_OpenableBase
{
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
	
	override vector GetFreePlacementOffset()
	{
		return Vector(0, 0.2, 0);
	}

	override bool CanPermanentlyDismantle()
	{
		return true;
	}
}
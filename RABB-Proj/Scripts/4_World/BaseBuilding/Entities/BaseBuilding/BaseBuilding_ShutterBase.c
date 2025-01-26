class BaseBuilding_ShutterBase: BaseBuilding_OpenableBase
{
	override float GetSmallRotationStep()
	{
		return 0.0;
	}
	
	override float GetLargeRotationStep()
	{
		return 180.0;
	}
		
	override string GetOpenAnimation()
	{
		return "shutters";
	}
}
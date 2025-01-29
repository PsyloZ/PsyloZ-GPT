class BaseBuilding_MetalShutters: BaseBuilding_ShutterBase
{
	override array<string> GetOpenSounds()
	{
		return {"doorMetalGateOpen_1", "doorMetalGateOpen_2"};
	}
	
	override array<string> GetCloseSounds()
	{
		return {"doorMetalGateClose_1", "doorMetalGateClose_2"};
	}
}
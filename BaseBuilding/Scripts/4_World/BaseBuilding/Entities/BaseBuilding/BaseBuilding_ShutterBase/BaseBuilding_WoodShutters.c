class BaseBuilding_WoodShutters: BaseBuilding_ShutterBase
{
	override array<string> GetOpenSounds()
	{
		return {"doorWoodGateOpen_1", "doorWoodGateOpen_2"};
	}
	
	override array<string> GetCloseSounds()
	{
		return {"doorWoodGateClose_1", "doorWoodGateClose_2"};
	}
}
class BaseBuilding_FrameCompoundGate: BaseBuilding_CompoundGateBase
{
	override array<string> GetCloseSounds()
	{
		return {"doorWoodChurchLargeClose_1", "doorWoodChurchLargeClose_2", "doorWoodChurchLargeClose_3", "doorWoodChurchLargeClose_4"};
	}
	
	override array<string> GetOpenSounds()
	{
		return {"doorWoodChurchLargeOpen_1", "doorWoodChurchLargeOpen_2", "doorWoodChurchLargeOpen_3", "doorWoodChurchLargeOpen_4"};
	}
}
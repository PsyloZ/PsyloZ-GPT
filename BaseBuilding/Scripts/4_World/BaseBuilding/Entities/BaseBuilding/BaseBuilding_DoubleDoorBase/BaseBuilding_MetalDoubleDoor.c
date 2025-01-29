class BaseBuilding_MetalDoubleDoor: BaseBuilding_DoubleDoorBase
{
	override array<string> GetOpenSounds()
	{
		return {"doorMetalSmallOpen_1"};
	}
	
	override array<string> GetCloseSounds()
	{
		return {"doorMetalSmallClose_1"};
	}
}
class BaseBuilding_MetalSingleDoor: BaseBuilding_SingleDoorBase
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
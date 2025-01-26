class BaseBuilding_VaultDoubleDoor: BaseBuilding_DoubleDoorBase
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
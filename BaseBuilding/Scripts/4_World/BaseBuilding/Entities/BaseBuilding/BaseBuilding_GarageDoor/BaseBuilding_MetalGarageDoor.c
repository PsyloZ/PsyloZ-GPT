class BaseBuilding_MetalGarageDoor: BaseBuilding_GarageDoorBase
{
	override array<string> GetCloseSounds()
	{
		return {"MetalGarageDoorSound_Close"};
	}
	
	override array<string> GetOpenSounds()
	{
		return {"MetalGarageDoorSound_Open"};
	}
}
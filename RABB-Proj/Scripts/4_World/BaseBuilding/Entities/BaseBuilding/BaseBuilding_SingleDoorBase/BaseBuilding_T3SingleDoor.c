class BaseBuilding_VaultSingleDoor: BaseBuilding_SingleDoorBase
{
	override array<string> GetOpenSounds()
	{//placeholder until i can find cooler sounds -aj
		return {"doorMetalSmallOpen_1"};
	}
	
	override array<string> GetCloseSounds()
	{//placeholder until i can find cooler sounds -aj
		return {"doorMetalSmallClose_1"};
	}
}
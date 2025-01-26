class BaseBuilding_WoodSingleDoor: BaseBuilding_SingleDoorBase
{
	override array<string> GetOpenSounds()
	{
		return {"doorWoodSmallOpen_1","doorWoodSmallOpen_2","doorWoodSmallOpen_3","doorWoodSmallOpen_4"};
	}
	
	override array<string> GetCloseSounds()
	{
		return {"doorWoodSmallClose_1","doorWoodSmallClose_2","doorWoodSmallClose_3","doorWoodSmallClose_4","doorWoodSmallClose_5","doorWoodSmallClose_6","doorWoodSmallClose_7"};
	}
}
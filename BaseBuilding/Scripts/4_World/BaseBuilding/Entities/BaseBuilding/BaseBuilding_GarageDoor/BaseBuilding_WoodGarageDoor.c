class BaseBuilding_WoodGarageDoor: BaseBuilding_GarageDoorBase
{
	override array<string> GetCloseSounds()
	{
		return {"doorWoodSlideClose_1", "doorWoodSlideClose_2", "doorWoodSlideClose_3", "doorWoodSlideClose_4"};
	}
	
	override array<string> GetOpenSounds()
	{
		return {"doorWoodSlideOpen_1", "doorWoodSlideOpen_2", "doorWoodSlideOpen_3", "doorWoodSlideOpen_4"};
	}
}
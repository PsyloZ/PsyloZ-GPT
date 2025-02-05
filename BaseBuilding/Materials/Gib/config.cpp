class CfgPatches
{
	class BaseBuilding_Gib_Objects
	{
		requiredAddons[]=
		{
			"Rearmed_BaseBuilding"
		};
		units[]={};
		weapons[]={};
	};
};
class CfgVehicles
{
	class HouseNoDestruct;
	class Gib_WoodLog_1: HouseNoDestruct
	{
		scope=1;
		model="RearmedServer\BaseBuilding\Materials\Gib\WoodLog_1.p3d";
	};
	class Gib_WoodPlank_1: HouseNoDestruct
	{
		scope=1;
		model="RearmedServer\BaseBuilding\Materials\Gib\WoodPlank_1.p3d";
	};
};

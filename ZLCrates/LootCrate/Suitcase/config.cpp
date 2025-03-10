class CfgPatches
{
	class RA_Suitcase
	{
		units[]=
		{
			"RA_Static_Suitcase_Blue",
			"RA_Static_Suitcase_Red",
			"RA_Static_Vintage_Suitcase",
			"RA_Static_Vintage_Tourist_Suitcase"
		};
		weapons[]={};
		requiredVersion=1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgVehicles
{
	class Container_Base;
	class RA_Static_Suitcase_Base: Container_Base
	{
		scope=0;
		displayName="Suitcase";
		carveNavmesh=1;
		model="ZLCrates\LootCrate\Suitcase\Suitcase.p3d";
		hiddenSelections[]=
		{
			"camo"
		};
	};
	class RA_Static_Suitcase_Blue: RA_Static_Suitcase_Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"ZLCrates\LootCrate\Suitcase\data\Suitcase_blue_co.paa"
		};
	};
	class RA_Static_Suitcase_Red: RA_Static_Suitcase_Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"ZLCrates\LootCrate\Suitcase\data\Suitcase_red_co.paa"
		};
	};
	class RA_Static_Vintage_Suitcase_Base: Container_Base
	{
		scope=0;
		displayName="Vintage Suitcase";
		carveNavmesh=1;
		model="ZLCrates\LootCrate\Suitcase\Vintage_Suitcase.p3d";
		hiddenSelections[]=
		{
			"camo"
		};
	};
	class RA_Static_Vintage_Suitcase: RA_Static_Suitcase_Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"ZLCrates\LootCrate\Suitcase\data\vintage_suitcase_co.paa"
		};
	};
	class RA_Static_Vintage_Tourist_Suitcase: RA_Static_Suitcase_Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"ZLCrates\LootCrate\Suitcase\data\vintage_suitcase_tourist_co.paa"
		};
	};
};

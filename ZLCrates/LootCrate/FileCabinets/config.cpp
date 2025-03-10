class CfgPatches
{
	class RA_Buildings_FileCabinet
	{
		units[]=
		{
			"RA_Static_FileCabinet_Grey",
			"RA_Static_FileCabinet_Red",
			"RA_Static_FileCabinet_White",
			"RA_Static_FileCabinet_Yellow",
			"RA_Static_FileCabinet_Green"
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
	class ZLandContainerBase;
	class RA_Static_FileCabinet_Base: ZLandContainerBase
	{
		scope=0;
		displayName="File Cabinet";
		model="ZLCrates\LootCrate\FileCabinets\FileCabinet.p3d";
		hiddenSelections[]=
		{
			"camo"
		};
		physLayer="item_large";
		simulation="inventoryItem";
		class Cargo
		{
			itemsCargoSize[]={8,8};
			openable=1;
			allowOwnedCargoManipulation=1;
		};
		class AnimationSources
		{
			class lid
			{
				source="user";
				initPhase=0;
				animPeriod=4;
			};
		};
	};
	class RA_Static_FileCabinet_Grey: RA_Static_FileCabinet_Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\ZLCrates\LootCrate\FileCabinets\data\FileCabinetOldGrey_co.paa"
		};
	};
	class RA_Static_FileCabinet_Red: RA_Static_FileCabinet_Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\ZLCrates\LootCrate\FileCabinets\data\FileCabinetRed_co.paa"
		};
	};
	class RA_Static_FileCabinet_White: RA_Static_FileCabinet_Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\ZLCrates\LootCrate\FileCabinets\data\FileCabinetWhite_co.paa"
		};
	};
	class RA_Static_FileCabinet_Yellow: RA_Static_FileCabinet_Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\ZLCrates\LootCrate\FileCabinets\data\FileCabinetYellow_co.paa"
		};
	};
	class RA_Static_FileCabinet_Green: RA_Static_FileCabinet_Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\ZLCrates\LootCrate\FileCabinets\data\FileCabinetGreen_co.paa"
		};
	};
};

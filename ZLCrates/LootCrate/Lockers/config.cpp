class CfgPatches
{
	class RA_Buildings_Lockers
	{
		units[]=
		{
			"RA_Static_Locker_Grey",
			"RA_Static_Locker_Red",
			"RA_Static_Locker_White",
			"RA_Static_Locker_Yellow",
			"RA_Static_Locker_Green"
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
	class RA_Static_Locker_Base: ZLandContainerBase
	{
		scope=0;
		displayName="Locker";
		model="ZLCrates\LootCrate\Lockers\Locker.p3d";
		hiddenSelections[]=
		{
			"camo"
		};
		physLayer="item_large";
		simulation="inventoryItem";
		class Cargo
		{
			itemsCargoSize[]={10,10};
			openable=1;
			allowOwnedCargoManipulation=1;
		};
		class AnimationSources
		{
			class lid
			{
				source="user";
				initPhase=0;
				animPeriod=0.5;
			};
		};
	};
	class RA_Static_Locker_Grey: RA_Static_Locker_Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\ZLCrates\LootCrate\Lockers\data\LockerGrey_co.paa"
		};
	};
	class RA_Static_Locker_Red: RA_Static_Locker_Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\ZLCrates\LootCrate\Lockers\data\LockerRed_co.paa"
		};
	};
	class RA_Static_Locker_White: RA_Static_Locker_Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\ZLCrates\LootCrate\Lockers\data\LockerWhite_co.paa"
		};
	};
	class RA_Static_Locker_Yellow: RA_Static_Locker_Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\ZLCrates\LootCrate\Lockers\data\LockerYellow_co.paa"
		};
	};
	class RA_Static_Locker_Green: RA_Static_Locker_Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\ZLCrates\LootCrate\Lockers\data\LockerGreenOld_co.paa"
		};
	};
};

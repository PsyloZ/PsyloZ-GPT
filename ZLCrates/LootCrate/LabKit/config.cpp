class CfgPatches
{
	class RA_LabKit
	{
		requiredAddons[]=
		{
			"DZ_Data"
		};
		units[]=
		{
			"RA_LabKit"
		};
		weapons[]={};
	};
};
class CfgVehicles
{
	class HouseNoDestruct;
	class RA_LabKit: HouseNoDestruct
	{
		scope=2;
		displayName="Large Crate";
		model="ZLCrates\LootCrate\LabKit\LabKit.p3d";
		physLayer="item_large";
		class Doors
		{
			class DoorsTwin1
			{
				displayName="Twin Doors 1";
				component="doorsTwin1";
				soundPos="doorsTwin1_action";
				animPeriod=1.25;
				initPhase=0;
				initOpened=0;
				soundOpen="caseOpen";
				soundClose="caseOpen";
			};
			class Door3
			{
				displayName="Door 3";
				component="door3";
				soundPos="door3_action";
				animPeriod=1;
				initPhase=0.5;
				initOpened=1;
			};
			class Door4
			{
				displayName="Door 3";
				component="door3";
				soundPos="door3_action";
				animPeriod=0.75;
				initPhase=0.5;
				initOpened=1;
			};
			class Door5
			{
				displayName="Door 3";
				component="door3";
				soundPos="door3_action";
				animPeriod=0.75;
				initPhase=0.5;
				initOpened=1;
			};
			class Cargo
			{
				itemsCargoSize[]={8,8};
				openable=1;
				allowOwnedCargoManipulation=1;
			};
		};
	};
};
class CfgSounds
{
	class case_sound
	{
		sound[]=
		{
			"ZLCrates\LootCrate\LabKit\sound\case.ogg",
			1,
			1,
			30
		};
	};
};
class CfgActionSounds
{
	class caseOpen
	{
		sounds[]=
		{
			"case_sound"
		};
	};
};

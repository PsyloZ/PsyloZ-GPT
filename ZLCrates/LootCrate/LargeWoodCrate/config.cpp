class CfgPatches
{
	class RearmedServer_Gear_LargeWoodCrate
	{
		units[]=
		{
			"RA_Static_LargeWoodCrate"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgVehicles
{
	class ZLandContainerBase;
	class RA_Static_LargeWoodCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Large Wood Crate";
		model="ZLCrates\LootCrate\LargeWoodCrate\LargeWoodCrate.p3d";
		physLayer="item_large";
		class AnimationSources
		{
			class lid
			{
				source="user";
				initPhase=0;
				animPeriod=0.25;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,15};
			openable=1;
			allowOwnedCargoManipulation=1;
		};
	};
};

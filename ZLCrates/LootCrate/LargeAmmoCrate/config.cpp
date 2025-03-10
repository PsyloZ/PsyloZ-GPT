class CfgPatches
{
	class RearmedServer_Gear_LargeAmmoCrate
	{
		units[]=
		{
			"RA_Static_LargeAmmoCrate"
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
	class RA_Static_LargeAmmoCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Wood Crate";
		model="ZLCrates\LootCrate\LargeAmmoCrate\LargeAmmoCrate.p3d";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"ZLCrates\LootCrate\LargeAmmoCrate\data\LargeAmmoCrate_co.paa"
		};
		physLayer="item_large";
		class AnimationSources
		{
			class Lid
			{
				source="user";
				initPhase=0;
				animPeriod=1;
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

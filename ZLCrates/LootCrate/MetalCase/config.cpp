class CfgPatches
{
	class RA_Gear_MetalCase
	{
		units[]=
		{
			"RA_Static_MetalCase"
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
	class RA_Static_MetalCase: ZLandContainerBase
	{
		scope=2;
		displayName="Metal Case";
		model="ZLCrates\LootCrate\MetalCase\MetalCase.p3d";
		physLayer="item_large";
		class AnimationSources
		{
			class lid
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,7};
			openable=1;
			allowOwnedCargoManipulation=1;
		};
	};
};

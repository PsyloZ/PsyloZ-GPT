class CfgPatches
{
	class RearmedServer_Gear_MetalBoxStash
	{
		units[]=
		{
			"RA_Static_MetalBoxStash"
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
	class RA_Static_MetalBoxStash: ZLandContainerBase
	{
		scope=2;
		displayName="Metal Box";
		model="ZLCrates\LootCrate\MetalBoxStash\MetalBoxStash.p3d";
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
			itemsCargoSize[]={10,15};
			openable=1;
			allowOwnedCargoManipulation=1;
		};
	};
};

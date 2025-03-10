class CfgPatches
{
	class RA_StaticLunchbox
	{
		units[]=
		{
			"RA_Static_Lunchbox"
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
	class RA_Static_Lunchbox: ZLandContainerBase
	{
		scope=2;
		displayName="Lunchbox";
		model="ZLCrates\LootCrate\Lunchbox\lunchbox.p3d";
		physLayer="item_large";
		class AnimationSources
		{
			class lid
			{
				source="user";
				component="lid";
				initPhase=0;
				animPeriod=0.75;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={8,8};
			openable=1;
			allowOwnedCargoManipulation=1;
		};
	};
};

class CfgPatches
{
	class RA_StaticBriefcase
	{
		units[]=
		{
			"RA_Static_Briefcase"
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
	class RA_Static_Briefcase: ZLandContainerBase
	{
		scope=2;
		displayName="Briefcase";
		model="ZLCrates\LootCrate\Briefcase\Briefcase.p3d";
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

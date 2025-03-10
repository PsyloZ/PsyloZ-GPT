class CfgPatches
{
	class RearmedServer_Gear_MedicalBox
	{
		units[]=
		{
			"RA_Static_MedicalBox"
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
	class RA_Static_MedicalBox: ZLandContainerBase
	{
		scope=2;
		displayName="Medical Box";
		model="ZLCrates\LootCrate\MedicalBox\MedicalBox.p3d";
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
			itemsCargoSize[]={8,8};
			openable=1;
			allowOwnedCargoManipulation=1;
		};
	};
};

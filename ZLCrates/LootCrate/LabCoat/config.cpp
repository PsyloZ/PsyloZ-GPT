class CfgPatches
{
	class RA_Gear_LabCoat
	{
		units[]=
		{
			"RA_Static_LabCoat"
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
	class RA_Static_LabCoat: ZLandContainerBase
	{
		scope=2;
		displayName="Lab Coat";
		model="ZLCrates\LootCrate\LabCoat\LabCoat.p3d";
		physLayer="item_large";
		class Cargo
		{
			itemsCargoSize[]={2,5};
			openable=1;
			allowOwnedCargoManipulation=1;
		};
	};
};

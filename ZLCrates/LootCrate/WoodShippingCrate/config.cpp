class CfgPatches
{
	class RA_StaticContainers_Wood_Shipping_Crate
	{
		units[]=
		{
			"RA_Static_Wood_Shipping_Crate"
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
	class RA_Static_Wood_Shipping_Crate: ZLandContainerBase
	{
		scope=2;
		displayName="Shipping Container";
		model="ZLCrates\LootCrate\WoodShippingCrate\WoodShippingCrate.p3d";
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
			itemsCargoSize[]={10,10};
			openable=1;
			allowOwnedCargoManipulation=1;
		};
	};
};

class CfgPatches
{
	class RA_Buildings_cash_register
	{
		units[]=
		{
			"RA_Static_Cash_Register"
		};
		weapons[]={};
		requiredVersion=1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgVehicles
{
	class ZLandContainerBase;
	class RA_Static_Cash_Register_Base: ZLandContainerBase
	{
		scope=0;
		displayName="Cash Register";
		model="ZLCrates\LootCrate\CashRegister\cash_register.p3d";
		hiddenSelections[]=
		{
			"camo",
			"cash"
		};
		physLayer="item_large";
		simulation="inventoryItem";
		class Cargo
		{
			itemsCargoSize[]={2,3};
			openable=1;
			allowOwnedCargoManipulation=1;
		};
		class AnimationSources
		{
			class lid
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
	};
	class RA_Static_Cash_Register: RA_Static_Cash_Register_Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"ZLCrates\LootCrate\CashRegister\data\cash_register_co.paa",
			"ZLCrates\LootCrate\CashRegister\data\cash_co.paa"
		};
	};
};

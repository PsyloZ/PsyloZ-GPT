class CfgPatches
{
	class RearmedServer_Gear_Consumables_Gunpowder
	{
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
		units[]=
		{
			"RA_Gunpowder"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class RA_Gunpowder: Inventory_Base
	{
		scope=2;
		displayName="Gunpowder";
		descriptionShort="Used to craft explosives. You need a workbench upgrade in order to craft them.";
		model="RearmedServer\BaseBuilding\Tools\Explosives\GunPowder\GunPowder_Conatainer_Small.p3d";
		itemBehaviour=1;
		weight=500;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		itemSize[]={2,3};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Stitch
				{
					soundSet="";
					id=201;
				};
				class pickup
				{
					soundSet="sewingkit_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="sewingkit_drop_SoundSet";
					id=898;
				};
			};
		};
	};
};

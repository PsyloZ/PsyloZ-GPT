class CfgPatches
{
	class Rearmed_BaseBuilding_InventoryOverrides
	{
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Consumables",
			"DZ_Gear_Camping"
		};
		units[]={};
		weapons[]={};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class WoodenLog: Inventory_Base
	{
		itemSize[]={3,7};
		varStackMax=10;
	};
	class WoodenPlank: Inventory_Base
	{
		varStackMax=25;
	};
	class MetalPlate: Inventory_Base
	{
		itemSize[]={5,5};
		varStackMax=25;
	};
	class Nail: Inventory_Base
	{
		varQuantityMax=1000;
		varStackMax=99;
		inventorySlot[]+=
		{
			"HQ_Nails"
		};
	};
	class CamoNet: Inventory_Base
	{
		itemSize[]={5,2};
	};
};

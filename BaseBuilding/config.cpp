class CfgPatches
{
	class Rearmed_BaseBuilding
	{
		requiredAddons[]=
		{
			"DZ_Data"
		};
		units[]={};
		weapons[]={};
	};
	class RA_BaseBuilding_Scripts
	{
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Scripts"
		};
		units[]={};
		weapons[]={};
	};
};
class CfgMods
{
	class RA_BaseBuilding_Scripts
	{
		name="Rearmed";
		dir="RearmedServer";
		credits="Designful, InclementDab, Specops, Gormirn, AJ45";
		author="Designful";
		type="mod";
		defines[]=
		{
			"RA_BASEBUILDING"
		};
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class imageSets
			{
				files[]=
				{
					"RA_BaseBuilding/GUI/imagesets/BaseBuilding_Icons.imageset"
				};
			};
			class gameScriptModule
			{
				files[]=
				{
					"RearmedServer/BaseBuilding/Scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				files[]=
				{
					"RearmedServer/BaseBuilding/Scripts/4_World"
				};
			};
			class missionScriptModule
			{
				files[]=
				{
					"RearmedServer/BaseBuilding/Scripts/5_Mission"
				};
			};
		};
	};
};
class CfgSlots
{
	class Slot_CodeLock
	{
		name="CodeLock";
		displayName="Code Lock";
		ghostIcon="set:icons image:lock";
		ghostIconSize=0.80000001;
	};
	class Slot_HQ_Nails
	{
		name="HQ_Nails";
		displayName="#STR_CfgNails0";
		ghostIcon="set:dayz_inventory image:nails";
		stackMax=1500;
	};
	class Slot_StorageContainer
	{
		name="StorageContainer";
		displayName="Storage";
		ghostIcon="set:dayz_inventory image:cat_common_cargo";
	};
};


class PreloadVehicles
{
	class BaseBuilding_FrameWall
	{
		loadStyle=2;
	};
	class BaseBuilding_WoodWall
	{
		loadStyle=2;
	};
	class BaseBuilding_FrameFoundation
	{
		loadStyle=2;
	};
	class BaseBuilding_WoodFoundation
	{
		loadStyle=2;
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class BaseBuilding: Inventory_Base
	{
		scope=0;
		physLayer="item_large";
		forceFarBubble="true";
		carveNavmesh=1;
		overrideDrawArea="3.0";
		inherit_rotation=1;
		heavyItem=1;
		materialLevel="= 0";
		placementMode="= 0";
		displayIcon="";
		upgradeType="";
		destroyOnEmpty=1;
		hideQuantityMax=1;
		class UpgradeSystem
		{
			class Hologram
			{
			};
			class Frame
			{
				class Construct
				{
					item="WoodenLog";
					quantity=1;
				};
				class Repair
				{
					item="WoodenLog";
					quantity=1;
				};
			};
			class Wood
			{
				class Construct
				{
					item="WoodenPlank";
					quantity=8;
				};
				class Repair
				{
					item="WoodenPlank";
					quantity=8;
				};
			};
			class Metal
			{
				class Construct
				{
					item="MetalPlate";
					quantity=8;
				};
				class Repair
				{
					item="MetalPlate";
					quantity=8;
				};
			};
			class Concrete
			{
				class Construct
				{
					item="RA_Cinderblock";
					quantity=8;
				};
				class Repair
				{
					item="RA_Cinderblock";
					quantity=8;
				};
			};
		};
	};
};

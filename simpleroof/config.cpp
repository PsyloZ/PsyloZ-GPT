class CfgMods
{
	class SimpleRoof
	{
		dir="simpleroof";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="SimpleRoof";
		credits="";
		author="Chopper";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"World",
			"Mission"
		};
		class defs
		{
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"simpleroof/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"simpleroof/scripts/5_Mission"
				};
			};
		};
	};
};
class CfgPatches
{
	class SimpleRoof
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Camping",
			"DZ_Gear_Consumables"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Chopper_BaseKit: Inventory_Base
	{
		scope=0;
		isMeleeWeapon=0;
		weight=10000;
		absorbency=0;
		rotationFlags=16;
		itemSize[]={5,5};
		lootCategory="Materials";
		reversed=0;
		itemBehaviour=2;
	};
	class Chopper_Step_Ladder_2Kit: Chopper_BaseKit
	{
		scope=2;
		displayName="Raid Ladder Kit";
		descriptionShort="Raid Ladder.";
		model="\simpleroof\models\dbo_ladder.p3d";
		isMeleeWeapon=0;
		weight=30000;
		absorbency=0;
		rotationFlags=0;
		itemSize[]={2,5};
		lootCategory="Materials";
		reversed=0;
		itemBehaviour=2;
	};
	class Chopper_Step_Ladder_2: Inventory_Base
	{
		scope=2;
		displayName="Raid Ladder";
		descriptionShort="Raid Ladder.";
		model="\simpleroof\models\dbo_ladder.p3d";
		handheld="true";
		weight=5000;
		heavyItem=1;
		itemSize[]={2,5};
		itemsCargoSize[]={0,0};
		canBeDigged=0;
		isMeleeWeapon=0;
		quantityBar=1;
		carveNavmesh=1;
		overrideDrawArea="8.0";
		physLayer="item_large";
		destroyOnEmpty=0;
		varQuantityDestroyOnMin=0;
		allowOwnedCargoManipulation=1;
		itemBehaviour=0;
		randomQuantity=2;
		minPlacingDist=10;
		rotationFlags=0;
		hiddenSelectionsTextures[]=
		{
			"\simpleroof\models\dbo_ladder.paa"
		};
		lootTag[]=
		{
			"Work"
		};
	};
};

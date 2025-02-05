class CfgPatches
{
	class RearmedServer_BaseBuilding_Storage
	{
		units[]=
		{
			"RA_RuinedStorageContainer"
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
	class Container_Base;
	class RA_BoxKit_Base: Container_Base
	{
		scope=0;
		model="\RearmedServer\BaseBuilding\Storage\KitBox\KitBox.p3d";
		itemSize[]={6,4};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		itemBehaviour=0;
		physLayer="item_large";
		rotationFlags=2;
		weight=300;
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"RearmedServer\BaseBuilding\Storage\KitBox\data\carrierbox_co.paa"
		};
	};
	class RA_RuinedStorageContainer: Container_Base
	{
		scope=2;
		model="\RearmedServer\BaseBuilding\Storage\KitBox\KitBox.p3d";
		attachments[]=
		{
			"StorageContainer"
		};
		inventorySlot[]=
		{
			"Crate1",
			"Crate2",
			"Crate3"
		};
		itemSize[]={1,1};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		itemBehaviour=0;
		physLayer="item_large";
		rotationFlags=2;
		weight=300;
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"RearmedServer\BaseBuilding\Storage\KitBox\data\carrierbox_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=5000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								""
							}
						},
						
						{
							0.69999999,
							
							{
								""
							}
						},
						
						{
							0.5,
							
							{
								""
							}
						},
						
						{
							0.30000001,
							
							{
								""
							}
						},
						
						{
							0,
							
							{
								""
							}
						}
					};
				};
			};
		};
	};
	class HouseNoDestruct;
	class TerritoryHQ_Kit_ExpansionMarketPreview: HouseNoDestruct
	{
		displayName="Territory HQ Kit";
		descriptionShort="Prevents your base from despawning.";
		model="RearmedServer\BaseBuilding\Territory\TerritoryHQ.p3d";
	};
};

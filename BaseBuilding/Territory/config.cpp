class CfgPatches
{
	class RearmedServer_Gear_Territory
	{
		units[]=
		{
			"TerritoryHQ",
			"TerritoryHQ_Hologram",
			"TerritoryHQ_Kit"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"RearmedServer_BaseBuilding_Storage"
		};
	};
};
class CfgVehicles
{
	class Container_Base;
	class TerritoryHQ: Container_Base
	{
		scope=2;
		displayName="$STR_RA_TERRITORYHQ";
		descriptionShort="$STR_DES_RA_TERRITORYHQ";
		model="RearmedServer\BaseBuilding\Territory\TerritoryHQ.p3d";
		inventorySlot[]=
		{
			"StorageContainer"
		};
		itemSize[]={5,5};
		weight=100;
		canBeDigged=0;
		alignHologramToTerain=1;
		itemBehaviour=2;
		carveNavmesh=1;
		physLayer="item_large";
		simulation="inventoryItem";
		attachments[]=
		{
			"CodeLock",
			"HQ_Nails",
			"TerritoryHQ_L1_Upgrade",
			"TerritoryHQ_L2_Upgrade",
			"TerritoryHQ_L3_Upgrade",
			"TerritoryHQ_L4_Upgrade"
		};
		class GUIInventoryAttachmentsProps
		{
			class Base
			{
				name="";
				description="";
				attachmentSlots[]=
				{
					"CodeLock"
				};
				icon="cat_bb_base";
			};
			class Upkeep_1
			{
				name="Upkeep";
				description="Base will decay without Nails";
				attachmentSlots[]=
				{
					"HQ_Nails"
				};
				icon="nails";
			};
			class Upgrades
			{
				name="Upgrades";
				description="Base will decay without Nails";
				attachmentSlots[]=
				{
					"TerritoryHQ_L1_Upgrade",
					"TerritoryHQ_L2_Upgrade",
					"TerritoryHQ_L3_Upgrade",
					"TerritoryHQ_L4_Upgrade"
				};
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=500;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"RearmedServer\BaseBuilding\Territory\data\Computer.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"RearmedServer\BaseBuilding\Territory\data\Computer.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Territory\data\Computer_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Territory\data\Computer_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Territory\data\Computer_destruct.rvmat"
							}
						}
					};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage=0.029999999;
					};
				};
				class Melee
				{
					class Health
					{
						damage=0.30000001;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0.1;
					};
				};
			};
		};
		class AnimationSources
		{
			class Placing
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class hidestart
			{
				source="start";
				animPeriod=1;
				initPhase=0;
			};
			class hidewb
			{
				source="wb";
				animPeriod=1;
				initPhase=1;
			};
		};
	};
	class Inventory_Base;
	class TerritoryHQ_Hologram: Inventory_Base
	{
		scope=2;
		displayName="This is a hologram";
		descriptionShort="Nothing to see here, move along";
		model="RearmedServer\BaseBuilding\Territory\TerritoryHQ.p3d";
		class AnimationSources
		{
			class hidewb
			{
				source="wb";
				animPeriod=1;
				initPhase=1;
			};
		};
	};
	class RA_BoxKit_Base;
	class TerritoryHQ_Kit: RA_BoxKit_Base
	{
		scope=2;
		displayName="$STR_RA_TERRITORYHQKIT";
		descriptionShort="$STR_DES_RA_TERRITORYHQKIT";
	};
};

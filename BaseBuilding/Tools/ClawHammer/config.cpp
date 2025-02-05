class CfgPatches
{
	class RearmedServer_BaseBuilding_ClawHammer
	{
		units[]=
		{
			"RA_ClawHammer_Blue",
			"RA_ClawHammer_Red",
			"RA_ClawHammer_Yellow"
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
	class Inventory_Base;
	class RA_ClawHammer: Inventory_Base
	{
		scope=0;
		displayName="$STR_RA_CLAWHAMMER";
		descriptionShort="$STR_DES_RA_CLAWHAMMER";
		model="\RearmedServer\BaseBuilding\Tools\ClawHammer\ClawHammer.p3d";
		inventorySlot[]+=
		{
			"SmallTool1",
			"SmallTool2",
			"SmallTool3",
			"SmallTool4",
			"SmallTool5",
			"SmallTool6",
			"SmallTool7",
			"SmallTool8",
			"SmallTool9",
			"SmallTool10",
			"SmallTool11",
			"SmallTool12"
		};
		build_action_type=10;
		dismantle_action_type=0;
		rotationFlags=17;
		weight=940;
		itemSize[]={1,3};
		fragility=0.0080000004;
		openItemSpillRange[]={20,50};
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"RearmedServer\BaseBuilding\Tools\ClawHammer\data\Hammer_Blue_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=150;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"RearmedServer\BaseBuilding\Tools\ClawHammer\data\Hammer.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"RearmedServer\BaseBuilding\Tools\ClawHammer\data\Hammer.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Tools\ClawHammer\data\Hammer_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Tools\ClawHammer\data\Hammer_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Tools\ClawHammer\data\Hammer_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeHammer";
				range=1.1;
			};
			class Heavy
			{
				ammo="MeleeHammer_Heavy";
				range=1.1;
			};
			class Sprint
			{
				ammo="MeleeHammer_Heavy";
				range=3.3;
			};
		};
		soundImpactType="metal";
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup
				{
					soundSet="hatchet_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="woodaxe_drop_SoundSet";
					id=898;
				};
				class WoodHammer_SoundSet
				{
					soundSet="WoodHammer_SoundSet";
					id=11161;
				};
			};
		};
	};
	class RA_ClawHammer_Blue: RA_ClawHammer
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"RearmedServer\BaseBuilding\Tools\ClawHammer\data\Hammer_Blue_co.paa"
		};
	};
	class RA_ClawHammer_Red: RA_ClawHammer
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"RearmedServer\BaseBuilding\Tools\ClawHammer\data\Hammer_Red_co.paa"
		};
	};
	class RA_ClawHammer_Yellow: RA_ClawHammer
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"RearmedServer\BaseBuilding\Tools\ClawHammer\data\Hammer_Yellow_co.paa"
		};
	};
};

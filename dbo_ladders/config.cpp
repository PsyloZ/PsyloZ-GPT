class CfgPatches
{
	class dbo_ladders
	{
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgMods
{
	class dbo_ladders
	{
		type="mod";
		class defs
		{
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"dbo/structures/dbo_ladders/scripts/4_world"
				};
			};
		};
	};
};
class cfgvehicles
{
	class HouseNoDestruct;
	class land_dbo_ladder: HouseNoDestruct
	{
		author="dbo";
		mapSize=1;
		scope=2;
		displayName="Ladder";
		descriptionShort="All your Basez Are belong to uZ ";
		model="\dbo\Structures\dbo_ladders\dbo_ladder.p3d";
	};
	class land_dbo_ladder_L: HouseNoDestruct
	{
		author="dbo";
		mapSize=1;
		scope=2;
		displayName="Tall Ladder";
		descriptionShort="All your Basez Are belong to uZ  biggerZ ";
		model="\dbo\Structures\dbo_ladders\dbo_ladder_L.p3d";
	};
	class Inventory_Base;
	class dbo_ladderP: Inventory_Base
	{
		scope=2;
		displayName="Ladder Part";
		descriptionShort="A section of ladder  used to create a larger ladder  but cannot be used by itself";
		model="\dbo\Structures\dbo_ladders\dbo_ladderP.p3d";
		rotationFlags=12;
		isMeleeWeapon=1;
		weight=3200;
		itemSize[]={1,6};
		fragility=0.001;
		itemBehaviour=1;
		inventorySlot[]=
		{
			"Shoulder",
			"Melee"
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
								"DZ\gear\tools\data\metal_pipe.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\tools\data\metal_pipe.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\tools\data\metal_pipe_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\tools\data\metal_pipe_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\tools\data\metal_pipe_destruct.rvmat"
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
				ammo="MeleePipeWrench";
				range=1.7;
			};
			class Heavy
			{
				ammo="MeleePipeWrench_Heavy";
				range=1.3;
			};
			class Sprint
			{
				ammo="MeleePipeWrench_Heavy";
				range=4.0999999;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Attack_pipemetalhollow_Light1
				{
					soundSet="Char_Attack_pipemetalhollow_light1_SoundSet";
					id=811;
				};
				class Attack_pipemetalhollow_Light2
				{
					soundSet="Char_Attack_pipemetalhollow_light2_SoundSet";
					id=812;
				};
				class Attack_pipemetalhollow_Heavy1
				{
					soundSet="Char_Attack_pipemetalhollow_heavy1_SoundSet";
					id=813;
				};
				class Attack_pipemetalhollow_Heavy2
				{
					soundSet="Char_Attack_pipemetalhollow_heavy2_SoundSet";
					id=814;
				};
				class drop
				{
					soundset="crowbar_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class dbo_ladderPART: dbo_ladderP
	{
		scope=2;
		displayName="Ladder Part Pole";
		descriptionShort="A Pole section of ladder  used to create a piece of a large ladder";
		model="\dbo\Structures\dbo_ladders\dbo_ladderPART.p3d";
	};
};

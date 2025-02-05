class CfgPatches
{
	class BaseBuilding_HatchLadder
	{
		requiredAddons[]=
		{
			"Rearmed_BaseBuilding"
		};
		units[]=
		{
			"BaseBuilding_HologramHatchLadder",
			"BaseBuilding_WoodHatchLadder",
			"BaseBuilding_MetalHatchLadder",
			"BaseBuilding_VaultHatchLadder"
		};
		weapons[]={};
	};
};
class CfgVehicles
{
	class BaseBuilding;
	class HouseNoDestruct;
	class BaseBuilding_Ladder_Memory: HouseNoDestruct
	{
		scope=1;
		displayName="Ladder";
		model="RearmedServer\BaseBuilding\LadderHatchLadder\LadderHatch_Ladder_Memory.p3d";
	};
	class BaseBuilding_HatchLadderBase: BaseBuilding
	{
		displayName="Ladder Hatch";
		displayIcon="set:BaseBuilding_Icons image:Ladder";
		placementMode=2;
		class Snapping
		{
			class Hatch
			{
				acceptedTypes[]=
				{
					"BaseBuilding_LadderHatchBase"
				};
				forward[]={0,0,1};
				up[]={0,1,0};
			};
		};
		heavyItem=1;
		weight=10000;
		itemSize[]={5,10};
		hiddenSelections[]=
		{
			"wood"
		};
		rotationFlags=34;
		attachments[]=
		{
			"CodeLock"
		};
		class AnimationSources
		{
			class ladder_extend
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
		};
	};
	class BaseBuilding_HologramHatchLadder: BaseBuilding_HatchLadderBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\LadderHatchLadder\HologramLadderHatch_Ladder.p3d";
		upgradeType="BaseBuilding_WoodHatchLadder";
		hiddenSelectionsTextures[]=
		{
			"#(argb,8,8,3)color(0.756863,0.741176,0.733333,0.9,co)"
		};
		hiddenSelectionsMaterials[]=
		{
			"rearmedserver\basebuilding\materials\basebuilding_neutral.rvmat"
		};
		materialLevel=0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
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
	class BaseBuilding_WoodHatchLadder: BaseBuilding_HatchLadderBase
	{
		scope=2;
		descriptionShort="A single wooden door. If you put a code lock on it, make the password 1234.";
		model="RearmedServer\BaseBuilding\LadderHatchLadder\WoodLadderHatch_Ladder.p3d";
		upgradeType="BaseBuilding_MetalHatchLadder";
		hiddenSelectionsTextures[]=
		{
			"dz\structures\data\wood\wood_planks_brown_new_co.paa"
		};
		materialLevel=2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1250;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_destruct.rvmat"
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
						damage=0;
					};
				};
				class Melee
				{
					class Health
					{
						damage=0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0;
					};
				};
			};
		};
	};
	class BaseBuilding_MetalHatchLadder: BaseBuilding_HatchLadderBase
	{
		scope=2;
		descriptionShort="A single wooden door. If you put a code lock on it, make the password 1234.";
		model="RearmedServer\BaseBuilding\LadderHatchLadder\MetalLadderHatch_Ladder.p3d";
		hiddenSelectionsTextures[]=
		{
			"dz\structures\data\wood\wood_planks_brown_new_co.paa"
		};
		upgradeType="BaseBuilding_VaultHatchLadder";
		materialLevel=3;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=2500;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_destruct.rvmat"
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
						damage=0;
					};
				};
				class Melee
				{
					class Health
					{
						damage=0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0;
					};
				};
			};
		};
	};
	class BaseBuilding_VaultHatchLadder: BaseBuilding_HatchLadderBase
	{
		scope=2;
		descriptionShort="A single wooden door. If you put a code lock on it, make the password 1234.";
		model="RearmedServer\BaseBuilding\LadderHatchLadder\T3LadderHatch_Ladder.p3d";
		hiddenSelections[]=
		{
			"camo_base",
			"camo_door"
		};
		hiddenSelectionsTextures[]=
		{
			"RearmedServer\BaseBuilding\Materials\Metal\data\T3Hatch_base_co.paa",
			"RearmedServer\BaseBuilding\Materials\Metal\data\T3Hatch_door_co.paa"
		};
		materialLevel=3;
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
								"RearmedServer\BaseBuilding\Materials\Metal\data\T3Hatch_base.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\T3Hatch_door.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"RearmedServer\BaseBuilding\Materials\Metal\data\T3Hatch_base_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\T3Hatch_door_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Materials\Metal\data\T3Hatch_base_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\T3Hatch_door_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Materials\Metal\data\T3Hatch_base_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\T3Hatch_door_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Materials\Metal\data\T3Hatch_base_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\T3Hatch_door_destruct.rvmat"
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
						damage=0;
					};
				};
				class Melee
				{
					class Health
					{
						damage=0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0;
					};
				};
			};
		};
	};
};

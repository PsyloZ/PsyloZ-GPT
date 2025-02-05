class CfgPatches
{
	class BaseBuilding_StairsStraight
	{
		requiredAddons[]=
		{
			"Rearmed_BaseBuilding"
		};
		units[]=
		{
			"BaseBuilding_HologramStairsStraight",
			"BaseBuilding_FrameStairsStraight",
			"BaseBuilding_WoodStairsStraight",
			"BaseBuilding_MetalStairsStraight"
		};
		weapons[]={};
	};
};
class CfgVehicles
{
	class BaseBuilding_StairsBase;
	class BaseBuilding_StairsStraightBase: BaseBuilding_StairsBase
	{
		displayName="Straight Stairs";
		displayIcon="set:BaseBuilding_Icons image:Stairs";
	};
	class BaseBuilding_HologramStairsStraight: BaseBuilding_StairsStraightBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\StairsStraight\HologramStairsStraight.p3d";
		materialLevel=0;
		upgradeType="BaseBuilding_FrameStairsStraight";
		hiddenSelections[]=
		{
			"wood"
		};
		hiddenSelectionsTextures[]=
		{
			"#(argb,8,8,3)color(0.756863,0.741176,0.733333,0.9,co)"
		};
		hiddenSelectionsMaterials[]=
		{
			"rearmedserver\basebuilding\materials\basebuilding_neutral.rvmat"
		};
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
	class BaseBuilding_FrameStairsStraight: BaseBuilding_StairsStraightBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\StairsStraight\FrameStairsStraight.p3d";
		materialLevel=1;
		upgradeType="BaseBuilding_WoodStairsStraight";
		hiddenSelections[]=
		{
			"wood"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\gear\consumables\data\pile_of_planks_co.paa"
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
			class DamageZones
			{
				class Interior
				{
					class Health
					{
						hitpoints=500;
						transferToGlobalCoef=1;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage=1;
							};
						};
						class Projectile
						{
							class Health
							{
								damage=0.5;
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
					componentNames[]=
					{
						"interior"
					};
				};
			};
		};
	};
	class BaseBuilding_WoodStairsStraight: BaseBuilding_StairsStraightBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\StairsStraight\WoodStairsStraight.p3d";
		materialLevel=2;
		upgradeType="BaseBuilding_MetalStairsStraight";
		hiddenSelections[]=
		{
			"wood"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\gear\consumables\data\pile_of_planks_co.paa"
		};
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
			class DamageZones
			{
				class Exterior
				{
					class Health
					{
						hitpoints=2500;
						transferToGlobalCoef=1;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage=0.0015;
							};
						};
						class Projectile
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
					componentNames[]=
					{
						"exterior"
					};
				};
				class Interior
				{
					class Health
					{
						hitpoints=2500;
						transferToGlobalCoef=1;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage=0.5;
							};
						};
						class Projectile
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
					componentNames[]=
					{
						"interior"
					};
				};
			};
		};
	};
	class BaseBuilding_MetalStairsStraight: BaseBuilding_StairsStraightBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\StairsStraight\MetalStairsStraight.p3d";
		materialLevel=3;
		hiddenSelections[]=
		{
			"metal_plate",
			"metal_rusty"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\structures\data\metal\metal_plates3_co.paa",
			"dz\structures\data\metal\metal_grey_rusty_co.paa"
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
								"rearmedserver\basebuilding\materials\metal\data\metal_plates3.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\metal_grey_rusty.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"rearmedserver\basebuilding\materials\metal\data\metal_plates3_damage.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\metal_grey_rusty_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"rearmedserver\basebuilding\materials\metal\data\metal_plates3_damage.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\metal_grey_rusty_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"rearmedserver\basebuilding\materials\metal\data\metal_plates3_destruct.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\metal_grey_rusty_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"rearmedserver\basebuilding\materials\metal\data\metal_plates3_destruct.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\metal_grey_rusty_destruct.rvmat"
							}
						}
					};
				};
			};
			class DamageZones
			{
				class Exterior
				{
					class Health
					{
						hitpoints=5000;
						transferToGlobalCoef=1;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage=0.0015;
							};
						};
						class Projectile
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
					componentNames[]=
					{
						"exterior"
					};
				};
				class Interior
				{
					class Health
					{
						hitpoints=5000;
						transferToGlobalCoef=1;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage=0.5;
							};
						};
						class Projectile
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
					componentNames[]=
					{
						"interior"
					};
				};
			};
		};
	};
};

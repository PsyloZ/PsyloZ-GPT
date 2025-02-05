class CfgPatches
{
	class BaseBuilding_Stairs
	{
		requiredAddons[]=
		{
			"Rearmed_BaseBuilding"
		};
		units[]=
		{
			"BaseBuilding_HologramStairs",
			"BaseBuilding_FrameStairs",
			"BaseBuilding_WoodStairs",
			"BaseBuilding_MetalStairs"
		};
		weapons[]={};
	};
};
class CfgVehicles
{
	class BaseBuilding;
	class BaseBuilding_StairsBase: BaseBuilding
	{
		displayName="Stairs";
		displayIcon="set:BaseBuilding_Icons image:Stairs";
		placementMode=2;
		class Snapping
		{
			class Center
			{
				acceptedTypes[]=
				{
					"BaseBuilding_StairsBase"
				};
				forward[]={0,0,1};
				up[]={0,1,0};
			};
			class Bottom
			{
				acceptedSnapPoints[]=
				{
					"Center"
				};
				forward[]={0,0,1};
				up[]={0,1,0};
			};
		};
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
					quantity=6;
				};
				class Repair
				{
					item="WoodenPlank";
					quantity=6;
				};
			};
			class Metal
			{
				class Construct
				{
					item="MetalPlate";
					quantity=6;
				};
				class Repair
				{
					item="MetalPlate";
					quantity=6;
				};
			};
			class Concrete
			{
				class Construct
				{
					item="RA_Cinderblock";
					quantity=6;
				};
				class Repair
				{
					item="RA_Cinderblock";
					quantity=6;
				};
			};
		};
	};
	class BaseBuilding_HologramStairs: BaseBuilding_StairsBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\Stairs\HologramStairs.p3d";
		materialLevel=0;
		upgradeType="BaseBuilding_FrameStairs";
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
	class BaseBuilding_FrameStairs: BaseBuilding_StairsBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\Stairs\WoodStairsFrame.p3d";
		materialLevel=1;
		upgradeType="BaseBuilding_WoodStairs";
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
	class BaseBuilding_WoodStairs: BaseBuilding_StairsBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\Stairs\WoodStairs.p3d";
		materialLevel=2;
		upgradeType="BaseBuilding_MetalStairs";
		hiddenSelections[]=
		{
			"top",
			"wood"
		};
		hiddenSelectionsTextures[]=
		{
			"RearmedServer\BaseBuilding\Materials\Wood\data\Stair_Planks_co.paa",
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
								"RearmedServer\BaseBuilding\Materials\Wood\data\Stair_Planks.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\Stair_Planks_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\Stair_Planks_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\Stair_Planks_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\Stair_Planks_destruct.rvmat",
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
	class BaseBuilding_MetalStairs: BaseBuilding_StairsBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\Stairs\MetalStairs.p3d";
		materialLevel=3;
		hiddenSelections[]=
		{
			"wood",
			"metal_plate",
			"metal_rot",
			"metal_rusty",
			"metal_smoke"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\gear\consumables\data\pile_of_planks_co.paa",
			"dz\structures\data\metal\metal_plates3_co.paa",
			"dz\structures\data\metal\rotfurnace_metal_02_co.paa",
			"dz\structures\data\metal\metal_grey_rusty_co.paa",
			"dz\structures\industrial\smokestacks\data\smokestack_metal_floor_co.paa"
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
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\metal_plates3.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\metalfloor.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\metal_grey_rusty.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\flatmetalplate.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_damage.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\metal_plates3_damage.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\metalfloor_damage.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\metal_grey_rusty_damage.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\flatmetalplate_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_damage.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\metal_plates3_damage.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\metalfloor_damage.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\metal_grey_rusty_damage.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\flatmetalplate_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_destruct.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\metal_plates3_destruct.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\metalfloor_destruct.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\metal_grey_rusty_destruct.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\flatmetalplate_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_destruct.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\metal_plates3_destruct.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\metalfloor_destruct.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\metal_grey_rusty_destruct.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\flatmetalplate_destruct.rvmat"
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

class CfgPatches
{
	class BaseBuilding_DoubleDoorFrame
	{
		requiredAddons[]=
		{
			"Rearmed_BaseBuilding",
			"BaseBuilding_Wall"
		};
		units[]=
		{
			"BaseBuilding_HologramDoubleDoorFrame",
			"BaseBuilding_FrameDoubleDoorFrame",
			"BaseBuilding_WoodDoubleDoorFrame",
			"BaseBuilding_MetalDoubleDoorFrame",
			"BaseBuilding_ConcreteDoubleDoorFrame"
		};
		weapons[]={};
	};
};
class CfgVehicles
{
	class BaseBuilding_WallBase;
	class Snapping;
	class Top;
	class Bottom;
	class BaseBuilding_DoubleDoorFrameBase: BaseBuilding_WallBase
	{
		displayIcon="set:BaseBuilding_Icons image:DoubleDoorFrame";
		displayName="Double Door Frame";
		class Snapping: Snapping
		{
			class Top: Top
			{
			};
			class Bottom: Bottom
			{
			};
			class DoubleDoor
			{
				acceptedTypes[]=
				{
					"BaseBuilding_DoubleDoorBase",
					"BaseBuilding_GarageDoorBase"
				};
				forward[]={0,0,1};
				up[]={0,1,0};
			};
		};
		class AnimationSources
		{
			class hide
			{
				source="user";
				animPeriod=0.001;
				initPhase=1;
			};
		};
	};
	class BaseBuilding_HologramDoubleDoorFrame: BaseBuilding_DoubleDoorFrameBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\DoubleDoorFrame\HologramDoubleDoor.p3d";
		materialLevel=0;
		upgradeType="BaseBuilding_FrameDoubleDoorFrame";
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
					hitpoints=500;
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
	class BaseBuilding_FrameDoubleDoorFrame: BaseBuilding_DoubleDoorFrameBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\DoubleDoorFrame\WoodDoubleDoorFrame.p3d";
		materialLevel=1;
		upgradeType="BaseBuilding_WoodDoubleDoorFrame";
		attachments[]=
		{
			"CamoNet"
		};
		hiddenSelections[]=
		{
			"logs",
			"planks"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\gear\consumables\data\pile_of_planks_co.paa",
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
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_destruct.rvmat",
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
	class BaseBuilding_WoodDoubleDoorFrame: BaseBuilding_DoubleDoorFrameBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\DoubleDoorFrame\WoodDoubleDoorWall.p3d";
		materialLevel=2;
		upgradeType="BaseBuilding_MetalDoubleDoorFrame";
		attachments[]=
		{
			"CamoNet"
		};
		hiddenSelections[]=
		{
			"planks",
			"wood"
		};
		hiddenSelectionsTextures[]=
		{
			"RearmedServer\BaseBuilding\Materials\Wood\data\DoubleDoorWall_Planks_co.paa",
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
								"RearmedServer\BaseBuilding\Materials\Wood\data\DoubleDoorWall_Planks.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\DoubleDoorWall_Planks_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\DoubleDoorWall_Planks_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\DoubleDoorWall_Planks_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\DoubleDoorWall_Planks_destruct.rvmat",
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
	class BaseBuilding_MetalDoubleDoorFrame: BaseBuilding_DoubleDoorFrameBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\DoubleDoorFrame\MetalDoubleDoorWall.p3d";
		materialLevel=3;
		upgradeType="BaseBuilding_ConcreteDoubleDoorFrame";
		attachments[]=
		{
			"CamoNet"
		};
		hiddenSelections[]=
		{
			"wood",
			"metal",
			"metalroll",
			"metalsmokestack"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\gear\consumables\data\pile_of_planks_co.paa",
			"RearmedServer\BaseBuilding\Materials\Metal\data\Metal_DoubleDoor_co.paa",
			"dz\structures\data\metal\metal_rollup_co.paa",
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
								"RearmedServer\BaseBuilding\Materials\Metal\data\Metal_DoubleDoor.rvmat",
								"dz\structures\data\metal\metal_rollup.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\FlatMetalPlate.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\Metal_DoubleDoor_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_rollup_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\FlatMetalPlate_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\Metal_DoubleDoor_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_rollup_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\FlatMetalPlate_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\Metal_DoubleDoor_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_rollup_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\FlatMetalPlate_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\Metal_DoubleDoor_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_rollup_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\FlatMetalPlate_destruct.rvmat"
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
	class BaseBuilding_ConcreteDoubleDoorFrame: BaseBuilding_DoubleDoorFrameBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\DoubleDoorFrame\ConcreteDoubleDoorWall.p3d";
		materialLevel=4;
		attachments[]=
		{
			"CamoNet"
		};
		hiddenSelections[]=
		{
			"bricks",
			"cement"
		};
		hiddenSelectionsTextures[]=
		{
			"rearmedserver\basebuilding\materials\concrete\municipaloffice2_facade1_grey_co.paa",
			"dz\structures\data\concrete\concrete_bare_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"rearmedserver\basebuilding\materials\concrete\municipaloffice2_facade1.rvmat",
			"rearmedserver\basebuilding\materials\concrete\vanillaconcretebare.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=10000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"rearmedserver\basebuilding\materials\concrete\municipaloffice2_facade1.rvmat",
								"rearmedserver\basebuilding\materials\concrete\vanillaconcretebare.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"rearmedserver\basebuilding\materials\concrete\municipaloffice2_facade1_damage.rvmat",
								"rearmedserver\basebuilding\materials\concrete\vanillaconcretebare_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"rearmedserver\basebuilding\materials\concrete\municipaloffice2_facade1_damage.rvmat",
								"rearmedserver\basebuilding\materials\concrete\vanillaconcretebare_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"rearmedserver\basebuilding\materials\concrete\municipaloffice2_facade1_destruct.rvmat",
								"rearmedserver\basebuilding\materials\concrete\vanillaconcretebare_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"rearmedserver\basebuilding\materials\concrete\municipaloffice2_facade1_destruct.rvmat",
								"rearmedserver\basebuilding\materials\concrete\vanillaconcretebare_destruct.rvmat"
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
						hitpoints=10000;
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
						hitpoints=10000;
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

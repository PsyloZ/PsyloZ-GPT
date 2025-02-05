class CfgPatches
{
	class BaseBuilding_RoofWall
	{
		requiredAddons[]=
		{
			"Rearmed_BaseBuilding"
		};
		units[]=
		{
			"BaseBuilding_HologramRoofWall_Left",
			"BaseBuilding_HologramRoofWall_Right",
			"Basebuilding_FrameRoofWall_Left",
			"Basebuilding_FrameRoofWall_Right",
			"Basebuilding_WoodRoofWall_Left",
			"Basebuilding_WoodRoofWall_Right",
			"Basebuilding_MetalRoofWall_Left",
			"Basebuilding_MetalRoofWall_Right",
			"BaseBuilding_ConcreteRoofWall_Left",
			"BaseBuilding_ConcreteRoofWall_Right"
		};
		weapons[]={};
	};
};
class CfgVehicles
{
	class BaseBuilding_WallBase;
	class Snapping;
	class Bottom;
	class BaseBuilding_RoofWallLeftBase: BaseBuilding_WallBase
	{
		displayName="Roof Wall Left";
		displayIcon="set:BaseBuilding_Icons image:RoofWall_Left";
		class Snapping
		{
			class Bottom
			{
				allowReverse=1;
				acceptedSnapPoints[]=
				{
					"Top"
				};
				forward[]={0,0,-1};
				up[]={0,1,0};
			};
		};
	};
	class BaseBuilding_RoofWallRightBase: BaseBuilding_WallBase
	{
		displayName="Roof Wall Right";
		displayIcon="set:BaseBuilding_Icons image:RoofWall_Right";
		class Snapping
		{
			class Bottom
			{
				allowReverse=1;
				acceptedSnapPoints[]=
				{
					"Top"
				};
				forward[]={0,0,-1};
				up[]={0,1,0};
			};
		};
	};
	class BaseBuilding_HologramRoofWall_Left: BaseBuilding_RoofWallLeftBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\RoofWall\HologramRoofWall_Left.p3d";
		materialLevel=0;
		upgradeType="Basebuilding_FrameRoofWall_Left";
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
	class BaseBuilding_HologramRoofWall_Right: BaseBuilding_RoofWallRightBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\RoofWall\HologramRoofWall_Right.p3d";
		materialLevel=0;
		upgradeType="Basebuilding_FrameRoofWall_Right";
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
	class Basebuilding_FrameRoofWall_Left: BaseBuilding_RoofWallLeftBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\RoofWall\FrameRoofWall_Left.p3d";
		materialLevel=1;
		upgradeType="Basebuilding_WoodRoofWall_Left";
		attachments[]=
		{
			"CamoNet"
		};
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
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_destruct.rvmat"
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
	class Basebuilding_FrameRoofWall_Right: BaseBuilding_RoofWallRightBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\RoofWall\FrameRoofWall_Right.p3d";
		materialLevel=1;
		upgradeType="Basebuilding_WoodRoofWall_Right";
		attachments[]=
		{
			"CamoNet"
		};
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
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_destruct.rvmat"
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
	class Basebuilding_WoodRoofWall_Left: BaseBuilding_RoofWallLeftBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\RoofWall\WoodRoofWall_Left.p3d";
		materialLevel=2;
		upgradeType="Basebuilding_MetalRoofWall_Left";
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
			"rearmedserver\basebuilding\materials\wood\data\Wall_Roof_Planks_Left_co.paa",
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
								"rearmedserver\basebuilding\materials\wood\data\Wall_Roof_Planks_Left.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"rearmedserver\basebuilding\materials\wood\data\Wall_Roof_Planks_Left_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"rearmedserver\basebuilding\materials\wood\data\Wall_Roof_Planks_Left_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"rearmedserver\basebuilding\materials\wood\data\Wall_Roof_Planks_Left_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"rearmedserver\basebuilding\materials\wood\data\Wall_Roof_Planks_Left_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_destruct.rvmat"
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
	class Basebuilding_WoodRoofWall_Right: BaseBuilding_RoofWallRightBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\RoofWall\WoodRoofWall_Right.p3d";
		materialLevel=2;
		upgradeType="Basebuilding_MetalRoofWall_Right";
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
			"rearmedserver\basebuilding\materials\wood\data\Wall_Roof_Planks_Right_co.paa",
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
								"rearmedserver\basebuilding\materials\wood\data\Wall_Roof_Planks_Right.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"rearmedserver\basebuilding\materials\wood\data\Wall_Roof_Planks_Right_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"rearmedserver\basebuilding\materials\wood\data\Wall_Roof_Planks_Right_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"rearmedserver\basebuilding\materials\wood\data\Wall_Roof_Planks_Right_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"rearmedserver\basebuilding\materials\wood\data\Wall_Roof_Planks_Right_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_destruct.rvmat"
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
	class Basebuilding_MetalRoofWall_Left: BaseBuilding_RoofWallLeftBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\RoofWall\MetalRoofWall_Left.p3d";
		materialLevel=3;
		upgradeType="BaseBuilding_ConcreteRoofWall_Left";
		attachments[]=
		{
			"CamoNet"
		};
		hiddenSelections[]=
		{
			"wood",
			"metalhangar",
			"metalroll",
			"metalsheets",
			"metalsmokestack",
			"metalwavy"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\gear\consumables\data\pile_of_planks_co.paa",
			"dz\structures\data\metal\metal_servicehangar_rust_co.paa",
			"dz\structures\data\metal\metal_rollup_co.paa",
			"dz\gear\consumables\data\metalsheets_co.paa",
			"dz\structures\industrial\smokestacks\data\smokestack_metal_floor_co.paa",
			"dz\structures\industrial\cementworks\data\wavy_sheet_co.paa"
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
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_servicehangar_rust.rvmat",
								"dz\structures\data\metal\metal_rollup.rvmat",
								"dz\gear\consumables\data\metalsheets.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\FlatMetalPlate.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\WavySheet.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_servicehangar_rust_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_rollup_damage.rvmat",
								"dz\gear\consumables\data\metalsheets_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\FlatMetalPlate_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\WavySheet_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_servicehangar_rust_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_rollup_damage.rvmat",
								"dz\gear\consumables\data\metalsheets_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\FlatMetalPlate_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\WavySheet_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_servicehangar_rust_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_rollup_destruct.rvmat",
								"dz\gear\consumables\data\metalsheets_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\FlatMetalPlate_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\WavySheet_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_servicehangar_rust_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_rollup_destruct.rvmat",
								"dz\gear\consumables\data\metalsheets_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\FlatMetalPlate_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\WavySheet_destruct.rvmat"
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
	class Basebuilding_MetalRoofWall_Right: BaseBuilding_RoofWallRightBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\RoofWall\MetalRoofWall_Right.p3d";
		materialLevel=3;
		upgradeType="BaseBuilding_ConcreteRoofWall_Right";
		attachments[]=
		{
			"CamoNet"
		};
		hiddenSelections[]=
		{
			"wood",
			"metalhangar",
			"metalroll",
			"metalsheets",
			"metalsmokestack",
			"metalwavy"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\gear\consumables\data\pile_of_planks_co.paa",
			"dz\structures\data\metal\metal_servicehangar_rust_co.paa",
			"dz\structures\data\metal\metal_rollup_co.paa",
			"dz\gear\consumables\data\metalsheets_co.paa",
			"dz\structures\industrial\smokestacks\data\smokestack_metal_floor_co.paa",
			"dz\structures\industrial\cementworks\data\wavy_sheet_co.paa"
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
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_servicehangar_rust.rvmat",
								"dz\structures\data\metal\metal_rollup.rvmat",
								"dz\gear\consumables\data\metalsheets.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\FlatMetalPlate.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\WavySheet.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_servicehangar_rust_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_rollup_damage.rvmat",
								"dz\gear\consumables\data\metalsheets_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\FlatMetalPlate_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\WavySheet_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_servicehangar_rust_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_rollup_damage.rvmat",
								"dz\gear\consumables\data\metalsheets_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\FlatMetalPlate_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\WavySheet_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_servicehangar_rust_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_rollup_destruct.rvmat",
								"dz\gear\consumables\data\metalsheets_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\FlatMetalPlate_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\WavySheet_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_servicehangar_rust_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_rollup_destruct.rvmat",
								"dz\gear\consumables\data\metalsheets_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\FlatMetalPlate_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\WavySheet_destruct.rvmat"
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
	class BaseBuilding_ConcreteRoofWall_Left: BaseBuilding_RoofWallLeftBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\RoofWall\ConcreteRoofWall_Left.p3d";
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
	class BaseBuilding_ConcreteRoofWall_Right: BaseBuilding_RoofWallRightBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\RoofWall\ConcreteRoofWall_Right.p3d";
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

class CfgPatches
{
	class BaseBuilding_Roof
	{
		requiredAddons[]=
		{
			"Rearmed_BaseBuilding"
		};
		units[]=
		{
			"BaseBuilding_HologramRoof",
			"BaseBuilding_FrameRoof",
			"BaseBuilding_WoodRoof",
			"BaseBuilding_MetalRoof"
		};
		weapons[]={};
	};
};
class CfgVehicles
{
	class BaseBuilding;
	class BaseBuilding_RoofBase: BaseBuilding
	{
		displayName="Roof";
		displayIcon="set:BaseBuilding_Icons image:Roof";
		placementMode=2;
		stabilityNode=1;
		class Snapping
		{
			class Top
			{
				allowReverse=1;
				acceptedTypes[]=
				{
					"BaseBuilding_WallBase",
					"BaseBuilding_HalfWallBase",
					"BaseBuilding_FloorBase"
				};
				acceptedSnapPoints[]=
				{
					"Bottom",
					"North",
					"South",
					"East",
					"West"
				};
				forward[]={0,0,1};
				up[]={0,1,0};
			};
			class Bottom
			{
				allowReverse=1;
				acceptedTypes[]=
				{
					"BaseBuilding_WallBase",
					"BaseBuilding_HalfWallBase"
				};
				acceptedSnapPoints[]=
				{
					"Top"
				};
				forward[]={0,0,-1};
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
	class BaseBuilding_HologramRoof: BaseBuilding_RoofBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\Roof\HologramRoof.p3d";
		materialLevel=0;
		upgradeType="BaseBuilding_FrameRoof";
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
	class BaseBuilding_FrameRoof: BaseBuilding_RoofBase
	{
		scope=2;
		descriptionShort="A weird lookin frame Roof";
		model="RearmedServer\BaseBuilding\Roof\FrameRoof.p3d";
		materialLevel=1;
		upgradeType="BaseBuilding_WoodRoof";
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
	class BaseBuilding_WoodRoof: BaseBuilding_RoofBase
	{
		scope=2;
		descriptionShort="A constructed wooden Roof";
		model="RearmedServer\BaseBuilding\Roof\WoodRoof.p3d";
		materialLevel=2;
		upgradeType="BaseBuilding_MetalRoof";
		attachments[]=
		{
			"CamoNet"
		};
		hiddenSelections[]=
		{
			"wood",
			"woodboardold",
			"woodchurch"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\gear\consumables\data\pile_of_planks_co.paa",
			"dz\structures_bliss\data\wood\woodboard_old_01.paa",
			"dz\structures_bliss\data\roof\church_04_roof_01_co.paa"
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
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\woodboard_old_01.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\church_04_roof_01.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\woodboard_old_01_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\church_04_roof_01_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\woodboard_old_01_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\church_04_roof_01_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\woodboard_old_01_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\church_04_roof_01_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\woodboard_old_01_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\church_04_roof_01_destruct.rvmat"
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
	class BaseBuilding_MetalRoof: BaseBuilding_RoofBase
	{
		scope=2;
		descriptionShort="A constructed Metal Roof";
		model="RearmedServer\BaseBuilding\Roof\MetalRoof.p3d";
		materialLevel=3;
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
			"metalwavy",
			"metalrollupcombo"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\gear\consumables\data\pile_of_planks_co.paa",
			"dz\structures\data\metal\metal_servicehangar_rust_co.paa",
			"dz\structures\data\metal\metal_rollup_co.paa",
			"dz\gear\consumables\data\metalsheets_co.paa",
			"dz\structures\industrial\smokestacks\data\smokestack_metal_floor_co.paa",
			"dz\structures\industrial\cementworks\data\wavy_sheet_co.paa",
			"DZ\structures_bliss\data\Metal\rollup_combo_co.paa"
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
								"RearmedServer\BaseBuilding\Materials\Metal\data\WavySheet.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\rollup_combo.rvmat"
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
								"RearmedServer\BaseBuilding\Materials\Metal\data\WavySheet_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\rollup_combo_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_servicehangar_rust_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_rollup_damage.rvmat",
								"dz\gear\consumables\data\metalsheets_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\FlatMetalPlate_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\WavySheet_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\rollup_combo_damage.rvmat"
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
								"RearmedServer\BaseBuilding\Materials\Metal\data\WavySheet_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\rollup_combo_destruct.rvmat"
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
								"RearmedServer\BaseBuilding\Materials\Metal\data\WavySheet_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\rollup_combo_destruct.rvmat"
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

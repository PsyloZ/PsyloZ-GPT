class CfgPatches
{
	class BaseBuilding_TriangleFoundation
	{
		requiredAddons[]=
		{
			"Rearmed_BaseBuilding"
		};
		units[]=
		{
			"BaseBuilding_HologramTriangleFoundation",
			"BaseBuilding_FrameTriangleFoundation",
			"BaseBuilding_WoodTriangleFoundation",
			"BaseBuilding_MetalTriangleFoundation",
			"BaseBuilding_ConcreteTriangleFoundation"
		};
		weapons[]={};
	};
};
class CfgVehicles
{
	class BaseBuilding;
	class BaseBuilding_TriangleFoundationBase: BaseBuilding
	{
		displayName="Triangle Foundation";
		displayIcon="set:BaseBuilding_Icons image:Triangle_Foundation";
		placementMode=3;
		stabilityNode=1;
		class Snapping
		{
			class NorthEast
			{
				acceptedTypes[]=
				{
					"BaseBuilding_FoundationBase",
					"BaseBuilding_TriangleFoundationBase",
					"BaseBuilding_WallBase",
					"BaseBuilding_HalfWallBase",
					"BaseBuilding_RampBase",
					"BaseBuilding_RoofBase"
				};
				forward[]={-0.86602497,0,-0.5};
				up[]={0,1,0};
			};
			class NorthWest
			{
				acceptedTypes[]=
				{
					"BaseBuilding_FoundationBase",
					"BaseBuilding_TriangleFoundationBase",
					"BaseBuilding_WallBase",
					"BaseBuilding_HalfWallBase",
					"BaseBuilding_RampBase",
					"BaseBuilding_RoofBase"
				};
				forward[]={0.86602497,0,-0.5};
				up[]={0,1,0};
			};
			class South
			{
				acceptedTypes[]=
				{
					"BaseBuilding_FoundationBase",
					"BaseBuilding_TriangleFoundationBase",
					"BaseBuilding_WallBase",
					"BaseBuilding_HalfWallBase",
					"BaseBuilding_RampBase",
					"BaseBuilding_RoofBase"
				};
				forward[]={0,0,1};
				up[]={0,1,0};
			};
			class NorthEastLow
			{
				acceptedTypes[]=
				{
					"BaseBuilding_FoundationBase",
					"BaseBuilding_TriangleFoundationBase",
					"BaseBuilding_HalfWallBase",
					"BaseBuilding_RoofBase"
				};
				forward[]={-0.86602497,0,-0.5};
				up[]={0,1,0};
			};
			class NorthWestLow
			{
				acceptedTypes[]=
				{
					"BaseBuilding_FoundationBase",
					"BaseBuilding_TriangleFoundationBase",
					"BaseBuilding_HalfWallBase",
					"BaseBuilding_RoofBase"
				};
				forward[]={0.86602497,0,-0.5};
				up[]={0,1,0};
			};
			class SouthLow
			{
				acceptedTypes[]=
				{
					"BaseBuilding_FoundationBase",
					"BaseBuilding_TriangleFoundationBase",
					"BaseBuilding_HalfWallBase",
					"BaseBuilding_RoofBase"
				};
				forward[]={0,0,1};
				up[]={0,1,0};
			};
		};
	};
	class BaseBuilding_HologramTriangleFoundation: BaseBuilding_TriangleFoundationBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\TriangleFoundation\HologramTriangleFoundation.p3d";
		materialLevel=0;
		upgradeType="BaseBuilding_FrameTriangleFoundation";
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
	class BaseBuilding_FrameTriangleFoundation: BaseBuilding_TriangleFoundationBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\TriangleFoundation\FrameTriangleFoundation.p3d";
		materialLevel=1;
		upgradeType="BaseBuilding_WoodTriangleFoundation";
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
	class BaseBuilding_WoodTriangleFoundation: BaseBuilding_TriangleFoundationBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\TriangleFoundation\WoodTriangleFoundation.p3d";
		materialLevel=2;
		upgradeType="BaseBuilding_MetalTriangleFoundation";
		hiddenSelections[]=
		{
			"top",
			"wood"
		};
		hiddenSelectionsTextures[]=
		{
			"rearmedserver\basebuilding\materials\wood\data\triangle_foundation_planks_co.paa",
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
								"RearmedServer\BaseBuilding\Materials\Wood\data\Triangle_Foundation_Planks.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\Triangle_Foundation_Planks_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\Triangle_Foundation_Planks_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\Triangle_Foundation_Planks_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\Triangle_Foundation_Planks_destruct.rvmat",
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
	class BaseBuilding_MetalTriangleFoundation: BaseBuilding_TriangleFoundationBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\TriangleFoundation\MetalTriangleFoundation.p3d";
		materialLevel=3;
		upgradeType="BaseBuilding_ConcreteTriangleFoundation";
		hiddenSelections[]=
		{
			"wood",
			"metalhangar",
			"metalfloor"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\gear\consumables\data\pile_of_planks_co.paa",
			"dz\structures\data\metal\metal_servicehangar_rust_co.paa",
			"dz\structures\data\metal\rotfurnace_metal_02_co.paa"
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
								"rearmedserver\basebuilding\materials\metal\data\metalfloor.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_servicehangar_rust_damage.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\metalfloor_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_servicehangar_rust_damage.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\metalfloor_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_servicehangar_rust_destruct.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\metalfloor_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_servicehangar_rust_destruct.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\metalfloor_destruct.rvmat"
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
	class BaseBuilding_ConcreteTriangleFoundation: BaseBuilding_TriangleFoundationBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\TriangleFoundation\ConcreteTriangleFoundation.p3d";
		materialLevel=4;
		hiddenSelections[]=
		{
			"brick",
			"concretebare",
			"floor"
		};
		hiddenSelectionsTextures[]=
		{
			"rearmedserver\basebuilding\materials\concrete\municipaloffice2_facade1_grey_co.paa",
			"dz\structures\data\concrete\concrete_bare_co.paa",
			"dz\structures\data\concrete\concrete_panels_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"rearmedserver\basebuilding\materials\concrete\municipaloffice2_facade1.rvmat",
			"rearmedserver\basebuilding\materials\concrete\vanillaconcretebare.rvmat",
			"rearmedserver\basebuilding\materials\concrete\vanillaconcrete_panels.rvmat"
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
								"rearmedserver\basebuilding\materials\concrete\vanillaconcretebare.rvmat",
								"rearmedserver\basebuilding\materials\concrete\vanillaconcrete_panels.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"rearmedserver\basebuilding\materials\concrete\municipaloffice2_facade1_damage.rvmat",
								"rearmedserver\basebuilding\materials\concrete\vanillaconcretebare_damage.rvmat",
								"rearmedserver\basebuilding\materials\concrete\vanillaconcrete_panels_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"rearmedserver\basebuilding\materials\concrete\municipaloffice2_facade1_damage.rvmat",
								"rearmedserver\basebuilding\materials\concrete\vanillaconcretebare_damage.rvmat",
								"rearmedserver\basebuilding\materials\concrete\vanillaconcrete_panels_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"rearmedserver\basebuilding\materials\concrete\municipaloffice2_facade1_destruct.rvmat",
								"rearmedserver\basebuilding\materials\concrete\vanillaconcretebare_destruct.rvmat",
								"rearmedserver\basebuilding\materials\concrete\vanillaconcrete_panels_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"rearmedserver\basebuilding\materials\concrete\municipaloffice2_facade1_destruct.rvmat",
								"rearmedserver\basebuilding\materials\concrete\vanillaconcretebare_destruct.rvmat",
								"rearmedserver\basebuilding\materials\concrete\vanillaconcrete_panels_destruct.rvmat"
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

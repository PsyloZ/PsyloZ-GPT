class CfgPatches
{
	class BaseBuilding_Foundation
	{
		requiredAddons[]=
		{
			"Rearmed_BaseBuilding"
		};
		units[]=
		{
			"BaseBuilding_HologramFoundation",
			"BaseBuilding_FrameFoundation",
			"BaseBuilding_WoodFoundation",
			"BaseBuilding_MetalFoundation",
			"BaseBuilding_ConcreteFoundation"
		};
		weapons[]={};
	};
};
class CfgVehicles
{
	class BaseBuilding;
	class BaseBuilding_FoundationBase: BaseBuilding
	{
		displayName="Foundation";
		displayIcon="set:BaseBuilding_Icons image:Floor_Foundation";
		placementMode=3;
		stabilityNode=1;
		class Snapping
		{
			class North
			{
				acceptedTypes[]=
				{
					"BaseBuilding_FoundationBase",
					"BaseBuilding_TriangleFoundationBase",
					"BaseBuilding_WallBase",
					"BaseBuilding_HalfWallBase",
					"BaseBuilding_RampBase"
				};
				forward[]={0,0,-1};
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
					"BaseBuilding_RampBase"
				};
				forward[]={0,0,1};
				up[]={0,1,0};
			};
			class East
			{
				acceptedTypes[]=
				{
					"BaseBuilding_FoundationBase",
					"BaseBuilding_TriangleFoundationBase",
					"BaseBuilding_WallBase",
					"BaseBuilding_HalfWallBase",
					"BaseBuilding_RampBase"
				};
				forward[]={-1,0,0};
				up[]={0,1,0};
			};
			class West
			{
				acceptedTypes[]=
				{
					"BaseBuilding_FoundationBase",
					"BaseBuilding_TriangleFoundationBase",
					"BaseBuilding_WallBase",
					"BaseBuilding_HalfWallBase",
					"BaseBuilding_RampBase"
				};
				forward[]={1,0,0};
				up[]={0,1,0};
			};
			class NorthLow
			{
				acceptedTypes[]=
				{
					"BaseBuilding_FoundationBase",
					"BaseBuilding_TriangleFoundationBase",
					"BaseBuilding_HalfWallBase",
					"BaseBuilding_RampBase"
				};
				forward[]={0,0,-1};
				up[]={0,1,0};
			};
			class SouthLow
			{
				acceptedTypes[]=
				{
					"BaseBuilding_FoundationBase",
					"BaseBuilding_TriangleFoundationBase",
					"BaseBuilding_HalfWallBase",
					"BaseBuilding_RampBase"
				};
				forward[]={0,0,1};
				up[]={0,1,0};
			};
			class EastLow
			{
				acceptedTypes[]=
				{
					"BaseBuilding_FoundationBase",
					"BaseBuilding_TriangleFoundationBase",
					"BaseBuilding_HalfWallBase",
					"BaseBuilding_RampBase"
				};
				forward[]={-1,0,0};
				up[]={0,1,0};
			};
			class WestLow
			{
				acceptedTypes[]=
				{
					"BaseBuilding_FoundationBase",
					"BaseBuilding_TriangleFoundationBase",
					"BaseBuilding_HalfWallBase",
					"BaseBuilding_RampBase"
				};
				forward[]={1,0,0};
				up[]={0,1,0};
			};
			class Center
			{
				acceptedTypes[]=
				{
					"BaseBuilding_StairsBase"
				};
				acceptedSnapPoints[]=
				{
					"Bottom"
				};
				forward[]={0,0,1};
				up[]={0,1,0};
			};
		};
	};
	class BaseBuilding_HologramFoundation: BaseBuilding_FoundationBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\Foundation\HologramFoundation.p3d";
		materialLevel=0;
		upgradeType="BaseBuilding_FrameFoundation";
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
	class BaseBuilding_FrameFoundation: BaseBuilding_FoundationBase
	{
		scope=2;
		descriptionShort="A weird lookin frame foundation";
		model="RearmedServer\BaseBuilding\Foundation\FrameFoundation.p3d";
		materialLevel=1;
		upgradeType="BaseBuilding_WoodFoundation";
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
	class BaseBuilding_WoodFoundation: BaseBuilding_FoundationBase
	{
		scope=2;
		descriptionShort="A constructed wooden foundation";
		model="RearmedServer\BaseBuilding\Foundation\WoodFoundation.p3d";
		materialLevel=2;
		upgradeType="BaseBuilding_MetalFoundation";
		hiddenSelections[]=
		{
			"top",
			"wood"
		};
		hiddenSelectionsTextures[]=
		{
			"RearmedServer\BaseBuilding\Materials\Wood\data\Foundation_Planks_co.paa",
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
								"RearmedServer\BaseBuilding\Materials\Wood\data\Foundation_Planks.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\Foundation_Planks_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\Foundation_Planks_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\Foundation_Planks_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\Foundation_Planks_destruct.rvmat",
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
	class BaseBuilding_MetalFoundation: BaseBuilding_FoundationBase
	{
		scope=2;
		descriptionShort="A constructed metal foundation";
		model="RearmedServer\BaseBuilding\Foundation\MetalFoundation.p3d";
		materialLevel=3;
		upgradeType="BaseBuilding_ConcreteFoundation";
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
	class BaseBuilding_ConcreteFoundation: BaseBuilding_FoundationBase
	{
		scope=2;
		descriptionShort="A constructed concrete foundation";
		model="RearmedServer\BaseBuilding\Foundation\ConcreteFoundation.p3d";
		materialLevel=4;
		hiddenSelections[]=
		{
			"bricks",
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

class CfgPatches
{
	class BaseBuilding_Wall
	{
		requiredAddons[]=
		{
			"Rearmed_BaseBuilding"
		};
		units[]=
		{
			"BaseBuilding_HologramWall",
			"BaseBuilding_FrameWall",
			"BaseBuilding_WoodWall",
			"BaseBuilding_MetalWall",
			"BaseBuilding_ConcreteWall"
		};
		weapons[]={};
	};
};
class CfgVehicles
{
	class BaseBuilding;
	class BaseBuilding_WallBase: BaseBuilding
	{
		displayName="Wall";
		displayIcon="set:BaseBuilding_Icons image:Wall";
		placementMode=2;
		class Snapping
		{
			class Top
			{
				allowReverse=1;
				acceptedTypes[]=
				{
					"BaseBuilding_WallBase",
					"BaseBuilding_HalfWallBase",
					"BaseBuilding_FloorBase",
					"BaseBuilding_TriangleFloorBase",
					"BaseBuilding_RoofBase"
				};
				forward[]={0,0,1};
				up[]={0,1,0};
			};
			class Bottom
			{
				allowReverse=1;
				acceptedSnapPoints[]=
				{
					"North",
					"South",
					"East",
					"West",
					"Top",
					"NorthEast",
					"NorthWest"
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
	class BaseBuilding_HologramWall: BaseBuilding_WallBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\Wall\HologramWall.p3d";
		materialLevel=0;
		upgradeType="BaseBuilding_FrameWall";
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
	class BaseBuilding_FrameWall: BaseBuilding_WallBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\Wall\FrameWall.p3d";
		materialLevel=1;
		upgradeType="BaseBuilding_WoodWall";
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
	class BaseBuilding_WoodWall: BaseBuilding_WallBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\Wall\WoodWall.p3d";
		materialLevel=2;
		upgradeType="BaseBuilding_MetalWall";
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
			"rearmedserver\basebuilding\materials\wood\data\wall_planks_co.paa",
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
								"rearmedserver\basebuilding\materials\wood\data\wall_planks.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"rearmedserver\basebuilding\materials\wood\data\wall_planks_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"rearmedserver\basebuilding\materials\wood\data\wall_planks_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"rearmedserver\basebuilding\materials\wood\data\wall_planks_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"rearmedserver\basebuilding\materials\wood\data\wall_planks_destruct.rvmat",
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
	class BaseBuilding_MetalWall: BaseBuilding_WallBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\Wall\MetalWall.p3d";
		materialLevel=3;
		upgradeType="BaseBuilding_ConcreteWall";
		attachments[]=
		{
			"CamoNet"
		};
		hiddenSelections[]=
		{
			"wood",
			"metal"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\gear\consumables\data\pile_of_planks_co.paa",
			"RearmedServer\BaseBuilding\Materials\Metal\data\Metal_Wall_co.paa"
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
								"RearmedServer\BaseBuilding\Materials\Metal\data\Metal_Wall.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\Metal_Wall_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\Metal_Wall_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\Metal_Wall_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\Metal_Wall_destruct.rvmat"
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
	class BaseBuilding_ConcreteWall: BaseBuilding_WallBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\Wall\ConcreteWall.p3d";
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

class CfgPatches
{
	class BaseBuilding_Floor
	{
		requiredAddons[]=
		{
			"Rearmed_BaseBuilding"
		};
		units[]=
		{
			"BaseBuilding_HologramFloor",
			"BaseBuilding_FrameFloor",
			"BaseBuilding_WoodFloor",
			"BaseBuilding_MetalFloor",
			"BaseBuilding_ConcreteFloor"
		};
		weapons[]={};
	};
};
class CfgVehicles
{
	class BaseBuilding;
	class BaseBuilding_FloorBase: BaseBuilding
	{
		displayIcon="set:BaseBuilding_Icons image:Floor";
		placementMode=2;
		class Snapping
		{
			class North
			{
				acceptedTypes[]=
				{
					"BaseBuilding_WallBase",
					"BaseBuilding_HalfWallBase"
				};
				acceptedSnapPoints[]=
				{
					"Bottom"
				};
				forward[]={0,0,-1};
				up[]={0,1,0};
			};
			class South
			{
				acceptedTypes[]=
				{
					"BaseBuilding_WallBase",
					"BaseBuilding_HalfWallBase"
				};
				acceptedSnapPoints[]=
				{
					"Bottom"
				};
				forward[]={0,0,1};
				up[]={0,1,0};
			};
			class East
			{
				acceptedTypes[]=
				{
					"BaseBuilding_WallBase",
					"BaseBuilding_HalfWallBase"
				};
				acceptedSnapPoints[]=
				{
					"Bottom"
				};
				forward[]={-1,0,0};
				up[]={0,1,0};
			};
			class West
			{
				acceptedTypes[]=
				{
					"BaseBuilding_WallBase",
					"BaseBuilding_HalfWallBase"
				};
				acceptedSnapPoints[]=
				{
					"Bottom"
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
	class BaseBuilding_HologramFloor: BaseBuilding_FloorBase
	{
		scope=2;
		displayName="Hologram Floor";
		model="RearmedServer\BaseBuilding\Floor\HologramFloor.p3d";
		materialLevel=0;
		upgradeType="BaseBuilding_FrameFloor";
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
	class BaseBuilding_FrameFloor: BaseBuilding_FloorBase
	{
		scope=2;
		displayName="Frame Floor";
		model="RearmedServer\BaseBuilding\Floor\FrameFloor.p3d";
		materialLevel=1;
		upgradeType="BaseBuilding_WoodFloor";
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
	class BaseBuilding_WoodFloor: BaseBuilding_FloorBase
	{
		scope=2;
		displayName="Wood Floor";
		model="RearmedServer\BaseBuilding\Floor\WoodFloor.p3d";
		materialLevel=2;
		upgradeType="BaseBuilding_MetalFloor";
		attachments[]=
		{
			"CamoNet"
		};
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
	class BaseBuilding_MetalFloor: BaseBuilding_FloorBase
	{
		scope=2;
		displayName="Metal Floor";
		descriptionShort="Less polys than the blender cube.";
		model="RearmedServer\BaseBuilding\Floor\MetalFloor.p3d";
		materialLevel=3;
		upgradeType="BaseBuilding_ConcreteFloor";
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
								"RearmedServer\BaseBuilding\Materials\Metal\data\MetalFloor.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_damage.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\metalfloor_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_damage.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\metalfloor_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_destruct.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\metalfloor_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_destruct.rvmat",
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
	class BaseBuilding_ConcreteFloor: BaseBuilding_FloorBase
	{
		scope=2;
		displayName="Concrete Floor";
		model="RearmedServer\BaseBuilding\Floor\ConcreteFloor.p3d";
		materialLevel=4;
		attachments[]=
		{
			"CamoNet"
		};
		hiddenSelections[]=
		{
			"floor",
			"concretebare"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\structures\data\concrete\concrete_panels_co.paa",
			"dz\structures\data\concrete\concrete_bare_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"rearmedserver\basebuilding\materials\concrete\vanillaconcrete_panels.rvmat",
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
								"rearmedserver\basebuilding\materials\concrete\vanillaconcrete_panels.rvmat",
								"rearmedserver\basebuilding\materials\concrete\vanillaconcretebare.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"rearmedserver\basebuilding\materials\concrete\vanillaconcrete_panels_damage.rvmat",
								"rearmedserver\basebuilding\materials\concrete\vanillaconcretebare_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"rearmedserver\basebuilding\materials\concrete\vanillaconcrete_panels_damage.rvmat",
								"rearmedserver\basebuilding\materials\concrete\vanillaconcretebare_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"rearmedserver\basebuilding\materials\concrete\vanillaconcrete_panels_destruct.rvmat",
								"rearmedserver\basebuilding\materials\concrete\vanillaconcretebare_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"rearmedserver\basebuilding\materials\concrete\vanillaconcrete_panels_destruct.rvmat",
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

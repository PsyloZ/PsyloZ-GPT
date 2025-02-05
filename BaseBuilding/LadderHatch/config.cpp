class CfgPatches
{
	class BaseBuilding_LadderHatch
	{
		requiredAddons[]=
		{
			"Rearmed_BaseBuilding"
		};
		units[]=
		{
			"BaseBuilding_HologramLadderHatch",
			"BaseBuilding_FrameLadderHatch",
			"BaseBuilding_WoodLadderHatch",
			"BaseBuilding_MetalLadderHatch",
			"BaseBuilding_ConcreteLadderHatch"
		};
		weapons[]={};
	};
};
class CfgVehicles
{
	class BaseBuilding_FloorBase;
	class Snapping;
	class North;
	class South;
	class East;
	class West;
	class BaseBuilding_LadderHatchBase: BaseBuilding_FloorBase
	{
		displayName="Ladder Hatch Frame";
		displayIcon="set:BaseBuilding_Icons image:Hatch";
		class Snapping: Snapping
		{
			class North: North
			{
			};
			class South: South
			{
			};
			class East: East
			{
			};
			class West: West
			{
			};
			class Hatch
			{
				acceptedTypes[]=
				{
					"BaseBuilding_HatchLadderBase"
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
	class BaseBuilding_HologramLadderHatch: BaseBuilding_LadderHatchBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\LadderHatch\HologramLadderHatch.p3d";
		upgradeType="BaseBuilding_FrameLadderHatch";
		materialLevel=0;
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
	class BaseBuilding_FrameLadderHatch: BaseBuilding_LadderHatchBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\LadderHatch\FrameLadderHatch.p3d";
		upgradeType="BaseBuilding_WoodLadderHatch";
		materialLevel=1;
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
	class BaseBuilding_WoodLadderHatch: BaseBuilding_LadderHatchBase
	{
		scope=2;
		descriptionShort="A single wooden door. If you put a code lock on it, make the password 1234.";
		model="RearmedServer\BaseBuilding\LadderHatch\WoodLadderHatch.p3d";
		upgradeType="BaseBuilding_MetalLadderHatch";
		materialLevel=2;
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
			"RearmedServer\BaseBuilding\Materials\Wood\data\Hatch_Planks_co.paa",
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
								"RearmedServer\BaseBuilding\Materials\Wood\data\Hatch_Planks.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\Hatch_Planks_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\Hatch_Planks_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\Hatch_Planks_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\Hatch_Planks_destruct.rvmat",
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
	class BaseBuilding_MetalLadderHatch: BaseBuilding_LadderHatchBase
	{
		scope=2;
		descriptionShort="A single wooden door. If you put a code lock on it, make the password 1234.";
		model="RearmedServer\BaseBuilding\LadderHatch\MetalLadderHatch.p3d";
		upgradeType="BaseBuilding_ConcreteLadderHatch";
		materialLevel=3;
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
	class BaseBuilding_ConcreteLadderHatch: BaseBuilding_LadderHatchBase
	{
		scope=2;
		descriptionShort="A single wooden door. If you put a code lock on it, make the password 1234.";
		model="RearmedServer\BaseBuilding\LadderHatch\ConcreteLadderHatch.p3d";
		materialLevel=4;
		attachments[]=
		{
			"CamoNet"
		};
		hiddenSelections[]=
		{
			"concrete_panels",
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

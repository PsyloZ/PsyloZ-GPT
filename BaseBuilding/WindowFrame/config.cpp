class CfgPatches
{
	class BaseBuilding_WindowFrame
	{
		requiredAddons[]=
		{
			"Rearmed_BaseBuilding"
		};
		units[]=
		{
			"BaseBuilding_HologramWindowFrame",
			"BaseBuilding_FrameWindowFrame",
			"BaseBuilding_WoodWindowFrame",
			"BaseBuilding_MetalWindowFrame",
			"BaseBuilding_ConcreteWindowFrame"
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
	class BaseBuilding_WindowFrameBase: BaseBuilding_WallBase
	{
		displayName="Window Frame";
		displayIcon="set:BaseBuilding_Icons image:Window_Frame";
		class Snapping: Snapping
		{
			class Top: Top
			{
			};
			class Bottom: Bottom
			{
			};
			class Shutter
			{
				acceptedTypes[]=
				{
					"BaseBuilding_WindowBase",
					"BaseBuilding_ShutterBase",
					"BaseBuilding_EmbrasureBase"
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
	class BaseBuilding_HologramWindowFrame: BaseBuilding_WindowFrameBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\WindowFrame\HologramWindowFrame.p3d";
		materialLevel=0;
		upgradeType="BaseBuilding_FrameWindowFrame";
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
	class BaseBuilding_FrameWindowFrame: BaseBuilding_WindowFrameBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\WindowFrame\FrameWindowFrame.p3d";
		materialLevel=1;
		upgradeType="BaseBuilding_WoodWindowFrame";
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
	class BaseBuilding_WoodWindowFrame: BaseBuilding_WindowFrameBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\WindowFrame\WoodWindowFrame.p3d";
		materialLevel=2;
		upgradeType="BaseBuilding_MetalWindowFrame";
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
			"rearmedserver\basebuilding\materials\wood\data\window_planks_co.paa",
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
								"rearmedserver\basebuilding\materials\wood\data\window_planks.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_pile_of_planks.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"rearmedserver\basebuilding\materials\wood\data\window_planks_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"rearmedserver\basebuilding\materials\wood\data\window_planks_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"rearmedserver\basebuilding\materials\wood\data\window_planks_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"rearmedserver\basebuilding\materials\wood\data\window_planks_destruct.rvmat",
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
	class BaseBuilding_MetalWindowFrame: BaseBuilding_WindowFrameBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\WindowFrame\MetalWindowFrame.p3d";
		materialLevel=3;
		upgradeType="BaseBuilding_ConcreteWindowFrame";
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
			"RearmedServer\BaseBuilding\Materials\Metal\data\Metal_WindowFrame_co.paa"
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
								"RearmedServer\BaseBuilding\Materials\Metal\data\Metal_WindowFrame.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\Metal_WindowFrame_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\Metal_WindowFrame_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\Metal_WindowFrame_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Materials\Wood\data\RA_generic_wood_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\Metal_WindowFrame_destruct.rvmat"
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
	class BaseBuilding_ConcreteWindowFrame: BaseBuilding_WindowFrameBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\WindowFrame\ConcreteWindowFrame.p3d";
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

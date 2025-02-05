class CfgPatches
{
	class BaseBuilding_Windows
	{
		units[]=
		{
			"BaseBuilding_HologramWindow",
			"BaseBuilding_WoodWindow",
			"BaseBuilding_HologramShutters",
			"BaseBuilding_WoodShutters",
			"BaseBuilding_HologramEmbrasure",
			"BaseBuilding_MetalEmbrasure"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"Rearmed_BaseBuilding"
		};
	};
};
class CfgVehicles
{
	class BaseBuilding;
	class BaseBuilding_WindowBase: BaseBuilding
	{
		displayName="Window";
		displayIcon="set:BaseBuilding_Icons image:Window";
		placementMode=2;
		class UpgradeSystem
		{
			class Hologram
			{
			};
			class Wood
			{
				class Construct
				{
					item="WoodenPlank";
					quantity=4;
				};
				class Repair
				{
					item="WoodenPlank";
					quantity=4;
				};
			};
			class Metal
			{
				class Construct
				{
					item="MetalPlate";
					quantity=4;
				};
				class Repair
				{
					item="MetalPlate";
					quantity=4;
				};
			};
		};
		class Snapping
		{
			class Window
			{
				acceptedTypes[]=
				{
					"BaseBuilding_WindowFrameBase"
				};
				forward[]={0,0,-1};
				up[]={0,1,0};
			};
		};
	};
	class BaseBuilding_HologramWindow: BaseBuilding_WindowBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\Windows\HologramWindow_Glass.p3d";
		upgradeType="BaseBuilding_WoodWindow";
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
	class BaseBuilding_WoodWindow: BaseBuilding_WindowBase
	{
		scope=2;
		descriptionShort="A wooden window. Bound to be broken by some kids playing golf";
		model="RearmedServer\BaseBuilding\Windows\WoodWindow_Glass.p3d";
		hiddenSelectionsTextures[]=
		{
			"dz\gear\consumables\data\pile_of_planks_co.paa"
		};
		materialLevel=2;
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
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage=0;
					};
				};
				class Melee
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
		};
	};
	class BaseBuilding_ShutterBase: BaseBuilding
	{
		displayName="Window Shutters";
		displayIcon="set:BaseBuilding_Icons image:Shutter";
		placementMode=2;
		class Snapping
		{
			class Window
			{
				acceptedTypes[]=
				{
					"BaseBuilding_WindowFrameBase"
				};
				forward[]={0,0,-1};
				up[]={0,1,0};
			};
		};
		class UpgradeSystem
		{
			class Hologram
			{
			};
			class Wood
			{
				class Construct
				{
					item="WoodenPlank";
					quantity=4;
				};
				class Repair
				{
					item="WoodenPlank";
					quantity=4;
				};
			};
			class Metal
			{
				class Construct
				{
					item="MetalPlate";
					quantity=4;
				};
				class Repair
				{
					item="MetalPlate";
					quantity=4;
				};
			};
		};
		attachments[]=
		{
			"CodeLock"
		};
		class AnimationSources
		{
			class shutters
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
		};
	};
	class BaseBuilding_HologramShutters: BaseBuilding_ShutterBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\Windows\HologramWindow_Shutter.p3d";
		upgradeType="BaseBuilding_WoodShutters";
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
		materialLevel=0;
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
	class BaseBuilding_WoodShutters: BaseBuilding_ShutterBase
	{
		scope=2;
		descriptionShort="A single wooden door. If you put a code lock on it, make the password 1234.";
		model="RearmedServer\BaseBuilding\Windows\WoodWindow_Shutter.p3d";
		hiddenSelectionsTextures[]=
		{
			"dz\gear\consumables\data\pile_of_planks_co.paa"
		};
		materialLevel=2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1250;
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
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage=0;
					};
				};
				class Melee
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
		};
	};
	class BaseBuilding_EmbrasureBase: BaseBuilding
	{
		displayName="Window Embrasure";
		displayIcon="set:BaseBuilding_Icons image:Embrasure";
		placementMode=2;
		class Snapping
		{
			class Window
			{
				acceptedTypes[]=
				{
					"BaseBuilding_WindowFrameBase"
				};
				forward[]={0,0,-1};
				up[]={0,1,0};
			};
		};
		class UpgradeSystem
		{
			class Hologram
			{
			};
			class Wood
			{
				class Construct
				{
					item="WoodenPlank";
					quantity=2;
				};
				class Repair
				{
					item="WoodenPlank";
					quantity=2;
				};
			};
			class Metal
			{
				class Construct
				{
					item="MetalPlate";
					quantity=2;
				};
				class Repair
				{
					item="MetalPlate";
					quantity=2;
				};
			};
		};
	};
	class BaseBuilding_HologramEmbrasure: BaseBuilding_EmbrasureBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\Windows\HologramWindow_Embrasure.p3d";
		upgradeType="BaseBuilding_MetalEmbrasure";
		hiddenSelections[]=
		{
			"metal"
		};
		hiddenSelectionsTextures[]=
		{
			"#(argb,8,8,3)color(0.756863,0.741176,0.733333,0.9,co)"
		};
		hiddenSelectionsMaterials[]=
		{
			"rearmedserver\basebuilding\materials\basebuilding_neutral.rvmat"
		};
		materialLevel=0;
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
	class BaseBuilding_MetalEmbrasure: BaseBuilding_EmbrasureBase
	{
		scope=2;
		descriptionShort="A collection of metal used to create a fighting position from your windows.";
		model="RearmedServer\BaseBuilding\Windows\MetalWindow_Embrasure.p3d";
		hiddenSelectionsTextures[]=
		{
			"dz\structures\data\metal\metal_servicehangar_rust_co.paa",
			"dz\structures\data\metal\metal_rollup_co.paa",
			"dz\gear\consumables\data\metalsheets_co.paa",
			"dz\structures\industrial\smokestacks\data\smokestack_metal_floor_co.paa",
			"dz\structures\industrial\cementworks\data\wavy_sheet_co.paa"
		};
		materialLevel=3;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=2250;
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
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage=0;
					};
				};
				class Melee
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
		};
	};
};

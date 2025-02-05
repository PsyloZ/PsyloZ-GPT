class CfgPatches
{
	class BaseBuilding_CompoundGate
	{
		requiredAddons[]=
		{
			"Rearmed_BaseBuilding"
		};
		units[]=
		{
			"BaseBuilding_HologramCompoundGate",
			"BaseBuilding_FrameCompoundGate",
			"BaseBuilding_WoodCompoundGate",
			"BaseBuilding_MetalCompoundGate",
			"BaseBuilding_ConcreteCompoundGate"
		};
		weapons[]={};
	};
};
class CfgVehicles
{
	class BaseBuilding;
	class UpgradeSystem;
	class BaseBuilding_CompoundGateBase: BaseBuilding
	{
		displayName="Compound Gate";
		displayIcon="set:BaseBuilding_Icons image:CompoundGate";
		placementMode=1;
		stabilityNode=1;
		class AnimationSources
		{
			class door
			{
				source="user";
				animPeriod=2.5;
				initPhase=0;
			};
		};
		class UpgradeSystem: UpgradeSystem
		{
			class Wood
			{
				class Construct
				{
					item="WoodenLog";
					quantity=8;
				};
			};
		};
	};
	class BaseBuilding_HologramCompoundGate: BaseBuilding_CompoundGateBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\CompoundGate\HologramCompoundGate.p3d";
		upgradeType="BaseBuilding_FrameCompoundGate";
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
	class BaseBuilding_FrameCompoundGate: BaseBuilding_CompoundGateBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\CompoundGate\CompoundGateFrame.p3d";
		materialLevel=1;
		upgradeType="BaseBuilding_WoodCompoundGate";
		attachments[]=
		{
			"CodeLock"
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
	class BaseBuilding_WoodCompoundGate: BaseBuilding_CompoundGateBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\CompoundGate\WoodCompoundGate.p3d";
		materialLevel=2;
		upgradeType="BaseBuilding_MetalCompoundGate";
		attachments[]=
		{
			"CodeLock"
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
	class BaseBuilding_MetalCompoundGate: BaseBuilding_CompoundGateBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\CompoundGate\MetalCompoundGate.p3d";
		materialLevel=3;
		upgradeType="BaseBuilding_ConcreteCompoundGate";
		attachments[]=
		{
			"CodeLock"
		};
		hiddenSelections[]=
		{
			"wood"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\structures\data\metal\metal_darkred_rusty_co.paa"
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
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_darkred_rusty.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_darkred_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_darkred_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_darkred_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_darkred_destruct.rvmat"
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
	class BaseBuilding_ConcreteCompoundGate: BaseBuilding_CompoundGateBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\CompoundGate\ConcreteCompoundGate.p3d";
		materialLevel=4;
		attachments[]=
		{
			"CodeLock"
		};
		hiddenSelections[]=
		{
			"camo_doors",
			"camo_ext",
			"camo_joints",
			"camo_locks"
		};
		hiddenSelectionsTextures[]=
		{
			"RearmedServer\BaseBuilding\Materials\Concrete\T3CompoundGate_Doors_co.paa",
			"RearmedServer\BaseBuilding\Materials\Concrete\T3CompoundGate_Ext_co.paa",
			"RearmedServer\BaseBuilding\Materials\Concrete\T3CompoundGate_Joints_co.paa",
			"RearmedServer\BaseBuilding\Materials\Concrete\T3CompoundGate_Locks_co.paa"
		};
		class AnimationSources
		{
			class door
			{
				source="user";
				animPeriod=2.5;
				initPhase=0;
			};
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
								"RearmedServer\BaseBuilding\Materials\Concrete\T3CompoundGate_Doors.rvmat",
								"RearmedServer\BaseBuilding\Materials\Concrete\T3CompoundGate_Ext.rvmat",
								"RearmedServer\BaseBuilding\Materials\Concrete\T3CompoundGate_Joints.rvmat",
								"RearmedServer\BaseBuilding\Materials\Concrete\T3CompoundGate_Locks.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"RearmedServer\BaseBuilding\Materials\Concrete\T3CompoundGate_Doors.rvmat",
								"RearmedServer\BaseBuilding\Materials\Concrete\T3CompoundGate_Ext.rvmat",
								"RearmedServer\BaseBuilding\Materials\Concrete\T3CompoundGate_Joints.rvmat",
								"RearmedServer\BaseBuilding\Materials\Concrete\T3CompoundGate_Locks.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Materials\Concrete\T3CompoundGate_Doors.rvmat",
								"RearmedServer\BaseBuilding\Materials\Concrete\T3CompoundGate_Ext.rvmat",
								"RearmedServer\BaseBuilding\Materials\Concrete\T3CompoundGate_Joints.rvmat",
								"RearmedServer\BaseBuilding\Materials\Concrete\T3CompoundGate_Locks.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Materials\Concrete\T3CompoundGate_Doors.rvmat",
								"RearmedServer\BaseBuilding\Materials\Concrete\T3CompoundGate_Ext.rvmat",
								"RearmedServer\BaseBuilding\Materials\Concrete\T3CompoundGate_Joints.rvmat",
								"RearmedServer\BaseBuilding\Materials\Concrete\T3CompoundGate_Locks.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Materials\Concrete\T3CompoundGate_Doors.rvmat",
								"RearmedServer\BaseBuilding\Materials\Concrete\T3CompoundGate_Ext.rvmat",
								"RearmedServer\BaseBuilding\Materials\Concrete\T3CompoundGate_Joints.rvmat",
								"RearmedServer\BaseBuilding\Materials\Concrete\T3CompoundGate_Locks.rvmat"
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

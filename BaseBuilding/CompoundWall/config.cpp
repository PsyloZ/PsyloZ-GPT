class CfgPatches
{
	class BaseBuilding_CompoundWall
	{
		requiredAddons[]=
		{
			"Rearmed_BaseBuilding"
		};
		units[]=
		{
			"BaseBuilding_HologramCompoundWall",
			"BaseBuilding_CompoundWall_Frame",
			"BaseBuilding_CompoundWall_Wood",
			"BaseBuilding_CompoundWall_Metal",
			"BaseBuilding_CompoundWall_Concrete"
		};
		weapons[]={};
	};
};
class CfgVehicles
{
	class BaseBuilding;
	class UpgradeSystem;
	class BaseBuilding_CompoundWallBase: BaseBuilding
	{
		displayName="Compound Wall";
		displayIcon="set:BaseBuilding_Icons image:CompoundWall";
		placementMode=1;
		stabilityNode=1;
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
	class BaseBuilding_HologramCompoundWall: BaseBuilding_CompoundWallBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\CompoundWall\HologramCompoundWall.p3d";
		upgradeType="BaseBuilding_CompoundWall_Frame";
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
	class BaseBuilding_CompoundWall_Frame: BaseBuilding_CompoundWallBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\CompoundWall\CompoundWallFrame.p3d";
		upgradeType="BaseBuilding_CompoundWall_Wood";
		materialLevel=1;
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
	class BaseBuilding_CompoundWall_Wood: BaseBuilding_CompoundWallBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\CompoundWall\WoodCompoundWall.p3d";
		materialLevel=2;
		upgradeType="BaseBuilding_CompoundWall_Metal";
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
	class BaseBuilding_CompoundWall_Metal: BaseBuilding_CompoundWallBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\CompoundWall\MetalCompoundWall.p3d";
		materialLevel=3;
		upgradeType="BaseBuilding_CompoundWall_Concrete";
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
	class BaseBuilding_CompoundWall_Concrete: BaseBuilding_CompoundWallBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\CompoundWall\ConcreteCompoundWall.p3d";
		materialLevel=4;
		hiddenSelections[]=
		{
			"pillars",
			"wall"
		};
		hiddenSelectionsTextures[]=
		{
			"RearmedServer\BaseBuilding\Materials\Concrete\Pillar_co.paa",
			"RearmedServer\BaseBuilding\Materials\Concrete\Wall_co.paa"
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
								"RearmedServer\BaseBuilding\Materials\Concrete\Pillar.rvmat",
								"RearmedServer\BaseBuilding\Materials\Concrete\Wall.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"RearmedServer\BaseBuilding\Materials\Concrete\Pillar_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Concrete\Wall_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Materials\Concrete\Pillar_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Concrete\Wall_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Materials\Concrete\Pillar_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Concrete\Wall_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Materials\Concrete\Pillar_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Concrete\Wall_destruct.rvmat"
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

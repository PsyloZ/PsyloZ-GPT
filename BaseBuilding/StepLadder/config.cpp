class CfgPatches
{
	class BaseBuilding_StepLadder
	{
		units[]=
		{
			"BaseBuilding_HologramStepLadder",
			"BaseBuilding_WoodStepLadder"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgVehicles
{
	class BaseBuilding_WallBase;
	class BaseBuilding_StepLadderBase: BaseBuilding_WallBase
	{
		displayName="Step Ladder";
		displayIcon="set:BaseBuilding_Icons image:Ladder";
		placementMode=1;
	};
	class BaseBuilding_HologramStepLadder: BaseBuilding_StepLadderBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\StepLadder\HologramStepLadder.p3d";
		upgradeType="BaseBuilding_WoodStepLadder";
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
	class BaseBuilding_WoodStepLadder: BaseBuilding_StepLadderBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\StepLadder\StepLadder.p3d";
		materialLevel=2;
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
					hitpoints=100;
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
				class FragGrenade
				{
					class Health
					{
						damage=10;
					};
				};
				class Melee
				{
					class Health
					{
						damage=1;
					};
				};
			};
		};
	};
};

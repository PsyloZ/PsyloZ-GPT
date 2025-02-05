class CfgPatches
{
	class RA_Server_Building_CinderBlock
	{
		units[]=
		{
			"RA_Cinderblock"
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
	class Inventory_Base;
	class RA_Cinderblock: Inventory_Base
	{
		scope=2;
		displayName="$STR_RA_CINDERBLOCK";
		descriptionShort="$STR_DES_RA_CINDERBLOCK";
		model="\RearmedServer\BaseBuilding\Tools\CinderBlock\CinderBlock.p3d";
		canBeSplit=1;
		weight=20000;
		varQuantityInit=8;
		varQuantityMin=0;
		varQuantityMax=25;
		varQuantityDestroyOnMin=1;
		varStackMax=8;
		itemSize[]={5,3};
		absorbency=0;
		rotationFlags=2;
		repairableWithKits[]={7};
		repairCosts[]={25};
		lockType=1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1500;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"RearmedServer\BaseBuilding\Tools\CinderBlock\data\cinderblock.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"RearmedServer\BaseBuilding\Tools\CinderBlock\data\cinderblock.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Tools\CinderBlock\data\cinderblock_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Tools\CinderBlock\data\cinderblock_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Tools\CinderBlock\data\cinderblock_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class drop
				{
					soundset="carbattery_drop_SoundSet";
					id=898;
				};
			};
		};
	};
};

class CfgPatches
{
	class BaseBuilding_Blueprint
	{
		units[]=
		{
			"RA_Blueprint"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"Rearmed_BaseBuilding"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class RA_Blueprint: Inventory_Base
	{
		scope=2;
		displayName="$STR_RA_BLUEPRINT";
		descriptionShort="$STR_DES_RA_BLUEPRINT";
		model="\dz\gear\navigation\Map_chernarus_animated.p3d";
		rotationFlags=17;
		itemSize[]={1,2};
		weight=40;
		hiddenSelections[]=
		{
			"texture_map_closed",
			"texture_map_opened",
			"texture_legend"
		};
		hiddenSelectionsTextures[]=
		{
			"RearmedServer\BaseBuilding\Tools\Blueprint\data\Blueprint_co.paa",
			"RearmedServer\BaseBuilding\Tools\Blueprint\data\Blueprint_co.paa",
			"RearmedServer\BaseBuilding\Tools\Blueprint\data\Blueprint_co.paa"
		};
		absorbency=1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=50;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\navigation\data\Map_chernarus.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\navigation\data\Map_chernarus.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\navigation\data\Map_chernarus_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\navigation\data\Map_chernarus_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\navigation\data\Map_chernarus_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimationSources
		{
			class map_closed
			{
				source="user";
				animPeriod=0.1;
				initPhase=0;
			};
			class map_opened
			{
				source="user";
				animPeriod=0.1;
				initPhase=1;
			};
		};
	};
};

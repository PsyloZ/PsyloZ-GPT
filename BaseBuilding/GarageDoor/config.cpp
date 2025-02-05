class CfgPatches
{
	class BaseBuilding_GarageDoor
	{
		requiredAddons[]=
		{
			"Rearmed_BaseBuilding"
		};
		units[]=
		{
			"BaseBuilding_HologramGarageDoor",
			"BaseBuilding_WoodGarageDoor",
			"BaseBuilding_MetalGarageDoor"
		};
		weapons[]={};
	};
};
class CfgVehicles
{
	class BaseBuilding;
	class BaseBuilding_GarageDoorBase: BaseBuilding
	{
		displayName="Garage Door";
		displayIcon="set:BaseBuilding_Icons image:Garage";
		placementMode=2;
		class Snapping
		{
			class DoubleDoor
			{
				acceptedTypes[]=
				{
					"BaseBuilding_DoubleDoorFrameBase"
				};
				forward[]={0,0,-1};
				up[]={0,1,0};
			};
		};
		physLayer="item_large";
		carveNavmesh=1;
		overrideDrawArea="8.0";
		forceFarBubble="true";
		heavyItem=1;
		weight=10000;
		itemSize[]={10,10};
		hiddenSelections[]=
		{
			"camo"
		};
		rotationFlags=34;
		attachments[]=
		{
			"CodeLock"
		};
		class AnimationSources
		{
			class door
			{
				source="user";
				animPeriod=1.5;
				initPhase=0;
			};
		};
	};
	class BaseBuilding_HologramGarageDoor: BaseBuilding_GarageDoorBase
	{
		scope=2;
		descriptionShort="peepee poopoo.";
		model="RearmedServer\BaseBuilding\GarageDoor\HologramGarageDoor.p3d";
		upgradeType="BaseBuilding_WoodGarageDoor";
		hiddenSelections[]=
		{
			"camo"
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
	class BaseBuilding_WoodGarageDoor: BaseBuilding_GarageDoorBase
	{
		scope=2;
		descriptionShort="A wooden garage door. If you put a code lock on it, make the password 1234.";
		model="RearmedServer\BaseBuilding\GarageDoor\WoodGarageDoor.p3d";
		upgradeType="BaseBuilding_MetalGarageDoor";
		hiddenSelectionsTextures[]=
		{
			"RearmedServer\BaseBuilding\Materials\Wood\data\garage_door_co.paa"
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
	class BaseBuilding_MetalGarageDoor: BaseBuilding_GarageDoorBase
	{
		scope=2;
		descriptionShort="A metal garage door. If you put a code lock on it, don't make the password 1234.";
		model="RearmedServer\BaseBuilding\GarageDoor\MetalGarageDoor.p3d";
		hiddenSelectionsTextures[]=
		{
			"rearmedserver\basebuilding\materials\metal\data\metal_rollup90_red_co.paa"
		};
		materialLevel=3;
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
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_rollup90.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_rollup_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_rollup_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_rollup_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Materials\Metal\data\metal_rollup_destruct.rvmat"
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
		class AnimationSources
		{
			class door
			{
				source="user";
				animPeriod=1.5;
				initPhase=0;
			};
		};
	};
};

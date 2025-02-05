class CfgPatches
{
	class BaseBuilding_DoorWall
	{
		requiredAddons[]=
		{
			"Rearmed_BaseBuilding"
		};
		units[]=
		{
			"BaseBuilding_HologramSingleDoor",
			"BaseBuilding_WoodSingleDoor",
			"BaseBuilding_MetalSingleDoor",
			"BaseBuilding_VaultSingleDoor"
		};
		weapons[]={};
	};
};
class CfgVehicles
{
	class BaseBuilding;
	class BaseBuilding_SingleDoorBase: BaseBuilding
	{
		displayName="Door";
		displayIcon="set:BaseBuilding_Icons image:Door";
		placementMode=2;
		class Snapping
		{
			class Door
			{
				acceptedTypes[]=
				{
					"BaseBuilding_DoorFrameBase"
				};
				forward[]={0,0,-1};
				up[]={0,1,0};
			};
		};
		heavyItem=1;
		weight=10000;
		itemSize[]={5,10};
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
				animPeriod=1;
				initPhase=0;
			};
		};
	};
	class BaseBuilding_HologramSingleDoor: BaseBuilding_SingleDoorBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\Door\HologramDoor.p3d";
		upgradeType="BaseBuilding_WoodSingleDoor";
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
	class BaseBuilding_WoodSingleDoor: BaseBuilding_SingleDoorBase
	{
		scope=2;
		descriptionShort="A single wooden door. If you put a code lock on it, make the password 1234.";
		model="RearmedServer\BaseBuilding\Door\WoodDoor.p3d";
		upgradeType="BaseBuilding_MetalSingleDoor";
		hiddenSelections[]=
		{
			"planks",
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"rearmedserver\basebuilding\materials\wood\data\door_planks_co.paa",
			"rearmedserver\basebuilding\materials\wood\data\DoubleDoorWood_Extras_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"rearmedserver\basebuilding\materials\wood\data\door_planks.rvmat",
			"rearmedserver\basebuilding\materials\wood\data\DoubleDoorWood_Extras.rvmat"
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
								"rearmedserver\basebuilding\materials\wood\data\door_planks.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\DoubleDoorWood_Extras.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"rearmedserver\basebuilding\materials\wood\data\door_planks_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\DoubleDoorWood_Extras_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"rearmedserver\basebuilding\materials\wood\data\door_planks_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\DoubleDoorWood_Extras_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"rearmedserver\basebuilding\materials\wood\data\door_planks_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\DoubleDoorWood_Extras_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"rearmedserver\basebuilding\materials\wood\data\door_planks_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\DoubleDoorWood_Extras_destruct.rvmat"
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
	class BaseBuilding_MetalSingleDoor: BaseBuilding_SingleDoorBase
	{
		scope=2;
		descriptionShort="A single metal door. If you put a code lock on it, don't make the password 1234.";
		model="RearmedServer\BaseBuilding\Door\MetalDoor.p3d";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"RearmedServer\BaseBuilding\Materials\Metal\data\SingleDoor_Metal_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"RearmedServer\BaseBuilding\Materials\Metal\data\SingleDoor_Metal.rvmat"
		};
		upgradeType="BaseBuilding_VaultSingleDoor";
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
								"RearmedServer\BaseBuilding\Materials\Metal\data\SingleDoor_Metal.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"RearmedServer\BaseBuilding\Materials\Metal\data\SingleDoor_Metal_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Materials\Metal\data\SingleDoor_Metal_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Materials\Metal\data\SingleDoor_Metal_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Materials\Metal\data\SingleDoor_Metal_destruct.rvmat"
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
	class BaseBuilding_VaultSingleDoor: BaseBuilding_SingleDoorBase
	{
		scope=2;
		descriptionShort="A single Vault door. If you put a code lock on it, don't make the password 1234.";
		model="RearmedServer\BaseBuilding\Door\T3VaultDoor.p3d";
		hiddenSelections[]=
		{
			"camo_base",
			"camo_door"
		};
		hiddenSelectionsTextures[]=
		{
			"rearmedserver\basebuilding\materials\metal\data\T3_singledoor_base_co.paa",
			"rearmedserver\basebuilding\materials\metal\data\T3_single_door_co.paa"
		};
		materialLevel=3;
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
								"RearmedServer\BaseBuilding\Materials\Metal\data\T3_singledoor_base.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\T3_single_door.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"RearmedServer\BaseBuilding\Materials\Metal\data\T3_singledoor_base_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\T3_single_door_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Materials\Metal\data\T3_singledoor_base_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\T3_single_door_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Materials\Metal\data\T3_singledoor_base_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\T3_single_door_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Materials\Metal\data\T3_singledoor_base_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Metal\data\T3_single_door_destruct.rvmat"
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

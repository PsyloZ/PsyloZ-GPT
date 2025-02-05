class CfgPatches
{
	class BaseBuilding_DoubleDoorWall
	{
		requiredAddons[]=
		{
			"Rearmed_BaseBuilding"
		};
		units[]=
		{
			"BaseBuilding_HologramDoubleDoor",
			"BaseBuilding_WoodDoubleDoor",
			"BaseBuilding_MetalDoubleDoor",
			"BaseBuilding_VaultDoubleDoor"
		};
		weapons[]={};
	};
};
class CfgVehicles
{
	class BaseBuilding;
	class BaseBuilding_DoubleDoorBase: BaseBuilding
	{
		displayName="Double Door";
		displayIcon="set:BaseBuilding_Icons image:DoubleDoor";
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
				animPeriod=1;
				initPhase=0;
			};
		};
	};
	class BaseBuilding_HologramDoubleDoor: BaseBuilding_DoubleDoorBase
	{
		scope=2;
		model="RearmedServer\BaseBuilding\DoubleDoor\HologramDoubleDoor.p3d";
		upgradeType="BaseBuilding_WoodDoubleDoor";
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
	class BaseBuilding_WoodDoubleDoor: BaseBuilding_DoubleDoorBase
	{
		scope=2;
		descriptionShort="A Double wooden door. If you put a code lock on it, make the password 1234.";
		model="RearmedServer\BaseBuilding\DoubleDoor\WoodDoubleDoor.p3d";
		upgradeType="BaseBuilding_MetalDoubleDoor";
		hiddenSelections[]=
		{
			"planks",
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"rearmedserver\basebuilding\materials\wood\data\DoubleDoor_Planks_co.paa",
			"rearmedserver\basebuilding\materials\wood\data\DoubleDoorWood_Extras_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"rearmedserver\basebuilding\materials\wood\data\DoubleDoor_Planks.rvmat",
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
								"rearmedserver\basebuilding\materials\wood\data\DoubleDoor_Planks.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\DoubleDoorWood_Extras.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"rearmedserver\basebuilding\materials\wood\data\DoubleDoor_Planks_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\DoubleDoorWood_Extras_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"rearmedserver\basebuilding\materials\wood\data\DoubleDoor_Planks_damage.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\DoubleDoorWood_Extras_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"rearmedserver\basebuilding\materials\wood\data\DoubleDoor_Planks_destruct.rvmat",
								"RearmedServer\BaseBuilding\Materials\Wood\data\DoubleDoorWood_Extras_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"rearmedserver\basebuilding\materials\wood\data\DoubleDoor_Planks_destruct.rvmat",
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
	class BaseBuilding_MetalDoubleDoor: BaseBuilding_DoubleDoorBase
	{
		scope=2;
		descriptionShort="A Double metal door. If you put a code lock on it, don't make the password 1234.";
		model="RearmedServer\BaseBuilding\DoubleDoor\MetalDoubleDoor.p3d";
		upgradeType="BaseBuilding_VaultDoubleDoor";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"RearmedServer\BaseBuilding\Materials\Metal\data\DoubleDoor_Metal_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"RearmedServer\BaseBuilding\Materials\Metal\data\DoubleDoor_Metal_co.paa"
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
								"RearmedServer\BaseBuilding\Materials\Metal\data\DoubleDoor_Metal.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"RearmedServer\BaseBuilding\Materials\Metal\data\DoubleDoor_Metal_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"RearmedServer\BaseBuilding\Materials\Metal\data\DoubleDoor_Metal_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"RearmedServer\BaseBuilding\Materials\Metal\data\DoubleDoor_Metal_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"RearmedServer\BaseBuilding\Materials\Metal\data\DoubleDoor_Metal_destruct.rvmat"
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
	class BaseBuilding_VaultDoubleDoor: BaseBuilding_DoubleDoorBase
	{
		scope=2;
		descriptionShort="A Vault Double door. I thought there was already a metal door bro wtf?";
		model="RearmedServer\BaseBuilding\DoubleDoor\T3DoubleDoor.p3d";
		materialLevel=3;
		hiddenSelections[]=
		{
			"door",
			"base"
		};
		hiddenSelectionsTextures[]=
		{
			"rearmedserver\basebuilding\materials\metal\data\t3_double_door_co.paa",
			"rearmedserver\basebuilding\materials\metal\data\t3_doubledoor_base_co.paa"
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
								"rearmedserver\basebuilding\materials\metal\data\t3_double_door.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\t3_doubledoor_base.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"rearmedserver\basebuilding\materials\metal\data\t3_double_door_damage.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\t3_doubledoor_base_damage.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"rearmedserver\basebuilding\materials\metal\data\t3_double_door_damage.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\t3_doubledoor_base_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"rearmedserver\basebuilding\materials\metal\data\t3_double_door_destruct.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\t3_doubledoor_base_destruct.rvmat"
							}
						},
						
						{
							0,
							
							{
								"rearmedserver\basebuilding\materials\metal\data\t3_double_door_destruct.rvmat",
								"rearmedserver\basebuilding\materials\metal\data\t3_doubledoor_base_destruct.rvmat"
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

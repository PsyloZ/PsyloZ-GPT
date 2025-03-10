class CfgPatches
{
	class RA_Gear_BetterStash
	{
		units[]=
		{
			"PlasticBarrel",
			"PlasticBarrelStash",
			"RA_Static_PlasticBarrelStash"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Containers"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Container_Base;
	class PlasticBarrel_ColorBase: Container_Base
	{
		displayName="Plastic Barrel";
		descriptionShort="A 220l plastic barrel, used for storing liquids. Could be buried and used as a stash, but must be emptied first.";
		model="\ZLCrates\LootCrate\BarrelStash\PlasticBarrel.p3d";
		overrideDrawArea="8.0";
		forceFarBubble="true";
		slopeTolerance=0.2;
		yawPitchRollLimit[]={45,45,45};
		destroyOnEmpty=0;
		varQuantityDestroyOnMin=0;
		quantityBar=1;
		carveNavmesh=1;
		canBeDigged=0;
		heavyItem=1;
		inventorySlot[]={};
		weight=7500;
		itemSize[]={5,6};
		itemBehaviour=0;
		stackedUnit="ml";
		randomQuantity=2;
		varLiquidTypeInit=512;
		liquidContainerType="1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256) -32768";
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=22000;
		absorbency=0.1;
		physLayer="item_large";
		allowOwnedCargoManipulation=1;
		hiddenSelections[]=
		{
			"camoGround"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1300;
				};
			};
			class GlobalArmor
			{
				class FragGrenade
				{
					class Health
					{
						damage=8;
					};
					class Blood
					{
						damage=8;
					};
					class Shock
					{
						damage=8;
					};
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[]={9,10};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		class AnimationSources
		{
			class latch
			{
				source="user";
				initPhase=0;
				animPeriod=0.5;
			};
			class lid
			{
				source="user";
				initPhase=0;
				animPeriod=0.5;
			};
			class lidrotate
			{
				source="user";
				initPhase=0;
				animPeriod=0.5;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class movement
				{
					soundSet="barrel_movement_SoundSet";
					id=1;
				};
				class pickUpItem_Light
				{
					soundSet="pickUpBarrelLight_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpBarrel_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="barrel_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class PlasticBarrel: PlasticBarrel_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\ZLCrates\LootCrate\BarrelStash\data\PlasticBarrel_co.paa"
		};
		hologramMaterial="PlasticBarrel";
		hologramMaterialPath="ZLCrates\LootCrate\BarrelStash\data";
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"ZLCrates\LootCrate\BarrelStash\data\PlasticBarrel.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"ZLCrates\LootCrate\BarrelStash\data\PlasticBarrel.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"ZLCrates\LootCrate\BarrelStash\data\PlasticBarrel_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"ZLCrates\LootCrate\BarrelStash\data\PlasticBarrel_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"ZLCrates\LootCrate\BarrelStash\data\PlasticBarrel_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class PlasticBarrelStash: Inventory_Base
	{
		scope=2;
		displayName="Hidden Cache";
		model="\ZLCrates\LootCrate\BarrelStash\BuriedBarrel.p3d";
		canBeDigged=0;
		hiddenSelections[]=
		{
			"camoGround"
		};
		hiddenSelectionsTextues[]=
		{
			"ZLCrates\LootCrate\BarrelStash\data\PlasticBarrel_dirty_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"ZLCrates\LootCrate\BarrelStash\data\PlasticBarrel_dirty.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1300;
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
					class Blood
					{
						damage=0;
					};
					class Shock
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
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[]={9,10};
			openable=1;
			allowOwnedCargoManipulation=1;
		};
		class AnimationSources
		{
			class lid
			{
				source="user";
				initPhase=0;
				animPeriod=0.5;
			};
		};
	};
	class ZLandContainerBase;
	class RA_Static_PlasticBarrelStash: ZLandContainerBase
	{
		scope=2;
		displayName="Hidden Cache";
		model="\ZLCrates\LootCrate\BarrelStash\BuriedBarrel.p3d";
		canBeDigged=0;
		hiddenSelections[]=
		{
			"camoGround"
		};
		hiddenSelectionsTextues[]=
		{
			"ZLCrates\LootCrate\BarrelStash\data\PlasticBarrel_dirty_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"ZLCrates\LootCrate\BarrelStash\data\PlasticBarrel_dirty.rvmat"
		};
		class AnimationSources
		{
			class latch
			{
				source="user";
				initPhase=0;
				animPeriod=0.5;
			};
			class lid
			{
				source="user";
				initPhase=0;
				animPeriod=0.5;
			};
			class lidrotate
			{
				source="user";
				initPhase=0;
				animPeriod=0.5;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,15};
			openable=1;
			allowOwnedCargoManipulation=1;
		};
	};
};

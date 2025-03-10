class CfgPatches
{
	class ZLand_Crates
	{
		units[]=
		{
			"ZLandLootCrate",
			"BlueLootCrate",
			"BlueKeycardLootCrate",
			"GreenLootCrate",
			"GreenKeycardLootCrate",
			"YellowLootCrate",
			"YellowKeycardLootCrate",
			"PurpleLootCrate",
			"PurpleKeycardLootCrate",
			"Key1LootCrate",
			"Key2LootCrate",
			"DuffleLootCrate",
			"DuffleLootCrate_HighTier",
			"DuffleLootCrate_Livonia",
			"DuffleLootCrate_HighTier_Livonia",
			"MedicLootCrate",
			"BlackLootCrate",
			"ToxicLootCrate",
			"BlueVestsLootCrate",
			"BlueHelmetsLootCrate",
			"BlueKeycardVestsLootCrate",
			"BlueKeycardHelmetsLootCrate",
			"GreenKeycardVestsLootCrate",
			"GreenKeycardHelmetsLootCrate",
			"YellowVestsLootCrate",
			"YellowHelmetsLootCrate",
			"YellowKeycardVestsLootCrate",
			"YellowKeycardHelmetsLootCrate",
			"PurpleVestsLootCrate",
			"PurpleHelmetsLootCrate",
			"PurpleKeycardVestsLootCrate",
			"PurpleKeycardHelmetsLootCrate",
			"RedVestsLootCrate",
			"RedHelmetsLootCrate",
			"BlackVestsLootCrate",
			"BlackHelmetsLootCrate",
			"ToxicVestsLootCrate",
			"ToxicHelmetsLootCrate",
			"PCLootCrate",
			"HelicrashLootCrate",
			"HelicrashLootCrate_Livonia",
			"HelicrashWeaponcrate",
			"BackpackLootCrate",
			"BackpackLootCrate_Livonia",
			"LootboxLootCrate",
			"LootboxLootCrate_Livonia",
			"ToolboxLootCrate",
			"ToolboxLootCrate_Livonia",
			"MilitaryItemCrate",
			"MilitaryHighTierItemCrate",
			"MilitaryItemCrate_Livonia",
			"MilitaryHighTierItemCrate_Livonia",
			"AirdropItemCrate",
			"AirdropItemCrateHighTier",
			"AirdropItemCrate_Livonia",
			"AirdropItemCrateHighTier_Livonia",
			"StaticWeaponcrate",
			"BriefcaseLootCrate",
			"BriefcaseLootCrate_Livonia",
			"AmmoCrateLootCrate",
			"AmmoCrateLootCrate_Livonia",
			"WoodenCrateLootCrate",
			"WoodenCrateLootCrate_Livonia",
			"SuitcaseLootCrate",
			"SuitcaseLootCrate_Livonia",
			"FileCabinetLootCrate",
			"FileCabinetLootCrate_Livonia"
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
	/* class Container_Base;
	class ZLandContainerBase: Container_Base */
	class LB_LC_Base;
	class ZLandContainerBase: LB_LC_Base
	{
		scope=0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1000000;
				};
			};
		};
	};
	class ZLandLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Gun Case";
		model="ZLCrates\LootCrate\GunCase.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=0.85000002;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,4};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
	};
	class BlueLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Gun Locker";
		model="ZLCrates\LootCrate\LockerLootCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,4};
			allowOwnedCargoManipulation=1;
		};
	};
	class BlueKeycardLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Gun Case";
		model="ZLCrates\LootCrate\GunCase.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,4};
			allowOwnedCargoManipulation=1;
		};
	};
	class GreenLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Building Supplies Crate";
		model="ZLCrates\LootCrate\ArmorCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,15};
			allowOwnedCargoManipulation=1;
		};
	};
	class GreenKeycardLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Gun Case";
		model="ZLCrates\LootCrate\GunCase.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,4};
			allowOwnedCargoManipulation=1;
		};
	};
	class YellowLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Gun Case";
		model="ZLCrates\LootCrate\GunCase.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,4};
			allowOwnedCargoManipulation=1;
		};
	};
	class YellowKeycardLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Gun Case";
		model="ZLCrates\LootCrate\GunCase.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,4};
			allowOwnedCargoManipulation=1;
		};
	};
	class PurpleLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Gun Case";
		model="ZLCrates\LootCrate\GunCase.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,4};
			allowOwnedCargoManipulation=1;
		};
	};
	class PurpleKeycardLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Gun Case";
		model="ZLCrates\LootCrate\GunCase.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,4};
			allowOwnedCargoManipulation=1;
		};
	};
	class Key1LootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Gun Case";
		model="ZLCrates\LootCrate\GunCase.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,4};
			allowOwnedCargoManipulation=1;
		};
	};
	class Key2LootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Gun Locker";
		model="ZLCrates\LootCrate\LockerLootCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,4};
			allowOwnedCargoManipulation=1;
		};
	};
	class DuffleLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Duffle Crate";
		model="ZLCrates\LootCrate\DuffleBag.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={5,5};
			allowOwnedCargoManipulation=1;
		};
	};
	class DuffleLootCrate_HighTier: ZLandContainerBase
	{
		scope=2;
		displayName="Duffle Crate";
		model="ZLCrates\LootCrate\DuffleBag.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={5,5};
			allowOwnedCargoManipulation=1;
		};
	};
	class DuffleLootCrate_Livonia: ZLandContainerBase
	{
		scope=2;
		displayName="Duffle Crate";
		model="ZLCrates\LootCrate\DuffleBag.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={5,5};
			allowOwnedCargoManipulation=1;
		};
	};
	class DuffleLootCrate_HighTier_Livonia: ZLandContainerBase
	{
		scope=2;
		displayName="Duffle Crate";
		model="ZLCrates\LootCrate\DuffleBag.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={5,5};
			allowOwnedCargoManipulation=1;
		};
	};
	class MedicLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Medical Crate";
		model="ZLCrates\LootCrate\MedicalDuffleBag.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={5,5};
			allowOwnedCargoManipulation=1;
		};
	};
	class BlackLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Gun Case";
		model="ZLCrates\LootCrate\GunCase.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,4};
			allowOwnedCargoManipulation=1;
		};
	};
	class ToxicLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Gun Case";
		model="ZLCrates\LootCrate\GunCase.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,4};
			allowOwnedCargoManipulation=1;
		};
	};
	class BlueVestsLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Armour Crate";
		model="ZLCrates\LootCrate\LootCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={6,6};
			allowOwnedCargoManipulation=1;
		};
	};
	class BlueHelmetsLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Helmet Crate";
		model="ZLCrates\LootCrate\LootCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={4,4};
			allowOwnedCargoManipulation=1;
		};
	};
	class BlueKeycardVestsLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Armour Crate";
		model="ZLCrates\LootCrate\LootCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={6,6};
			allowOwnedCargoManipulation=1;
		};
	};
	class BlueKeycardHelmetsLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Helmet Crate";
		model="ZLCrates\LootCrate\LootCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={4,4};
			allowOwnedCargoManipulation=1;
		};
	};
	class GreenKeycardVestsLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Armour Crate";
		model="ZLCrates\LootCrate\LootCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={6,6};
			allowOwnedCargoManipulation=1;
		};
	};
	class GreenKeycardHelmetsLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Helmet Crate";
		model="ZLCrates\LootCrate\LootCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={4,4};
			allowOwnedCargoManipulation=1;
		};
	};
	class YellowVestsLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Armour Crate";
		model="ZLCrates\LootCrate\LootCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={6,6};
			allowOwnedCargoManipulation=1;
		};
	};
	class YellowHelmetsLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Helmet Crate";
		model="ZLCrates\LootCrate\LootCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={4,4};
			allowOwnedCargoManipulation=1;
		};
	};
	class YellowKeycardVestsLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Armour Crate";
		model="ZLCrates\LootCrate\LootCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={6,6};
			allowOwnedCargoManipulation=1;
		};
	};
	class YellowKeycardHelmetsLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Helmet Crate";
		model="ZLCrates\LootCrate\LootCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={4,4};
			allowOwnedCargoManipulation=1;
		};
	};
	class PurpleVestsLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Armour Crate";
		model="ZLCrates\LootCrate\LootCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={6,6};
			allowOwnedCargoManipulation=1;
		};
	};
	class PurpleHelmetsLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Helmet Crate";
		model="ZLCrates\LootCrate\LootCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={4,4};
			allowOwnedCargoManipulation=1;
		};
	};
	class PurpleKeycardVestsLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Armour Crate";
		model="ZLCrates\LootCrate\LootCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={6,6};
			allowOwnedCargoManipulation=1;
		};
	};
	class PurpleKeycardHelmetsLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Helmet Crate";
		model="ZLCrates\LootCrate\LootCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={4,4};
			allowOwnedCargoManipulation=1;
		};
	};
	class RedVestsLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Armour Crate";
		model="ZLCrates\LootCrate\LootCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={6,6};
			allowOwnedCargoManipulation=1;
		};
	};
	class RedHelmetsLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Helmet Crate";
		model="ZLCrates\LootCrate\LootCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={4,4};
			allowOwnedCargoManipulation=1;
		};
	};
	class BlackVestsLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Armour Crate";
		model="ZLCrates\LootCrate\LootCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={6,6};
			allowOwnedCargoManipulation=1;
		};
	};
	class BlackHelmetsLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Helmet Crate";
		model="ZLCrates\LootCrate\LootCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={4,4};
			allowOwnedCargoManipulation=1;
		};
	};
	class ToxicVestsLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Armour Crate";
		model="ZLCrates\LootCrate\LootCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={6,6};
			allowOwnedCargoManipulation=1;
		};
	};
	class ToxicHelmetsLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Helmet Crate";
		model="ZLCrates\LootCrate\LootCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={4,4};
			allowOwnedCargoManipulation=1;
		};
	};
	class PCLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Lootable PC";
		model="ZLCrates\LootCrate\PC.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=0.85000002;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={4,4};
			allowOwnedCargoManipulation=1;
		};
	};
	class HelicrashLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Loot Crate";
		model="ZLCrates\LootCrate\LootCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=0.85000002;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,10};
			allowOwnedCargoManipulation=1;
		};
	};
	class HelicrashLootCrate_Livonia: ZLandContainerBase
	{
		scope=2;
		displayName="Loot Crate";
		model="ZLCrates\LootCrate\LootCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=0.85000002;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,10};
			allowOwnedCargoManipulation=1;
		};
	};
	class HelicrashWeaponcrate: ZLandContainerBase
	{
		scope=2;
		displayName="Gun Case";
		model="ZLCrates\LootCrate\GunCase.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=0.85000002;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,4};
			allowOwnedCargoManipulation=1;
		};
	};
	class BackpackLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Lootable Backpack";
		model="FOG_MOD\Gear\Bags\Trizip\models\Trizip_g.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=0.85000002;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,10};
			allowOwnedCargoManipulation=1;
		};
	};
	class BackpackLootCrate_Livonia: ZLandContainerBase
	{
		scope=2;
		displayName="Lootable Backpack";
		model="FOG_MOD\Gear\Bags\Trizip\models\Trizip_g.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=0.85000002;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,10};
			allowOwnedCargoManipulation=1;
		};
	};
	class LootboxLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Openable Crate";
		model="ZLCrates\LootCrate\LootBox.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,10};
			allowOwnedCargoManipulation=1;
		};
	};
	class LootboxLootCrate_Livonia: ZLandContainerBase
	{
		scope=2;
		displayName="Openable Crate";
		model="ZLCrates\LootCrate\LootBox.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,10};
			allowOwnedCargoManipulation=1;
		};
	};
	class ToolboxLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Openable Tool Box";
		model="ZLCrates\LootCrate\Toolbox.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,10};
			allowOwnedCargoManipulation=1;
		};
	};
	class ToolboxLootCrate_Livonia: ZLandContainerBase
	{
		scope=2;
		displayName="Openable Tool Box";
		model="ZLCrates\LootCrate\Toolbox.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,10};
			allowOwnedCargoManipulation=1;
		};
	};
	class MilitaryItemCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Item Crate";
		model="ZLCrates\LootCrate\MilitaryItemCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={6,6};
			allowOwnedCargoManipulation=1;
		};
	};
	class MilitaryHighTierItemCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Item Crate";
		model="ZLCrates\LootCrate\MilitaryItemCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={6,6};
			allowOwnedCargoManipulation=1;
		};
	};
	class MilitaryItemCrate_Livonia: ZLandContainerBase
	{
		scope=2;
		displayName="Item Crate";
		model="ZLCrates\LootCrate\MilitaryItemCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={6,6};
			allowOwnedCargoManipulation=1;
		};
	};
	class MilitaryHighTierItemCrate_Livonia: ZLandContainerBase
	{
		scope=2;
		displayName="Item Crate";
		model="ZLCrates\LootCrate\MilitaryItemCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={6,6};
			allowOwnedCargoManipulation=1;
		};
	};
	class AirdropItemCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Military Item Crate";
		model="ZLCrates\LootCrate\Airdrop.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,100};
			allowOwnedCargoManipulation=1;
		};
	};
	class AirdropItemCrateHighTier: ZLandContainerBase
	{
		scope=2;
		displayName="Military Item Crate";
		model="ZLCrates\LootCrate\Airdrop.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,100};
			allowOwnedCargoManipulation=1;
		};
	};
	class AirdropItemCrate_Livonia: ZLandContainerBase
	{
		scope=2;
		displayName="Military Item Crate";
		model="ZLCrates\LootCrate\Airdrop.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,100};
			allowOwnedCargoManipulation=1;
		};
	};
	class AirdropItemCrateHighTier_Livonia: ZLandContainerBase
	{
		scope=2;
		displayName="Military Item Crate";
		model="ZLCrates\LootCrate\Airdrop.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,100};
			allowOwnedCargoManipulation=1;
		};
	};
	class StaticWeaponcrate: ZLandContainerBase
	{
		scope=2;
		displayName="Gun Case";
		model="ZLCrates\LootCrate\GunCase.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=0.85000002;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,4};
			allowOwnedCargoManipulation=1;
		};
	};
	class BriefcaseLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Briefcase";
		model="ZLCrates\LootCrate\BriefCase.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=0.85000002;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={5,5};
			allowOwnedCargoManipulation=1;
		};
	};
	class BriefcaseLootCrate_Livonia: ZLandContainerBase
	{
		scope=2;
		displayName="Briefcase";
		model="ZLCrates\LootCrate\BriefCase.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=0.85000002;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={5,5};
			allowOwnedCargoManipulation=1;
		};
	};
	class AmmoCrateLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Ammo Crate";
		model="ZLCrates\LootCrate\AmmoCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=0.85000002;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={5,5};
			allowOwnedCargoManipulation=1;
		};
	};
	class AmmoCrateLootCrate_Livonia: ZLandContainerBase
	{
		scope=2;
		displayName="Ammo Crate";
		model="ZLCrates\LootCrate\AmmoCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=0.85000002;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={5,5};
			allowOwnedCargoManipulation=1;
		};
	};
	class WoodenCrateLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Item Crate";
		model="ZLCrates\LootCrate\WoodenCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=0.85000002;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,10};
			allowOwnedCargoManipulation=1;
		};
	};
	class WoodenCrateLootCrate_Livonia: ZLandContainerBase
	{
		scope=2;
		displayName="Item Crate";
		model="ZLCrates\LootCrate\WoodenCrate.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=0.85000002;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,10};
			allowOwnedCargoManipulation=1;
		};
	};
	class SuitcaseLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="Suitcase";
		model="ZLCrates\LootCrate\Suitcase.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=0.85000002;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,10};
			allowOwnedCargoManipulation=1;
		};
	};
	class SuitcaseLootCrate_Livonia: ZLandContainerBase
	{
		scope=2;
		displayName="Suitcase";
		model="ZLCrates\LootCrate\Suitcase.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=0.85000002;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,10};
			allowOwnedCargoManipulation=1;
		};
	};
	class FileCabinetLootCrate: ZLandContainerBase
	{
		scope=2;
		displayName="File Cabinet";
		model="ZLCrates\LootCrate\FileCabinat.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=0.85000002;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,10};
			allowOwnedCargoManipulation=1;
		};
	};
	class FileCabinetLootCrate_Livonia: ZLandContainerBase
	{
		scope=2;
		displayName="File Cabinet";
		model="ZLCrates\LootCrate\FileCabinat.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=0.85000002;
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,10};
			allowOwnedCargoManipulation=1;
		};
	};
};

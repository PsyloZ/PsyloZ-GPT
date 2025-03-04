class BriefcaseLootCrate: ZLandContainerBase
{
	override void RegisterLootTable(array<ref ZLandLootEntry> loot_table) 
	{
		super.RegisterLootTable(loot_table);
		
		loot_table.Insert(new ZLandLootEntry({"EFT_Bolts", "EFT_BulbexCablecutter", "EFT_Cloth_Cordura", "EFT_Cloth_Ripstop", "EFT_Drill", "EFT_GasAnalyzer", "EFT_InjectorCase", "EFT_KeycardHolder", "EFT_Keytool", "EFT_Lion", "EFT_MS2000", "EFT_Nuts", "EFT_Rolex", "EFT_Rooster", "EFT_Teapot", "EFT_Toolset", "EFT_WeaponParts", "EFT_Whiskey"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"Collectable_RetroToy", "Collectable_TetrisToy", "Collectable_USB", "Collectable_RAM", "Collectable_FloppyDisks_1999", "Collectable_SSD", "Collectable_SSDV2", "Collectable_SmartPhone_Black", "Collectable_MemoryCard", "CPB_AquaFPS", "CPB_Cat"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"ammobox_00buck_10rnd", "ammobox_12gaslug_10rnd", "ammobox_12garubberslug_10rnd", "ammobox_22_50rnd", "ammobox_308win_20rnd", "ammobox_380_35rnd", "ammobox_45acp_25rnd", "ammobox_545x39_20rnd", "ammobox_556x45_20rnd", "ammobox_762x39_20rnd", "ammobox_762x54_20rnd", "ammobox_9x19_25rnd", "ammobox_9x39_20rnd", "ammobox_9x39ap_20rnd", "ZLand_AmmoBox_50BMGSlug"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"CP_CannabisSeedsPackStardawg", "CP_CannabisSeedsPackKush", "CP_CannabisSeedsPackBlue", "CP_CannabisSeedsPackSkunk", "CP_CannabisSeedsPackFuture", "CP_CannabisSeedsPackS1", "CP_CannabisSeedsPackNomad", "CP_CannabisSeedsPackBlackFrost", "DP_CocaSeedsPack"}, 0.1));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"Keycard_Blue", "Keycard_Green", "Keycard_Yellow", "Keycard_Purple", "Keycard_Red"}, 0.01));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand_Key_Red", "ZLand_Key_Red2", "ZLand_Key_Red3", "ZLand_Key_Green", "ZLand_Key_Green2", "ZLand_Key_Green3", "ZLand_Key_Green4", "ZLand_Key_Green5", "ZLand_Key_Blue", "ZLand_Key_Blue2", "ZLand_Key_Blue3", "ZLand_Key_Blue4", "ZLand_Key_Blue5", "ZLand_Key_Yellow", "ZLand_Key_Yellow2", "ZLand_Key_Yellow3", "ZLand_Key_Yellow4", "ZLand_Key_Yellow5", "ZLand_Key_Purple", "ZLand_Key_Purple2", "ZLand_Key_Purple3", "ZLand_Key_Purple4", "ZLand_Key_Purple5", "CJ_Key103", "CJ_Key101"}, 0.1));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"ZLANDBandage", "ZLAND_Salewa", "AI2_Orange", "ZLand_Stimpack", "ZLand_Blood_Stimpack", "ZLAND_GoldenStar"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"ZLAND_SprayPaint_Black", "ZLAND_SprayPaint_Green"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"HDSN_Charcoal", "HDSN_Sulfur"}, 0.01));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
	}
	
	override int GetMinLoot()
	{
		return 3;
	}
	
	override int GetMaxLoot()
	{
		return 3;
	}
		
	override float GetRestockTimer()
	{
		return 60.0 * 240.0; // 2 hours default
	}
	override void SoundOpenPlay()
	{
		EffectSound sound =	SEffectManager.PlaySound( "armorcrateOpen_SoundSet", GetPosition() );
		sound.SetSoundAutodestroy( true );
	}
}
class BriefcaseLootCrate_Livonia: ZLandContainerBase
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
		loot_table.Insert(new ZLandLootEntry({"Keycard_Blue_Livonia", "Keycard_Green_Livonia", "Keycard_Yellow_Livonia", "Keycard_Purple_Livonia", "Keycard_Red_Livonia"}, 0.01));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"ZLAND_Key_Red_Livonia","ZLAND_Key_Red2_Livonia","ZLAND_Key_Red3_Livonia","ZLAND_Key_Blue_Livonia","ZLAND_Key_Blue2_Livonia","ZLAND_Key_Blue3_Livonia","ZLAND_Key_Blue4_Livonia","ZLAND_Key_Blue5_Livonia","ZLAND_Key_Yellow_Livonia","ZLAND_Key_Yellow2_Livonia","ZLAND_Key_Yellow3_Livonia","ZLAND_Key_Yellow4_Livonia","ZLAND_Key_Yellow5_Livonia","ZLAND_Key_Green_Livonia","ZLAND_Key_Green2_Livonia","ZLAND_Key_Green3_Livonia","ZLAND_Key_Green4_Livonia","ZLAND_Key_Green5_Livonia","ZLAND_Key_Purple_Livonia","ZLAND_Key_Purple2_Livonia","ZLAND_Key_Purple3_Livonia","ZLAND_Key_Purple4_Livonia","ZLAND_Key_Purple5_Livonia","ZLAND_ArmoryKey_Livonia"}, 0.1));
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
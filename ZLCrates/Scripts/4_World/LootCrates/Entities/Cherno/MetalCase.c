class RA_Static_MetalBoxStash: ZLandContainerBase
{
	override void RegisterLootTable(array<ref ZLandLootEntry> loot_table) 
	{
		super.RegisterLootTable(loot_table);
		
		loot_table.Insert(new ZLandLootEntry({"bandage","SalineBag"}, 1.0));
        loot_table.Insert(new ZLandLootEntry({"Collectable_USB", "Collectable_RAM", "Collectable_FloppyDisks_1999", "Collectable_SSD", "Collectable_SSDV2", "Collectable_MemoryCard","EFT_Bolts","EFT_Nuts"}, 1.0));
		loot_table.Insert(new ZLandLootEntry({"EFT_Bolts", "EFT_BulbexCablecutter", "EFT_Cloth_Cordura", "EFT_Cloth_Ripstop", "EFT_Drill", "EFT_GasAnalyzer", "EFT_InjectorCase", "EFT_KeycardHolder", "EFT_Keytool", "EFT_Lion", "EFT_MS2000", "EFT_Nuts", "EFT_Rolex", "EFT_Rooster", "EFT_Teapot", "EFT_Toolset", "EFT_WeaponParts", "EFT_Whiskey"}, 1.0));
		loot_table.Insert(new ZLandLootEntry({"ZLand_Key_Red", "ZLand_Key_Red2", "ZLand_Key_Red3", "ZLand_Key_Green", "ZLand_Key_Green2", "ZLand_Key_Green3", "ZLand_Key_Green4", "ZLand_Key_Green5", "ZLand_Key_Blue", "ZLand_Key_Blue2", "ZLand_Key_Blue3", "ZLand_Key_Blue4", "ZLand_Key_Blue5", "ZLand_Key_Yellow", "ZLand_Key_Yellow2", "ZLand_Key_Yellow3", "ZLand_Key_Yellow4", "ZLand_Key_Yellow5", "ZLand_Key_Purple", "ZLand_Key_Purple2", "ZLand_Key_Purple3", "ZLand_Key_Purple4", "ZLand_Key_Purple5", "CJ_Key103", "CJ_Key101"}, 0.1));
        loot_table.Insert(new ZLandLootEntry({"NailBox"}, 0.1));
        loot_table.Insert(new ZLandLootEntry({"screwdriver"}, 1.0));
	}
	override int GetMinLoot()
	{
		return 1;
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
		EffectSound sound =	SEffectManager.PlaySound( "toolbox_SoundSet", GetPosition() );
		sound.SetSoundAutodestroy( true );
	}
}
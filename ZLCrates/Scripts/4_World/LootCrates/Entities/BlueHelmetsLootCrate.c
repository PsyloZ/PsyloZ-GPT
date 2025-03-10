class BlueHelmetsLootCrate: ZLandContainerBase
{
	override void RegisterLootTable(array<ref ZLandLootEntry> loot_table) 
	{
		super.RegisterLootTable(loot_table);
		
		loot_table.Insert(new ZLandLootEntry({"ZLANDACHelmet_Black","ZLANDACHelmet_Olive","ZLANDKiver_Black","ZLANDKiver_Olive","ZLANDKiver_Tan","IMP_Helmet_Heavy_Dominator2_Green","IMP_Helmet_Heavy_Dominator2_Tan","IMP_Helmet_Mich_Skull","IMP_Helmet_SOBR_Green","IMP_Helmet_SOBR_Black","IMP_Helmet_SWAT","IMP_Helmet_PBR","IMP_Helmet_6B47T_Black","IMP_Helmet_ACHHC_Green","IMP_Helmet_ACHHC_Black","IMP_Helmet_Mich2001","IMP_Helmet_Mich2002","IMP_Helmet_Rys","IMP_Helmet_6b47_Cover_black","IMP_Helmet_6b47_Cover_green"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"IMP_Helmet_Altyn_Black","IMP_Helmet_Altyn_Green","IMP_Helmet_Altyn_Tan","IMP_Helmet_RoninMedium","IMP_Helmet_Mich_Black","IMP_Helmet_Mich_Green","IMP_Helmet_Tactic_Black","IMP_Helmet_Tactic_Green","IMP_Helmet_Tactic_Beige","IMP_Helmet_CryeAirframe_Black","IMP_Helmet_CryeAirframe","IMP_Helmet_CryeAirframe_Green","IMP_Helmet_6B47T_Black","PITSTOP_SOCOMHelmet_Camo","PITSTOP_SOCOMHelmet_Black"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
	}
	
	override int GetMinLoot()
	{
		return 1;
	}
	
	override int GetMaxLoot()
	{
		return 1;
	}
		
	override float GetRestockTimer()
	{
		return 60.0 * 240.0; // 2 hours default
	}
	override void SoundOpenPlay()
	{
		EffectSound sound =	SEffectManager.PlaySound( "militarycrateOpen_SoundSet", GetPosition() );
		sound.SetSoundAutodestroy( true );
	}
}
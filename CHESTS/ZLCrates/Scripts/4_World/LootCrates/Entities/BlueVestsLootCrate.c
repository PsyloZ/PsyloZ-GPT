class BlueVestsLootCrate: ZLandContainerBase
{
	override void RegisterLootTable(array<ref ZLandLootEntry> loot_table) 
	{
		super.RegisterLootTable(loot_table);
		
		loot_table.Insert(new ZLandLootEntry({"IMP_Vest_IOTVMini_Green","IMP_Vest_IOTVMini_Black","IMP_Vest_TacTec_Green","IMP_Vest_TacTec_Tan","IMP_Vest_6B13T_EMR","IMP_Vest_6B23T_Pixel","IMP_Vest_6h112_Green","IMP_Vest_BNTIKirasaN_Blue","IMP_Vest_Defender2","IMP_Vest_Hexgrid_Black","IMP_Vest_KorundVM_Black","IMP_Vest_Slick","IMP_Vest_TacTecT_Green","IMP_Vest_Trooper","IMP_Vest_UNVest_Blue","IMP_Vest_Zhuk","IMP_Vest_Zhuk6a","IMP_Vest_FBIVest_Green","IMP_Vest_MediumVest_Black","IMP_Vest_MediumVest_Green","IMP_Vest_MediumVest_Tan","ZLAND_CageVest_Black","ZLAND_CageVest_Green","ZLAND_CageVest_Tan"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"IMP_Vest_6B13_Black","IMP_Vest_6B13_Tan","IMP_Vest_6B13_Green","IMP_Vest_6B45_Black","IMP_Vest_6B45_Green","IMP_Vest_6b23_Black","IMP_Vest_6b23_Green","IMP_Vest_6b23_Tan","IMP_Vest_IOTV_Black","IMP_Vest_IOTV_Green","IMP_Vest_IOTV_Tan","IMP_Vest_Slick","IMP_Vest_TacTecT_Green","IMP_Vest_MTV_Black","IMP_Vest_MTV_Green","IMP_Vest_MTV_Tan","IMP_Vest_Redut_Black","IMP_Vest_Redut_Green","IMP_Vest_Gjel","IMP_Vest_AACVest_Black","IMP_Vest_AACVest_Green","IMP_Vest_AACVest_Tan","IMP_Vest_Defender_Black","IMP_Vest_Defender_Green","IMP_Vest_Defender_Tan","ZLAND_Cage_Black","ZLAND_Cage_Green","ZLAND_Cage_Tan","ZLAND_Emerson_Black","ZLAND_Emerson_Green","ZLAND_Emerson_Tan"}, 1.0));
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
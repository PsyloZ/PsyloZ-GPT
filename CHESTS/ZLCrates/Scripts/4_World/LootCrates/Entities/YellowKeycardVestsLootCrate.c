class YellowKeycardVestsLootCrate: ZLandContainerBase
{
	override void RegisterLootTable(array<ref ZLandLootEntry> loot_table) 
	{
		super.RegisterLootTable(loot_table);
		
		loot_table.Insert(new ZLandLootEntry({"IMP_Vest_6B43T_Black","IMP_Vest_6B43T_Green","IMP_Vest_6B43T_Tan","IMP_Vest_Gen4_Black","IMP_Vest_6B45_Green","IMP_Vest_Gen4_Tan","IMP_Vest_Thor_Black","IMP_Vest_Thor_Tan","IMP_Vest_Thor_Green","ZLAND_NavySealsVest_Black","ZLAND_NavySealsVest_Green","ZLAND_NavySealsVest_Tan"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"ZLANDLevel3JuggSuit_Black","ZLANDLevel3JuggSuit_Tan","ZLANDLevel3JuggSuit_Olive"}, 0.04));
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
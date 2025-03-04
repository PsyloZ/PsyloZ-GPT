class RA_Static_MedicalBox: ZLandContainerBase
{
	override void RegisterLootTable(array<ref ZLandLootEntry> loot_table) 
	{
		super.RegisterLootTable(loot_table);
		
		loot_table.Insert(new ZLandLootEntry({"AntiPestsSpray","sewingkit","leathersewingkit"}, 1.0));
		loot_table.Insert(new ZLandLootEntry({"SalineBag","BloodBagEmpty","BloodTestKit","StartKitIV","TetracyclineAntibiotics","Morphine","ZLANDBandage","VitaminBottle","Heatpack","CharcoalTablets"},0.8));
		loot_table.Insert(new ZLandLootEntry({"ZLAND_Salewa","AI2_Orange","ZLand_Stimpack","ZLand_Blood_Stimpack","ZLAND_GoldenStar"},0.4));

	}
	override int GetMinLoot()
	{
		return 1;
	}
	
	override int GetMaxLoot()
	{
		return 2;
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
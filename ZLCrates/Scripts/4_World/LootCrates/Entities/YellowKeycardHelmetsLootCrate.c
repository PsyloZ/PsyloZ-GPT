class YellowKeycardHelmetsLootCrate: ZLandContainerBase
{
	override void RegisterLootTable(array<ref ZLandLootEntry> loot_table) 
	{
		super.RegisterLootTable(loot_table);
		
		loot_table.Insert(new ZLandLootEntry({"IMP_Helmet_RoninHeavy_Black","IMP_Helmet_RoninHeavy_Green","ZLANDk6Helmet_Green","ZLANDk6Helmet_Black","IMP_Helmet_Silencer_Black","IMP_Helmet_Silencer_Green","ZLANDKSHHelmet_BlackKilla","ZLANDKSHHelmet_Black","ZLANDKSHHelmet_Green"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"ZLAND_Tagilla_WeldingMask","ZLAND_Tagilla_WeldingMask_Gorilla"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"ZLAND_Jugg_Helmet_Black","ZLAND_Jugg_Helmet_Green"}, 0.1));
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
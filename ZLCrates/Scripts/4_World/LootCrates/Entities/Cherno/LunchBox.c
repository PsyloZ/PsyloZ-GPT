class RA_Static_Lunchbox: ZLandContainerBase
{
	override void RegisterLootTable(array<ref ZLandLootEntry> loot_table) 
	{
		super.RegisterLootTable(loot_table);
		
		loot_table.Insert(new ZLandLootEntry({"sodacan_cola", "sodacan_kvass", "sodacan_pipsi", "sodacan_spite", "sodacan_fronta", "SodaCan_Budweiser", "SodaCan_Guiness", "SodaCan_Ironbru", "SodaCan_Sanmiguel", "SodaCan_Stella", "vodka", "waterbottle"}, 1.0));
		loot_table.Insert(new ZLandLootEntry({"crackers", "saltysticks", "rice", "spaghettican", "peachescan", "bakedbeanscan", "pajka", "pate", "zagorkychocolate", "tacticalbaconcan", "brisketspread", "catfoodcan", "dogfoodcan", "honey", "porkcan", "ZLAND_Doritos_Coolranch", "ZLAND_Doritos_Nachocheese"}, 1.0));

	}
	override int GetMinLoot()
	{
		return 2;
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
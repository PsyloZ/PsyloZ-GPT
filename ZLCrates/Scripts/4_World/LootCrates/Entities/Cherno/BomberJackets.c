class RA_Static_BomberJacket: ZLandContainerBase
{
	override void RegisterLootTable(array<ref ZLandLootEntry> loot_table) 
	{
		super.RegisterLootTable(loot_table);
		
		loot_table.Insert(new ZLandLootEntry({"Collectable_RetroToy", "Collectable_TetrisToy", "Collectable_USB", "Collectable_RAM", "Collectable_FloppyDisks_1999", "Collectable_SSD", "Collectable_SSDV2", "Collectable_SmartPhone_Black", "Collectable_MemoryCard", "CPB_AquaFPS", "CPB_Cat"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLand"}, 0, {
				new ZLandLootEntry({"ZLand"}),
			}),
        }));
        loot_table.Insert(new ZLandLootEntry({"Keycard_Blue", "Keycard_Green", "Keycard_Yellow", "Keycard_Purple", "Keycard_Red"}, 0.01));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLand"}, 0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
        loot_table.Insert(new ZLandLootEntry({"ZLand_Key_Red", "ZLand_Key_Red2", "ZLand_Key_Red3", "ZLand_Key_Green", "ZLand_Key_Green2", "ZLand_Key_Green3", "ZLand_Key_Green4", "ZLand_Key_Green5", "ZLand_Key_Blue", "ZLand_Key_Blue2", "ZLand_Key_Blue3", "ZLand_Key_Blue4", "ZLand_Key_Blue5", "ZLand_Key_Yellow", "ZLand_Key_Yellow2", "ZLand_Key_Yellow3", "ZLand_Key_Yellow4", "ZLand_Key_Yellow5", "ZLand_Key_Purple", "ZLand_Key_Purple2", "ZLand_Key_Purple3", "ZLand_Key_Purple4", "ZLand_Key_Purple5", "CJ_Key103", "CJ_Key101"}, 0.1));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLand"}, 0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
        		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"mkii"}, 0.1, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"Mag_MKII_10Rnd"}, 1.0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"makarovij70"}, 0.1, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"Mag_IJ70_8Rnd"}, 1.0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"cz75"}, 0.1, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"Mag_CZ75_15Rnd"}, 1.0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"fnx45"}, 0.1, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"Mag_FNX45_15Rnd"}, 1.0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"glock19"}, 0.1, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"Mag_Glock_15Rnd"}, 1.0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"colt1911"}, 0.1, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"Mag_1911_7Rnd"}, 1.0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"engraved1911"}, 0.1, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"Mag_1911_7Rnd"}, 1.0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"PITSTOP_FiveSeven_Tan"}, 0.1, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"PITSTOP_FiveSeven_Magazine"}, 1.0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"PITSTOP_Glock18"}, 0.1, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"PITSTOP_Glock18_Magazine"}, 1.0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"Derringer_Black"}, 0.1, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"Ammo_357"}, 0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"Magnum"}, 0.1, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"Ammo_357"}, 1.0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"LongHorn"}, 0.1, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"Ammo_308"}, 1.0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"Deagle"}, 0.1, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"Mag_Deagle_9rnd"}, 1.0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
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
class RA_Static_BomberJacket_2: RA_Static_BomberJacket{}
class RA_Static_FireFighterJacket_2: RA_Static_BomberJacket{}
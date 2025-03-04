class RA_Static_Briefcase: ZLandContainerBase
{
	override void RegisterLootTable(array<ref ZLandLootEntry> loot_table) 
	{
		super.RegisterLootTable(loot_table);
		
		loot_table.Insert(new ZLandLootEntry({"CP_CannabisSeedsPackStardawg", "CP_CannabisSeedsPackKush", "CP_CannabisSeedsPackBlue", "CP_CannabisSeedsPackSkunk", "CP_CannabisSeedsPackFuture", "CP_CannabisSeedsPackS1", "CP_CannabisSeedsPackNomad", "CP_CannabisSeedsPackBlackFrost", "DP_CocaSeedsPack"}, 0.2));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLand"}, 0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"Collectable_RetroToy", "Collectable_TetrisToy", "Collectable_USB", "Collectable_RAM", "Collectable_FloppyDisks_1999", "Collectable_SSD", "Collectable_SSDV2", "Collectable_SmartPhone_Black", "Collectable_MemoryCard", "CPB_AquaFPS", "CPB_Cat"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLand"}, 0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"EFT_Bolts", "EFT_BulbexCablecutter", "EFT_Cloth_Cordura", "EFT_Cloth_Ripstop", "EFT_Drill", "EFT_GasAnalyzer", "EFT_InjectorCase", "EFT_KeycardHolder", "EFT_Keytool", "EFT_Lion", "EFT_MS2000", "EFT_Nuts", "EFT_Rolex", "EFT_Rooster", "EFT_Teapot", "EFT_Toolset", "EFT_WeaponParts", "EFT_Whiskey", "EFT_Sugar"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLand"}, 0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"CPB_GPU","Collectable_CrossNecklace", "Collectable_PocketWatch", "Collectable_Bitcoin", "Collectable_Intel", "CPB_GPCoin", "CPB_LEDX"}, 0.1));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLand"}, 0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLAND_MiningLaptop","ZLAND_NVME","ZLAND_Powerbank"}, 0.3));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLand"}, 0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"HDSN_Charcoal"}, 0.1));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLand"}, 0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"HDSN_Sulfur"}, 0.1));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLand"}, 0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"HDSN_Detonator"}, 0.1));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLand"}, 0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"HDSN_C4Stick"}, 0.1));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLand"}, 0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"HDSN_Gunpowder"}, 0.1));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLand"}, 0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"Grenade_ChemGas"}, 0.1));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLand"}, 0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLAND_RaidHacksaw"}, 0.1));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLand"}, 0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"CJ_Key103"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLand"}, 0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"CJ_Key101"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLand"}, 0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"CP_Bagger"}, 0.25));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLand"}, 0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"CP_PlasticWrapper"}, 0.25));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLand"}, 0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLAND_Key_Red","ZLAND_Key_Red2","ZLAND_Key_Red3","ZLAND_Key_Blue","ZLAND_Key_Blue2","ZLAND_Key_Blue3","ZLAND_Key_Blue4","ZLAND_Key_Blue5","ZLAND_Key_Yellow","ZLAND_Key_Yellow2","ZLAND_Key_Yellow3","ZLAND_Key_Yellow4","ZLAND_Key_Yellow5","ZLAND_Key_Green","ZLAND_Key_Green2","ZLAND_Key_Green3","ZLAND_Key_Green4","ZLAND_Key_Green5","ZLAND_Key_Purple","ZLAND_Key_Purple2","ZLAND_Key_Purple3","ZLAND_Key_Purple4","ZLAND_Key_Purple5","ZLAND_ArmoryKey"}, 0.1));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLand"}, 0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand_RedRoomArmoryKey"}, 0.25));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLand"}, 0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLAND_WorkBench_TableSaw"}, 0.1));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLand"}, 0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLAND_WorkBench_Grinder"}, 0.1));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLand"}, 0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLAND_WorkBench_Kit"}, 0.1));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLand"}, 0, {
				new ZLandLootEntry({"ZLand"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"Syringe"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLand"}, 0, {
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
		EffectSound sound =	SEffectManager.PlaySound( "zipper_SoundSet", GetPosition() );
		sound.SetSoundAutodestroy( true );
	}
}
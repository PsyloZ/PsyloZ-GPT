class AirdropItemCrate_Livonia: ZLandContainerBase
{
	override void RegisterLootTable(array<ref ZLandLootEntry> loot_table) 
	{
		super.RegisterLootTable(loot_table);
		
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"IMP_AKM"}, 1.0, {
			new ZLandLootEntry({"AK_FoldingBttstck"}),
			new ZLandLootEntry({"AK_RailHndgrd"}),
			new ZLandLootWithAttachments({"Mag_AKM_30Rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"IMP_AK74"}, 1.0, {
			new ZLandLootEntry({"AK_FoldingBttstck"}),
			new ZLandLootEntry({"AK_RailHndgrd"}),
			new ZLandLootWithAttachments({"Mag_AK74_30Rnd_Black"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"SV98"}, 1.0, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_CombatGrip","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"Mag_SV98_10Rnd"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_AKS74U"}, 1.0, {
			new ZLandLootEntry({"ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"IMP_RailAK"}),
			new ZLandLootWithAttachments({"Mag_AK74_30Rnd_Black"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"IMP_AR15"}, 1.0, {
			new ZLandLootEntry({"M4_OEBttstck","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"M4_RISHndgrd","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"Mag_CMAG_40Rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_ScarL"}, 1.0, {
			new ZLandLootEntry({"ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"Mag_CMAG_40Rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_SVD"}, 1.0, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"ZLand_SVD_Magazine"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_AUG"}, 1.0, {
			new ZLandLootEntry({"ZLand_DeltaPoint"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"Mag_STANAGCoupled_30Rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_X95"}, 1.0, {
			new ZLandLootEntry({"ZLand_DeltaPoint"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"Mag_STANAGCoupled_30Rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_F2000"}, 1.0, {
			new ZLandLootEntry({"ZLand_VortexAMG_UH1_Optic","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"Mag_CMAG_40Rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_MK47"}, 1.0, {
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"M4_CQBBttstk"}),
			new ZLandLootWithAttachments({"ZLand_MK47_Magazine"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_DMR"}, 1.0, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"ZLand_DMR_Mag_20rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_HKG28"}, 1.0, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"ZLand_Mag_HKG28_20rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_MP7A1"}, 1.0, {
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"VTR_Bravo4"}),
			new ZLandLootWithAttachments({"ZLand_MP7A1_Mag_50Rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_MP7A2"}, 1.0, {
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"VTR_Bravo4"}),
			new ZLandLootWithAttachments({"ZLand_MP7A1_Mag_50Rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"IMP_McMillan_CS5"}, 1.0, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"IMP_Mag_McMillan_CS5_10Rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_SR25"}, 1.0, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_CombatGrip","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"ZLand_PMAG_GEN3_Mag"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"Connor_AR15"}, 1.0, {
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"ZLand_CombatGrip","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"Connor_AR15_Magazine"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"IMP_M39EMR"}, 1.0, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"IMP_Mag_M39EMR_20Rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_ASVAL"}, 1.0, {
			new ZLandLootEntry({"ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"ZLand_CombatGrip","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"ZLand_ASVAL_Magazine_Dual"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_RSASS_Tan"}, 1.0, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_CombatGrip","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"ZLand_PMAG_GEN3_Mag"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_Honeybadger_Tan"}, 1.0, {
			new ZLandLootEntry({"VTR_Bravo4","Battery9V"}),
			new ZLandLootEntry({"ZLand_CombatGrip","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"ZLand_Honeybadger_Mag_30Rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_RPK16"}, 1.0, {
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"ZLand_CombatGrip","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"ZLand_RPK16_Drum"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"PITSTOP_AA12_Black"}, 1.0, {
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootWithAttachments({"PITSTOP_AA12_Magazine"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_MDR308"}, 1.0, {
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootWithAttachments({"ZLand_PMAG_GEN3_Mag"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_RD704"}, 1.0, {
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootWithAttachments({"ZLand_RD704_Magazine"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"Connor_M110"}, 0.1, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"Connor_M110_Magazine"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"Connor_CZ805"}, 1.0, {
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"ZLand_CombatGrip","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"Connor_CZ805_Magazine"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"IMP_Helmet_RoninHeavy_Black","IMP_Helmet_RoninHeavy_Green","ZLANDk6Helmet_Green","ZLANDk6Helmet_Black","IMP_Helmet_Silencer_Black","IMP_Helmet_Silencer_Green","ZLANDKSHHelmet_BlackKilla","ZLANDKSHHelmet_Black","ZLANDKSHHelmet_Green"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"ZLAND_Tagilla_WeldingMask","ZLAND_Tagilla_WeldingMask_Gorilla"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"ZLAND_Jugg_Helmet_Black","ZLAND_Jugg_Helmet_Green"}, 0.25));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"IMP_Vest_6B43T_Black","IMP_Vest_6B43T_Green","IMP_Vest_6B43T_Tan","IMP_Vest_Gen4_Black","IMP_Vest_6B45_Green","IMP_Vest_Gen4_Tan","IMP_Vest_Thor_Black","IMP_Vest_Thor_Tan","IMP_Vest_Thor_Green","ZLAND_NavySealsVest_Black","ZLAND_NavySealsVest_Green","ZLAND_NavySealsVest_Tan"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"ZLANDLevel3JuggSuit_Black","ZLANDLevel3JuggSuit_Tan","ZLANDLevel3JuggSuit_Olive"}, 0.01));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"CP_CannabisSeedsPackStardawg", "CP_CannabisSeedsPackKush", "CP_CannabisSeedsPackBlue", "CP_CannabisSeedsPackSkunk", "CP_CannabisSeedsPackFuture", "CP_CannabisSeedsPackS1", "CP_CannabisSeedsPackNomad", "CP_CannabisSeedsPackBlackFrost", "DP_CocaSeedsPack"}, 0.5));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"Collectable_RetroToy", "Collectable_TetrisToy", "Collectable_USB", "Collectable_RAM", "Collectable_FloppyDisks_1999", "Collectable_SSD", "Collectable_SSDV2", "Collectable_SmartPhone_Black", "Collectable_MemoryCard", "CPB_AquaFPS", "CPB_Cat"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"CPB_GPU","Collectable_CrossNecklace", "Collectable_PocketWatch", "Collectable_Bitcoin", "Collectable_Intel", "CPB_GPCoin", "CPB_LEDX"}, 0.3));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"EFT_Bolts", "EFT_BulbexCablecutter", "EFT_Cloth_Cordura", "EFT_Cloth_Ripstop", "EFT_Drill", "EFT_GasAnalyzer", "EFT_InjectorCase", "EFT_KeycardHolder", "EFT_Keytool", "EFT_Lion", "EFT_MS2000", "EFT_Nuts", "EFT_Rolex", "EFT_Rooster", "EFT_Teapot", "EFT_Toolset", "EFT_WeaponParts", "EFT_Whiskey", "EFT_Sugar"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"EFT_InjectorCase", "EFT_KeycardHolder", "EFT_Keytool", "ZLand_Wallet"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"ZLAND_MiningLaptop","ZLAND_NVME","ZLAND_Powerbank"}, 0.6));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"A6_Hacking_Tablet"}, 0.75));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"A6_TabletBattery"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"HDSN_Charcoal"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"HDSN_Sulfur"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"HDSN_Detonator"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"HDSN_C4Stick"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
	
		}));
		loot_table.Insert(new ZLandLootEntry({"HDSN_Gunpowder"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
	
		}));
		loot_table.Insert(new ZLandLootEntry({"Grenade_ChemGas"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
	
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLAND_RaidHacksaw"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
	
		}));
		loot_table.Insert(new ZLandLootEntry({"HDSN_BreachingCharge"}, 0.75));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
	
		}));
		loot_table.Insert(new ZLandLootEntry({"HDSN_BreachingChargeHeavy"}, 0.5));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
	
		}));
		loot_table.Insert(new ZLandLootEntry({"CJ_Key103"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
	
		}));
		loot_table.Insert(new ZLandLootEntry({"CJ_Key101"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
	
		}));
		loot_table.Insert(new ZLandLootEntry({"CP_Bagger"}, 0.5));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"CP_PlasticWrapper"}, 0.5));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
	
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLAND_WorkBench_TableSaw"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
	
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLAND_WorkBench_Grinder"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"ZLAND_WorkBench_Kit"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
	
		}));
		loot_table.Insert(new ZLandLootEntry({"Syringe"}, 0.25));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
	
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand_Ruby","ZLand_Saphire","ZLand_Diamond"}, 0.5));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
	
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLAND_Raid_Backpack_Black","ZLAND_Raid_Backpack_Green","ZLAND_Raid_Backpack_Olive","ZLAND_Raid_Backpack_Khaki"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
	
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand_RedRoomArmoryKey_Livonia"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
	
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLAND_Key_Red_Livonia","ZLAND_Key_Red2_Livonia","ZLAND_Key_Red3_Livonia","ZLAND_Key_Blue_Livonia","ZLAND_Key_Blue2_Livonia","ZLAND_Key_Blue3_Livonia","ZLAND_Key_Blue4_Livonia","ZLAND_Key_Blue5_Livonia","ZLAND_Key_Yellow_Livonia","ZLAND_Key_Yellow2_Livonia","ZLAND_Key_Yellow3_Livonia","ZLAND_Key_Yellow4_Livonia","ZLAND_Key_Yellow5_Livonia","ZLAND_Key_Green_Livonia","ZLAND_Key_Green2_Livonia","ZLAND_Key_Green3_Livonia","ZLAND_Key_Green4_Livonia","ZLAND_Key_Green5_Livonia","ZLAND_Key_Purple_Livonia","ZLAND_Key_Purple2_Livonia","ZLAND_Key_Purple3_Livonia","ZLAND_Key_Purple4_Livonia","ZLAND_Key_Purple5_Livonia","ZLAND_ArmoryKey_Livonia"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
	
		}));
		loot_table.Insert(new ZLandLootEntry({"Keycard_Livonia","Keycard_Blue_Livonia","Keycard_Green_Livonia","Keycard_Yellow_Livonia","Keycard_Purple_Livonia","Keycard_Red_Livonia","Keycard_Black_Livonia"}, 0.01));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
	
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand_Ruby","ZLand_Saphire","ZLand_Diamond"}, 0.01));
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
		EffectSound sound =	SEffectManager.PlaySound( "woodcrateOpen_SoundSet", GetPosition() );
		sound.SetSoundAutodestroy( true );
	}
}
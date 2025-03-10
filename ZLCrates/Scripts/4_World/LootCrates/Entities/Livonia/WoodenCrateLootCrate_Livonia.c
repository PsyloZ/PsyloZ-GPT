class WoodenCrateLootCrate_Livonia: ZLandContainerBase
{
	override void RegisterLootTable(array<ref ZLandLootEntry> loot_table) 
	{
		super.RegisterLootTable(loot_table);
		
		loot_table.Insert(new ZLandLootEntry({"EFT_Bolts", "EFT_BulbexCablecutter", "EFT_Cloth_Cordura", "EFT_Cloth_Ripstop", "EFT_Drill", "EFT_GasAnalyzer", "EFT_InjectorCase", "EFT_KeycardHolder", "EFT_Keytool", "EFT_Lion", "EFT_MS2000", "EFT_Nuts", "EFT_Rolex", "EFT_Rooster", "EFT_Teapot", "EFT_Toolset", "EFT_WeaponParts", "EFT_Whiskey"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"Collectable_RetroToy", "Collectable_TetrisToy", "Collectable_USB", "Collectable_RAM", "Collectable_FloppyDisks_1999", "Collectable_SSD", "Collectable_SSDV2", "Collectable_SmartPhone_Black", "Collectable_MemoryCard", "CPB_AquaFPS", "CPB_Cat"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"ZLAND_Key_Red_Livonia","ZLAND_Key_Red2_Livonia","ZLAND_Key_Red3_Livonia","ZLAND_Key_Blue_Livonia","ZLAND_Key_Blue2_Livonia","ZLAND_Key_Blue3_Livonia","ZLAND_Key_Blue4_Livonia","ZLAND_Key_Blue5_Livonia","ZLAND_Key_Yellow_Livonia","ZLAND_Key_Yellow2_Livonia","ZLAND_Key_Yellow3_Livonia","ZLAND_Key_Yellow4_Livonia","ZLAND_Key_Yellow5_Livonia","ZLAND_Key_Green_Livonia","ZLAND_Key_Green2_Livonia","ZLAND_Key_Green3_Livonia","ZLAND_Key_Green4_Livonia","ZLAND_Key_Green5_Livonia","ZLAND_Key_Purple_Livonia","ZLAND_Key_Purple2_Livonia","ZLAND_Key_Purple3_Livonia","ZLAND_Key_Purple4_Livonia","ZLAND_Key_Purple5_Livonia","ZLAND_ArmoryKey_Livonia","CJ_Key103", "CJ_Key101"}, 0.1));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
	
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLANDBandage", "ZLAND_Salewa", "AI2_Orange", "ZLand_Stimpack", "ZLand_Blood_Stimpack", "ZLAND_GoldenStar"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"ZLAND_SprayPaint_Black", "ZLAND_SprayPaint_Green", "ZLand_Shotgun_Suppressor", "NailBox", "CodeLock", "MetalPlate"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"LBS_SleepingPacked_New_Camo", "LBS_SleepingPacked_New_Blue", "LBS_SleepingPacked_New_Urban", "LBS_SleepingPacked_New_Green", "LBS_SleepingPacked_New_Orange", "LBS_SleepingPacked_New_Pink", "LBS_SleepingPacked_New_Red"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"IMP_Jacket_SWAT", "PITSTOP_LongCoat_Black", "PITSTOP_SOCOMJacket_BlackCamo", "ZLAND_MilitaryJacket_black", "ZLAND_MilitaryJacket_woodland", "PITSTOP_SOCOMPants_Black", "PITSTOP_SOCOMPants_GreenCamo", "PITSTOP_SpecOpsPants_Black", "PITSTOP_SpecOpsPants_Green", "IMP_Pants_Tactical_Black", "IMP_Pants_Tactical_Green", "GorkaShirt_Black", "GorkaShirt_Green"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"AmmoBox_338", "AmmoBox_408Chey", "AmmoBox_50Cal", "A6_Hacking_Tablet", "A6_TabletBattery", "ZLand_AmmoBox_277Fury"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_UMP45"}, 0.1, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLand_UMP45_Mag_25Rnd"}, 0.1, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_P90"}, 0.1, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLand_P90_50RndMag"}, 0.1, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"M16A2"}, 0.1, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"Mag_CMAG_30Rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"PITSTOP_M16"}, 0.1, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"Mag_CMAG_30Rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"IMP_AN94"}, 0.1, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"Mag_AK74_30Rnd_Black"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"Connor_AK12"}, 0.1, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"Mag_AK74_30Rnd_Black"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"PITSTOP_AEK971"}, 0.1, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"Mag_AK74_30Rnd_Black"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"IMP_AKM"}, 0.1, {
			new ZLandLootEntry({"AK_FoldingBttstck"}),
			new ZLandLootEntry({"AK_RailHndgrd"}),
			new ZLandLootWithAttachments({"Mag_AKM_30Rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"IMP_AK74"},0.1, {
			new ZLandLootEntry({"AK_FoldingBttstck"}),
			new ZLandLootEntry({"AK_RailHndgrd"}),
			new ZLandLootWithAttachments({"Mag_AK74_30Rnd_Black"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"IMP_AR15"}, 0.1, {
			new ZLandLootEntry({"M4_RISHndgrd_Black"}),
			new ZLandLootEntry({"M4_MPBttstck_Black"}),
			new ZLandLootWithAttachments({"Mag_CMAG_30Rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"SV98"}, 0.1, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_CombatGrip","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"Mag_SV98_10Rnd"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_AKS74U"}, 0.1, {
			new ZLandLootEntry({"ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"IMP_RailAK"}),
			new ZLandLootWithAttachments({"Mag_AK74_30Rnd_Black"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"IMP_AR15"}, 0.1, {
			new ZLandLootEntry({"M4_OEBttstck","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"M4_RISHndgrd","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"Mag_CMAG_40Rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_ScarL"}, 0.1, {
			new ZLandLootEntry({"ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"Mag_CMAG_40Rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_SVD"}, 0.1, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"ZLand_SVD_Magazine"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_AUG"}, 0.1, {
			new ZLandLootEntry({"ZLand_DeltaPoint"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"Mag_STANAGCoupled_30Rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_X95"}, 0.1, {
			new ZLandLootEntry({"ZLand_DeltaPoint"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"Mag_STANAGCoupled_30Rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_F2000"}, 0.1, {
			new ZLandLootEntry({"ZLand_VortexAMG_UH1_Optic","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"Mag_CMAG_40Rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_MK47"}, 0.1, {
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"M4_CQBBttstk"}),
			new ZLandLootWithAttachments({"ZLand_MK47_Magazine"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_DMR"}, 0.1, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"ZLand_DMR_Mag_20rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_HKG28"}, 0.1, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"ZLand_Mag_HKG28_20rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_MP7A1"}, 0.1, {
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"VTR_Bravo4"}),
			new ZLandLootWithAttachments({"ZLand_MP7A1_Mag_50Rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_MP7A2"}, 0.1, {
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"VTR_Bravo4"}),
			new ZLandLootWithAttachments({"ZLand_MP7A1_Mag_50Rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"IMP_McMillan_CS5"}, 0.1, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"IMP_Mag_McMillan_CS5_10Rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_SR25"}, 0.1, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_CombatGrip","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"ZLand_PMAG_GEN3_Mag"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"Connor_AR15"}, 0.1, {
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"ZLand_CombatGrip","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"Connor_AR15_Magazine"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"IMP_M39EMR"}, 0.1, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"IMP_Mag_M39EMR_20Rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_ASVAL"}, 0.1, {
			new ZLandLootEntry({"ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"ZLand_CombatGrip","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"ZLand_ASVAL_Magazine_Dual"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_RSASS_Tan"}, 0.1, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_CombatGrip","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"ZLand_PMAG_GEN3_Mag"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_Honeybadger_Tan"}, 0.1, {
			new ZLandLootEntry({"VTR_Bravo4","Battery9V"}),
			new ZLandLootEntry({"ZLand_CombatGrip","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"ZLand_Honeybadger_Mag_30Rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_RPK16"}, 0.1, {
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"ZLand_CombatGrip","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"ZLand_RPK16_Drum"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_RD704"}, 0.1, {
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
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_MCX"}, 1.0, {
			new ZLandLootEntry({"M4_OEBttstck","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"M4_RISHndgrd","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"ZLand_MCX_Magazine"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
	}
	
	override int GetMinLoot()
	{
		return 4;
	}
	
	override int GetMaxLoot()
	{
		return 4;
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
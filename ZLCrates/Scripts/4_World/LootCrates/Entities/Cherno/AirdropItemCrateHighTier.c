class AirdropItemCrateHighTier: ZLandContainerBase
{
	override void RegisterLootTable(array<ref ZLandLootEntry> loot_table) 
	{
		super.RegisterLootTable(loot_table);
		
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"B95"}, 0.8, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"Ammo_308Win"}, 1.0, {
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
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_ARX160"}, 1.0, {
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"ZLand_CombatGrip","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"ZLand_ARX160_Mag_30rnd"}, 1.0, {
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
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"Connor_MK18"}, 1.0, {
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"ZLand_CombatGrip","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"ConnorMK18_Magazine"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"PITSTOP_SCARH_Black"}, 1.0, {
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"ZLand_CombatGrip","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"PITSTOP_SCARH_50rnd_Magazine"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_SA58"}, 1.0, {
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"ZLand_CombatGrip","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"ZLandSA58_Magazine"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"PITSTOP_HK417_Black"}, 1.0, {
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"ZLand_CombatGrip","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"PITSTOP_HK417_Magazine"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_G3SG1"}, 1.0, {
			new ZLandLootEntry({"IMP_RailAK"}),
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootWithAttachments({"ZLand_G3SG1_Magazine"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_AK47"}, 1.0, {
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"ZLand_DeltaPoint"}),
			new ZLandLootWithAttachments({"ZLand_AK47_Magazine"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"zland"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_MK3"}, 0.2, {
			new ZLandLootEntry({"ZLand_Burris_RT6","Atlas_Bipod"}),
			new ZLandLootEntry({"ZLand_CombatGrip","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"ZLandMk3_Magazine"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_MK3_Black"}, 0.2, {
			new ZLandLootEntry({"ZLand_Burris_RT6","Atlas_Bipod"}),
			new ZLandLootEntry({"ZLand_CombatGrip","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"ZLandMK3_Magazine"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_SKW338"}, 0.2, {
			new ZLandLootEntry({"ZLand_Burris_RT6","Atlas_Bipod"}),
			new ZLandLootEntry({"ZLand_CombatGrip","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"ZLandSKW338_Magazine"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_MK18_Mjolnir_Tan"}, 0.2, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_CombatGrip","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"ZLand_MK18_Mjolnir_Magazine"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_Tac21"}, 0.5, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLandTac21_Magazine"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"PITSTOP_Ruger_Black"}, 0.5, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"PITSTOP_Ruger_Magazine"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_TIMBERWOLF"}, 0.5, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"Atlas_Bipod"}),
			new ZLandLootWithAttachments({"ZLandTIMBERWOLF_Magazine"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"PITSTOP_M10_Black"}, 0.2, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"Atlas_Bipod"}),
			new ZLandLootWithAttachments({"PITSTOP_M10_Magazine"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"PITSTOP_M1000X_Black"}, 0.1, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"PITSTOP_M1000X_Magazine"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_SRSA2"}, 0.5, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"Atlas_Bipod"}),
			new ZLandLootWithAttachments({"SRSA2_Mag_10rnd"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"PITSTOP_Beowulf"}, 1.0, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"PITSTOP_Beowulf_Magazine"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_M300"}, 0.2, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"Atlas_Bipod"}),
			new ZLandLootWithAttachments({"ZLand_M300_Magazine"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_M200"}, 0.2, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"ZLand_M200_Mag_7rnd"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"PITSTOP_M240"}, 1.0, {
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"VTR_bravo4","Battery9V"}),
			new ZLandLootWithAttachments({"PITSTOP_M240_Magazine"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_PKM"}, 1.0, {
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"IMP_RailAK"}),
			new ZLandLootWithAttachments({"ZLand_PKM_Magazine"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"PITSTOP_PKP"}, 1.0, {
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"VTR_bravo4"}),
			new ZLandLootWithAttachments({"PITSTOP_PKP_Magazine"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"PITSTOP_M96"}, 0.01, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"PITSTOP_M96_Magazine"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_AX50"}, 0.01, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"ZLand_Mag_AX50_5rnd"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLAND_50Cal_Suppressor"}, 0.01));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_GM6LYNX"}, 0.01, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"ZLandGM6LYNX_Magazine"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"PITSTOP_M82A2_Black"}, 0.01, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"PITSTOP_M82A2_Magazine"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_VSSK"}, 0.6, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"ZLand_VSSK_Mag_5rnd"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"Connor_Anzio"}, 0.01, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"PITSTOP_Ammo_65cal"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_Alligator"}, 0.01, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"ZLand_Alligator_Mag"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"IMP_Supp_408_Black"}, 0.1));
		loot_table.Insert(new ZLandLootWithAttachments({"IMP_M98B"}, 0.5, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"IMP_Mag_M98B_10Rnd"}, 1.0, {
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
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_MCX_Spear"}, 0.8, {
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootWithAttachments({"ZLand_MCX_Spear_Magazine"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_DesertTechHTI_Black"}, 0.2, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"ZLand_DesertTechHTI_Magazine"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"IMP_Helmet_RoninHeavy_Black","IMP_Helmet_RoninHeavy_Green","ZLANDk6Helmet_Green","ZLANDk6Helmet_Black","IMP_Helmet_Silencer_Black","IMP_Helmet_Silencer_Green","ZLANDKSHHelmet_BlackKilla","ZLANDKSHHelmet_Black","ZLANDKSHHelmet_Green"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"ZLAND_Tagilla_WeldingMask","ZLAND_Tagilla_WeldingMask_Gorilla"}, 0.5));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"ZLAND_Jugg_Helmet_Black","ZLAND_Jugg_Helmet_Green"}, 0.25));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"IMP_Vest_6B43T_Black","IMP_Vest_6B43T_Green","IMP_Vest_6B43T_Tan","IMP_Vest_Gen4_Black","IMP_Vest_6B45_Green","IMP_Vest_Gen4_Tan","IMP_Vest_Thor_Black","IMP_Vest_Thor_Tan","IMP_Vest_Thor_Green","ZLAND_NavySealsVest_Black","ZLAND_NavySealsVest_Green","ZLAND_NavySealsVest_Tan"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {

		}));
		loot_table.Insert(new ZLandLootEntry({"ZLANDLevel3JuggSuit_Black","ZLANDLevel3JuggSuit_Tan","ZLANDLevel3JuggSuit_Olive"}, 0.1));
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
		loot_table.Insert(new ZLandLootEntry({"ZLAND_Key_Red","ZLAND_Key_Red2","ZLAND_Key_Red3","ZLAND_Key_Blue","ZLAND_Key_Blue2","ZLAND_Key_Blue3","ZLAND_Key_Blue4","ZLAND_Key_Blue5","ZLAND_Key_Yellow","ZLAND_Key_Yellow2","ZLAND_Key_Yellow3","ZLAND_Key_Yellow4","ZLAND_Key_Yellow5","ZLAND_Key_Green","ZLAND_Key_Green2","ZLAND_Key_Green3","ZLAND_Key_Green4","ZLAND_Key_Green5","ZLAND_Key_Purple","ZLAND_Key_Purple2","ZLAND_Key_Purple3","ZLAND_Key_Purple4","ZLAND_Key_Purple5","ZLAND_ArmoryKey"}, 1.0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand"}, 0, {
	
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand_RedRoomArmoryKey"}, 1.0));
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
		loot_table.Insert(new ZLandLootEntry({"Keycard","Keycard_Blue","Keycard_Green","Keycard_Yellow","Keycard_Purple","Keycard_Red","Keycard_Black"}, 0.01));
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
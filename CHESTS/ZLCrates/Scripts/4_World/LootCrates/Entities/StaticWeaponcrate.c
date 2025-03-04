class StaticWeaponcrate: ZLandContainerBase
{
	override void RegisterLootTable(array<ref ZLandLootEntry> loot_table) 
	{
		super.RegisterLootTable(loot_table);
		
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_UMP45"}, 1.0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLand_UMP45_Mag_25Rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_P90"}, 1.0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLand_P90_50RndMag"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"M16A2"}, 1.0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"Mag_CMAG_30Rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"PITSTOP_M16"}, 1.0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"Mag_CMAG_30Rnd"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"IMP_AN94"}, 1.0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"Mag_AK74_30Rnd_Black"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"Connor_AK12"}, 1.0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"Mag_AK74_30Rnd_Black"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"PITSTOP_AEK971"}, 1.0, {
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"Mag_AK74_30Rnd_Black"}, 1.0, {
				new ZLandLootEntry({"Battery9V"}),
			}),
		}));
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
		loot_table.Insert(new ZLandLootWithAttachments({"IMP_AR15"}, 1.0, {
			new ZLandLootEntry({"M4_RISHndgrd_Black"}),
			new ZLandLootEntry({"M4_MPBttstck_Black"}),
			new ZLandLootWithAttachments({"Mag_CMAG_30Rnd"}, 1.0, {
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
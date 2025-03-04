class ToxicLootCrate: ZLandContainerBase
{
	override void RegisterLootTable(array<ref ZLandLootEntry> loot_table) 
	{
		super.RegisterLootTable(loot_table);
		
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
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_MK3"}, 0.5, {
			new ZLandLootEntry({"ZLand_Burris_RT6","Atlas_Bipod"}),
			new ZLandLootEntry({"ZLand_CombatGrip","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"ZLandMk3_Magazine"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_MK3_Black"}, 0.5, {
			new ZLandLootEntry({"ZLand_Burris_RT6","Atlas_Bipod"}),
			new ZLandLootEntry({"ZLand_CombatGrip","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"ZLandMK3_Magazine"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_SKW338"}, 0.5, {
			new ZLandLootEntry({"ZLand_Burris_RT6","Atlas_Bipod"}),
			new ZLandLootEntry({"ZLand_CombatGrip","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"ZLandSKW338_Magazine"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_Tac21"}, 1.0, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand"}),
			new ZLandLootWithAttachments({"ZLandTac21_Magazine"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"PITSTOP_Ruger_Black"}, 1.0, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"PITSTOP_Ruger_Magazine"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_TIMBERWOLF"}, 1.0, {
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
		loot_table.Insert(new ZLandLootWithAttachments({"PITSTOP_M1000X_Black"}, 0.01, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"PITSTOP_M1000X_Magazine"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_SRSA2"}, 1.0, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"Atlas_Bipod"}),
			new ZLandLootWithAttachments({"SRSA2_Mag_10rnd"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"PITSTOP_Beowulf"}, 1.0, {
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootEntry({"VTR_bravo4","ZLand_DeltaPoint","Connor_Bravo","Connor_Burris","Connor_Elcan","Connor_PK06","Connor_TrijiconMRO"}),
			new ZLandLootWithAttachments({"PITSTOP_Beowulf_Magazine"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_M300"}, 0.4, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"Atlas_Bipod"}),
			new ZLandLootWithAttachments({"ZLand_M300_Magazine"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_M200"}, 0.4, {
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
		loot_table.Insert(new ZLandLootWithAttachments({"PITSTOP_M96"}, 0.1, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"PITSTOP_M96_Magazine"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_AX50"}, 0.1, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"ZLand_Mag_AX50_5rnd"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLAND_50Cal_Suppressor"}, 0.3));
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
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_VSSK"}, 1.0, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"ZLand_VSSK_Mag_5rnd"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"Connor_Anzio"}, 0.1, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"PITSTOP_Ammo_65cal"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"ZLand"}, 0));
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_Alligator"}, 0.1, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootWithAttachments({"ZLand_Alligator_Mag"}, 1.0, {
			    new ZLandLootEntry({"Battery9V"}),
			}),
		}));
		loot_table.Insert(new ZLandLootEntry({"IMP_Supp_408_Black"}, 0.4));
		loot_table.Insert(new ZLandLootWithAttachments({"IMP_M98B"}, 0.7, {
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
		loot_table.Insert(new ZLandLootWithAttachments({"ZLand_MK18_Mjolnir_Tan"}, 0.5, {
			new ZLandLootEntry({"ZLand_Burris_RT6"}),
			new ZLandLootEntry({"ZLand_CombatGrip","ZLand_CobraForeGrip","ZLand_ShiftGrip","ZLand_StubbyGrip","ZLand_ZenithGrip","ProjectForeGrip_Black"}),
			new ZLandLootWithAttachments({"ZLand_MK18_Mjolnir_Magazine"}, 1.0, {
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
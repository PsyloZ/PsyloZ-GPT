[DayZGame.RegisterLBAdminPage("LBLootChestsAdminPage", "LBmaster_LootChests/logo/logo.paa", "Chest Config", "lootchest.change.chests")]
class LBLootChestsAdminPage : LBAdmin_Menu_Page {

	MultilineEditBoxWidget edit_description, edit_comment;
	TextListboxWidget list_chests, list_keys, list_chest_items, list_soundsets;
	CheckBoxWidget chckbx_enabled, chckbx_enabled_chest, chckbx_openable;
	ButtonWidget btn_add_chest, btn_del_chest, btn_add_key, btn_del_key, btn_add_chest_item, btn_del_chest_item, btn_add_soundset, btn_del_soundset, btn_browse_pool;
	ButtonWidget btn_browse_preset;
	EditBoxWidget edit_respawn_dist, edit_name, edit_displayname, edit_max_chests, edit_positionpool, edit_key_classname, edit_open_time, edit_item_damage;
	EditBoxWidget edit_key_success, edit_lootpreset, edit_loot_hp_min, edit_loot_hp_max, edit_respawn_min, edit_respawn_max;

	override array<string> GetEditedConfigs() {
		return {"LBLootChestConfig"};
	}

	override void OnShow() {
		super.OnShow();
		linked.LoadLinkedVars();
	}

	override void RegisterAllLinkedVars() {
		TStringArray soundSets = new TStringArray();
		int count = g_Game.ConfigGetChildrenCount("CfgSoundSets");
		for (int i = 0; i < count; ++i) {
			string name;
			g_Game.ConfigGetChildName("CfgSoundSets", i, name);
			if (g_Game.ConfigIsExisting("CfgSoundSets " + name + " soundShaders"))
				soundSets.Insert(name);
		}
		TStringSet soundSetsSet = LBArrayTools<string>.ToSet(soundSets);
		TStringArray availablePools = new TStringArray();
		foreach (LB_LC_PositionPool pool : LB_LC_PoolConfig.Get.positionPools) {
			availablePools.Insert(pool.name);
		}
		
		linked.RegisterLinkedVar("GetConfig().enabled", chckbx_enabled);
		linked.RegisterLinkedVar("GetConfig().minPlayerDistanceForRespawn", edit_respawn_dist);
		linked.RegisterLinkedList("GetConfig().chestConfigs", list_chests, btn_add_chest, btn_del_chest).SetListManager(new LBListManager<LB_LC_Chest>());
		linked.RegisterLinkedVar("GetConfig().chestConfigs[list_chests].name", edit_name, true);
		linked.RegisterLinkedVar("GetConfig().chestConfigs[list_chests].chestDisplayName", edit_displayname);
		linked.RegisterLinkedVar("GetConfig().chestConfigs[list_chests].chestDescription", edit_description);
		linked.RegisterLinkedVar("GetConfig().chestConfigs[list_chests].comment", edit_comment);
		linked.RegisterLinkedVar("GetConfig().chestConfigs[list_chests].enabled", chckbx_enabled_chest);
		linked.RegisterLinkedVar("GetConfig().chestConfigs[list_chests].maxSpawns", edit_max_chests);
		linked.RegisterLinkedVar("GetConfig().chestConfigs[list_chests].positionPool", edit_positionpool).EnableListBrowse(availablePools, btn_browse_pool, "Select a position pool");
		linked.RegisterLinkedList("GetConfig().chestConfigs[list_chests].chests", list_chest_items, btn_add_chest_item, btn_del_chest_item).SetListManager(new LBListManagerString()).EnableItemSelector(true, "LB_LC_Base", false);
		linked.RegisterLinkedList("GetConfig().chestConfigs[list_chests].keys", list_keys, btn_add_key, btn_del_key).SetListManager(new LBListManager<LB_LC_ChestKey>()).EnableItemSelector(true, "Inventory_Base", true);
		linked.RegisterLinkedVar("GetConfig().chestConfigs[list_chests].keys[list_keys].itemname", edit_key_classname);
		linked.RegisterLinkedVar("GetConfig().chestConfigs[list_chests].keys[list_keys].time", edit_open_time);
		linked.RegisterLinkedVar("GetConfig().chestConfigs[list_chests].keys[list_keys].damage", edit_item_damage);
		linked.RegisterLinkedVar("GetConfig().chestConfigs[list_chests].keys[list_keys].successRate", edit_key_success);
		linked.RegisterLinkedVar("GetConfig().chestConfigs[list_chests].openable", chckbx_openable);
		linked.RegisterLinkedList("GetConfig().chestConfigs[list_chests].playedSoundSets", list_soundsets, btn_add_soundset, btn_del_soundset).SetListManager(new LBListManagerString()).EnableListSelector(soundSets).EnableInListSearch(soundSetsSet);
		linked.RegisterLinkedVar("GetConfig().chestConfigs[list_chests].lootPreset", edit_lootpreset).EnableListBrowse(g_Game.lbAvailableLoadouts, btn_browse_preset, "Select a preset (must have root enabled)");
		linked.RegisterLinkedVar("GetConfig().chestConfigs[list_chests].lootHealthMin", edit_loot_hp_min);
		linked.RegisterLinkedVar("GetConfig().chestConfigs[list_chests].lootHealthMax", edit_loot_hp_max);
		linked.RegisterLinkedVar("GetConfig().chestConfigs[list_chests].lootRespawnTimeMin", edit_respawn_min);
		linked.RegisterLinkedVar("GetConfig().chestConfigs[list_chests].lootRespawnTimeMax", edit_respawn_max);
	}

	LBLootChestConfig_ GetConfig() {
		return LBLootChestConfig.Get;
	}
}
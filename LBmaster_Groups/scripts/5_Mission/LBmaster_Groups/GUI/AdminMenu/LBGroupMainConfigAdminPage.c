[RegisterLBAdminPage(LBGroupMainConfigAdminPage, "LBmaster_Groups/logo/logo.paa", "Main Config", "group.mainconfig.change")]
class LBGroupMainConfigAdminPage : LBAdmin_Menu_Page {

	Widget legend_text_out;
	TextListboxWidget list_icons, list_sub_names, list_legend, list_compass_items, list_gps_items, list_gps_vehicles, list_map_items, list_see_items;
	XComboBoxWidget combo_marker_config, combo_info_buttons;
	SliderWidget slider_b, slider_g, slider_r, slider_a, slider_a_txt, slider_r_txt, slider_g_txt, slider_b_txt;
	ButtonWidget btn_death_browse, btn_del_icon, btn_add_icon, btn_add_subname, btn_del_subname, btn_add_legend, btn_del_legend, btn_legend_icon, btn_add_compass, btn_del_compass, btn_add_gps, btn_del_gps;
	ButtonWidget btn_add_vehicle, btn_del_vehicle, btn_add_map, btn_del_map, btn_not_found_browse, btn_add_see, btn_del_see;
	CheckBoxWidget chckbx_own_marker, chckbx_add_death, chckbx_death_private, chckbx_death_group, chckbx_death_delete, chckbx_marker_place, chckbx_marker_page, chckbx_display3d, chckbx_displaydistance, chckbx_displaymap;
	CheckBoxWidget chckbx_displaycompass, chckbx_displaygps, chckbx_invite_action, chckbx_invite_name, chckbx_friendly_fire, chckbx_friendly_fire_sub, chckbx_secondary_group, chckbx_rem_temp_restart;
	CheckBoxWidget chckbx_rem_temp_leave, chckbx_subgroups, chckbx_subgroups_player, chckbx_subgroups_ping, chckbx_disable_groups, chckbx_upgrade_bene, chckbx_obfuscate_list, chckbx_enable_legend, chckbx_compass;
	CheckBoxWidget chckbx_compass_item, chckbx_gps, chckbx_gps_heading, chckbx_gps_speed, chckbx_gps_coords, chckbx_gps_item, chckbx_gps_item_veh, chckbx_map_item, chckbx_group_see_item, chckbx_group_seen_item;
	CheckBoxWidget chckbx_playerlist_enable, chckbx_playerlist_distance, chckbx_obfuscate, chckbx_disable_settings, chckbx_survivor_count, chckbx_cursor_coords, chckbx_player_pos, chckbx_ingame_time, chckbx_real_time;
	ImageWidget img_icon_preview, legend_icon, img_death_icon;
	EditBoxWidget edit_death_icon, edit_marker_limit, edit_ping_lifetime, edit_ping_limit, edit_offline_distance, edit_max_distance, edit_inactive_del, edit_invite_cooldown, edit_sub_name, edit_legend_title, edit_b;
	EditBoxWidget edit_g, edit_r, edit_a, edit_legend_icon, edit_legend_text, edit_a_txt, edit_r_txt, edit_g_txt, edit_b_txt, edit_map_not_found_txt, edit_map_not_found_img, edit_button_title, edit_button_subtext;
	EditBoxWidget edit_button_link;

	string lastPath;
	ref TIntArray combo_to_id = new TIntArray();

	override void OnPageShown() {
		super.OnPageShown();
		linked.LoadLinkedVars();
	}

	override array<typename> GetEditedConfigs() {
		return {LBGroupMainConfig};
	}

	override void RegisterAllLinkedVars() {
		// Marker
		linked.RegisterLinkedVar("GetConfig().canSeeOwnPlayerOnMap", chckbx_own_marker);
		linked.RegisterLinkedVar("GetConfig().addPlayerDeathMarker", chckbx_add_death);
		linked.RegisterLinkedVar("GetConfig().deathMarkerPrivate", chckbx_death_private);
		linked.RegisterLinkedVar("GetConfig().deathMarkerGroup", chckbx_death_group);
		linked.RegisterLinkedVar("GetConfig().deleteOldDeathMarker", chckbx_death_delete);
		linked.RegisterLinkedVar("GetConfig().deathMarkerIcon", edit_death_icon).EnableFileSelector({".paa", ".edds"}, btn_death_browse).SetChangeTrigger("LoadDeathIcon()");
		linked.RegisterLinkedList("GetConfig().availableIcons", list_icons, null, btn_del_icon);
		linked.RegisterLinkedVar("GetConfig().disableMarkerPlacement", chckbx_marker_place);
		linked.RegisterLinkedVar("GetConfig().disableMarkerPageOnMap", chckbx_marker_page);
		linked.RegisterLinkedVar("GetConfig().groupMarkerLimit", edit_marker_limit);
		linked.RegisterLinkedVar("GetConfig().tacticalPingLifetimeSeconds", edit_ping_lifetime);
		linked.RegisterLinkedVar("GetConfig().tacticalPingMaxConcurrentMarkersPerPlayer", edit_ping_limit);
		linked.RegisterLinkedVar("GetConfig().offlinePlayer3dMarkerDistance", edit_offline_distance);
		LoadMarkerConfigTypes();
		linked.RegisterLinkedVar("GetCurrentMarkerConfigEntry().maxDistance", edit_max_distance).SetReloadTrigger(combo_marker_config);
		linked.RegisterLinkedVar("GetCurrentMarkerConfigEntry().display3d", chckbx_display3d).SetReloadTrigger(combo_marker_config);
		linked.RegisterLinkedVar("GetCurrentMarkerConfigEntry().displayDistance", chckbx_displaydistance).SetReloadTrigger(combo_marker_config);
		linked.RegisterLinkedVar("GetCurrentMarkerConfigEntry().displayMap", chckbx_displaymap).SetReloadTrigger(combo_marker_config);
		linked.RegisterLinkedVar("GetCurrentMarkerConfigEntry().displayCompass", chckbx_displaycompass).SetReloadTrigger(combo_marker_config);
		linked.RegisterLinkedVar("GetCurrentMarkerConfigEntry().displayGPS", chckbx_displaygps).SetReloadTrigger(combo_marker_config);
		combo_marker_config.SetCurrentItem(0);
		// Groups
		linked.RegisterLinkedVar("GetConfig().inactiveGroupLifetimeDays", edit_inactive_del);
		linked.RegisterLinkedVar("GetConfig().inviteActionEnabled", chckbx_invite_action);
		linked.RegisterLinkedVar("GetConfig().inviteActionShowName", chckbx_invite_name);
		linked.RegisterLinkedVar("GetConfig().inviteCooldownSeconds", edit_invite_cooldown);
		linked.RegisterLinkedVar("GetConfig().preventFriendlyFire", chckbx_friendly_fire);
		linked.RegisterLinkedVar("GetConfig().preventFriendlyFireOnlyInSameSubgroup", chckbx_friendly_fire_sub);
		linked.RegisterLinkedVar("GetConfig().allowJoinSecondGroupTemporarily", chckbx_secondary_group);
		linked.RegisterLinkedVar("GetConfig().removeTemporaryMemberOnServerStart", chckbx_rem_temp_restart);
		linked.RegisterLinkedVar("GetConfig().removeTemporaryMemberOnPlayerLeave", chckbx_rem_temp_leave);
		linked.RegisterLinkedVar("GetConfig().enableSubGroups", chckbx_subgroups);
		linked.RegisterLinkedVar("GetConfig().enableSubGroupSharedPlayerMapMarker", chckbx_subgroups_player);
		linked.RegisterLinkedVar("GetConfig().enableSubGroupSharedPingMapMarker", chckbx_subgroups_ping);
		linked.RegisterLinkedVar("GetConfig().disableGroupPageOnMap", chckbx_disable_groups);
		linked.RegisterLinkedVar("GetConfig().groupManagePageObfuscatePlayernames", chckbx_obfuscate_list);
		linked.RegisterLinkedVar("GetConfig().showLevelUpgradeBenefits", chckbx_upgrade_bene);
		linked.RegisterLinkedList("GetConfig().subGroupNames", list_sub_names, btn_add_subname, btn_del_subname, edit_sub_name);
		// Legend
		linked.RegisterLinkedVar("GetConfig().enableMapLegend", chckbx_enable_legend);
		linked.RegisterLinkedVar("GetConfig().mapLegendTitle", edit_legend_title);
		linked.RegisterLinkedList("GetConfig().mapLegend", list_legend, btn_add_legend, btn_del_legend).SetListManager(new LBListManager<ref MapLegendItem>());
		linked.RegisterLinkedVar("GetConfig().mapLegend[list_legend].iconPath", edit_legend_icon).EnableFileSelector({".paa", ".edds"}, btn_legend_icon).SetReloadTrigger(list_legend).SetChangeTrigger("LoadLegendIcon()");
		linked.RegisterLinkedVar("GetConfig().mapLegend[list_legend].iconColorA", slider_a).SetExtraOutput(edit_a).SetChangeTrigger("LoadLegendIcon()");
		linked.RegisterLinkedVar("GetConfig().mapLegend[list_legend].iconColorR", slider_r).SetExtraOutput(edit_r).SetChangeTrigger("LoadLegendIcon()");
		linked.RegisterLinkedVar("GetConfig().mapLegend[list_legend].iconColorG", slider_g).SetExtraOutput(edit_g).SetChangeTrigger("LoadLegendIcon()");
		linked.RegisterLinkedVar("GetConfig().mapLegend[list_legend].iconColorB", slider_b).SetExtraOutput(edit_b).SetChangeTrigger("LoadLegendIcon()");
		linked.RegisterLinkedVar("GetConfig().mapLegend[list_legend].nameColorA", slider_a_txt).SetExtraOutput(edit_a_txt).SetChangeTrigger("UpdateLegendName()");
		linked.RegisterLinkedVar("GetConfig().mapLegend[list_legend].nameColorR", slider_r_txt).SetExtraOutput(edit_r_txt).SetChangeTrigger("UpdateLegendName()");
		linked.RegisterLinkedVar("GetConfig().mapLegend[list_legend].nameColorG", slider_g_txt).SetExtraOutput(edit_g_txt).SetChangeTrigger("UpdateLegendName()");
		linked.RegisterLinkedVar("GetConfig().mapLegend[list_legend].nameColorB", slider_b_txt).SetExtraOutput(edit_b_txt).SetChangeTrigger("UpdateLegendName()");
		linked.RegisterLinkedVar("GetConfig().mapLegend[list_legend].name", edit_legend_text);
		// Items
		TStringSet itemSet = LBInherit.Get().GetAllChildren({"Inventory_Base"}, false, true, true);
		linked.RegisterLinkedVar("GetConfig().enableCompassHud", chckbx_compass);
		linked.RegisterLinkedVar("GetConfig().compassRequireItem", chckbx_compass_item);
		linked.RegisterLinkedList("GetConfig().compassItems", list_compass_items, btn_add_compass, btn_del_compass, null).EnableItemSelector(true, "Inventory_Base").EnableInListSearch(itemSet);
		linked.RegisterLinkedVar("GetConfig().enableGPS", chckbx_gps);
		linked.RegisterLinkedVar("GetConfig().gpsDisplayAngle", chckbx_gps_heading);
		linked.RegisterLinkedVar("GetConfig().gpsDisplaySpeed", chckbx_gps_speed);
		linked.RegisterLinkedVar("GetConfig().gpsDisplayCoords", chckbx_gps_coords);
		linked.RegisterLinkedVar("GetConfig().gpsRequireItem", chckbx_gps_item);
		linked.RegisterLinkedList("GetConfig().gpsItems", list_gps_items, btn_add_gps, btn_del_gps, null).EnableItemSelector(true, "Inventory_Base").EnableInListSearch(itemSet);
		linked.RegisterLinkedVar("GetConfig().gpsOnlyInVehicles", chckbx_gps_item_veh);
		TStringSet itemVehicles = LBInherit.Get().GetAllChildren({"Transport"}, false, true, true);
		linked.RegisterLinkedList("GetConfig().vehiclesWithGPS", list_gps_vehicles, btn_add_vehicle, btn_del_vehicle, null).EnableItemSelector(false, "Transport").EnableInListSearch(itemVehicles);
		linked.RegisterLinkedVar("GetConfig().mapRequireItem", chckbx_map_item);
		linked.RegisterLinkedList("GetConfig().mapItems", list_map_items, btn_add_map, btn_del_map, null).EnableItemSelector(true, "Inventory_Base").EnableInListSearch(itemSet);
		linked.RegisterLinkedVar("GetConfig().mapNotFoundText", edit_map_not_found_txt);
		linked.RegisterLinkedVar("GetConfig().mapNotFoundImage", edit_map_not_found_img).EnableFileSelector({".paa", ".edds"}, btn_not_found_browse);
		linked.RegisterLinkedVar("GetConfig().requireItemToSeeGroupMembers", chckbx_group_see_item);
		linked.RegisterLinkedVar("GetConfig().requireItemToBeSeenByGroupMembers", chckbx_group_seen_item);
		linked.RegisterLinkedList("GetConfig().playerMarkerItems", list_see_items, btn_add_see, btn_del_see, null).EnableItemSelector(true, "Inventory_Base").EnableInListSearch(itemSet);
		// Misc
		linked.RegisterLinkedVar("GetConfig().enablePlayerList", chckbx_playerlist_enable);
		linked.RegisterLinkedVar("GetConfig().enablePlayerListDistance", chckbx_playerlist_distance);
		linked.RegisterLinkedVar("GetConfig().groupManagePageObfuscatePlayernames", chckbx_obfuscate);
		linked.RegisterLinkedVar("GetConfig().disableSettingsPageOnMap", chckbx_disable_settings);
		// Info Page
		linked.RegisterLinkedVar("GetConfig().enableInfoPanelSurvivorCount", chckbx_survivor_count);
		linked.RegisterLinkedVar("GetConfig().enableInfoPanelCursorCoordinates", chckbx_cursor_coords);
		linked.RegisterLinkedVar("GetConfig().enableUIPlayerPosition", chckbx_player_pos);
		linked.RegisterLinkedVar("GetConfig().enableInfoPanelIngameTime", chckbx_ingame_time);
		linked.RegisterLinkedVar("GetConfig().enableInfoPanelRealTime", chckbx_real_time);
		linked.RegisterLinkedVar("GetCurrentButtonConfig().buttonName", edit_button_title).SetReloadTrigger(combo_info_buttons);
		linked.RegisterLinkedVar("GetCurrentButtonConfig().subtext", edit_button_subtext).SetReloadTrigger(combo_info_buttons);
		linked.RegisterLinkedVar("GetCurrentButtonConfig().link", edit_button_link).SetReloadTrigger(combo_info_buttons);

	}

	void LoadMarkerConfigTypes() {
		combo_marker_config.ClearAll();
		typename tn = LBMarkerType;
		int count = tn.GetVariableCount();
		for (int i = 0; i < count; ++i) {
			string name = tn.GetVariableName(i);
			combo_marker_config.AddItem(name);
			combo_to_id.Insert(typename.StringToEnum(LBMarkerType, name));
		}
	}

	void LoadLegendIcon() {
		int selected = list_legend.GetSelectedRow();
		if (selected < 0 || selected >= GetConfig().mapLegend.Count())
			return;
		MapLegendItem legend = GetConfig().mapLegend.Get(selected);
		if (!legend)
			return;
		legend_icon.LoadImageFile(0, legend.iconPath);
		legend_icon.SetColor(ARGB(slider_a.GetCurrent(), slider_r.GetCurrent(), slider_g.GetCurrent(), slider_b.GetCurrent()));
	}

	void LoadDeathIcon() {
		img_death_icon.LoadImageFile(0, GetConfig().deathMarkerIcon);
	}

	void UpdateLegendName() {
		edit_legend_text.SetTextColor(ARGB(slider_a_txt.GetCurrent(), slider_r_txt.GetCurrent(), slider_g_txt.GetCurrent(), slider_b_txt.GetCurrent()));
	}

	LBButtonConfig GetCurrentButtonConfig() {
		int selected = combo_info_buttons.GetCurrentItem();
		if (selected < 0 || selected >= 6)
			return null;
		while (selected >= GetConfig().buttonConfig.Count())
			GetConfig().buttonConfig.Insert(new LBButtonConfig());
		return GetConfig().buttonConfig.Get(selected);

	}

	LBGroupMainConfig_ GetConfig() {
		return LBGroupMainConfig.Get;
	}

	MarkerConfigEntry GetCurrentMarkerConfigEntry() {
		int selected = combo_marker_config.GetCurrentItem();
		if (selected < 0 || selected >= GetConfig().markerConfig.Count())
			return null;
		return GetConfig().GetMarkerConfigEntry(combo_to_id.Get(selected));
	}

	void OnIconSelected(string value) {
		value.Replace("/", "\\");
		lastPath = value;
		if (GetConfig().availableIcons.Find(value) != -1)
			return;
		GetConfig().availableIcons.Insert(value);
		linked.TriggerLoad("GetConfig().availableIcons");
	}

	override bool OnClick(Widget w, int x, int y, int button) {
		if (super.OnClick(w, x, y, button))
			return true;
		if (w == btn_add_icon) {
			LBMenuManager.Get().OpenMenu(LBFileSelectorDialog, new LBMenuDataFileSelector(lastPath, "#lb_file_selector", "#lb_select", {".paa", ".edds"}, ScriptCaller.Create(OnIconSelected)), false, LBMenuManager.Get().GetOpenLBMenu());
			return true;
		}
		return false;
	}

	override bool OnItemSelected(Widget w, int x, int y, int row, int column, int oldRow, int oldColumn) {
		if (super.OnItemSelected(w, x, y, row, column, oldRow, oldColumn))
			return true;
		if (w == list_icons) {
			int selected = list_icons.GetSelectedRow();
			if (selected < 0 || selected > GetConfig().availableIcons.Count())
				return true;
			img_icon_preview.LoadImageFile(0, GetConfig().availableIcons.Get(selected));
			return true;
		}
		return false;
	}
}
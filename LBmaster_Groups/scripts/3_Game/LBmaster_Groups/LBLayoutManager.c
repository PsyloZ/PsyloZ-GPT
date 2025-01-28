modded class LBLayoutManager {

	override string GetLayoutPathOriginal(string name) {
		if (name == "Map Page 0 0") return "LBmaster_Groups/gui/layouts/mapmenu/pages/page_0_0_default.layout";
		if (name == "Map Page 1 0") return "LBmaster_Groups/gui/layouts/mapmenu/pages/page_1_0_default.layout";
		if (name == "Map Page 1 1") return "LBmaster_Groups/gui/layouts/mapmenu/pages/page_1_1_default.layout";
		if (name == "Map Page 2 0") return "LBmaster_Groups/gui/layouts/mapmenu/pages/page_2_0_default.layout";
		if (name == "Map Page 3 0") return "LBmaster_Groups/gui/layouts/mapmenu/pages/page_3_0_default.layout";
		if (name == "Map Page 4 0") return "LBmaster_Groups/gui/layouts/mapmenu/pages/page_4_0_default.layout";
		if (name == "Map Page 5 0") return "LBmaster_Groups/gui/layouts/mapmenu/pages/page_5_0_default.layout";
		if (name == "Map Page 6 0") return "LBmaster_Groups/gui/layouts/mapmenu/pages/page_6_0_default.layout";
		if (name == "Map Page 7 0") return "LBmaster_Groups/gui/layouts/mapmenu/pages/page_7_0_default.layout";
		if (name == "Map Page 8 0") return "LBmaster_Groups/gui/layouts/mapmenu/pages/page_8_0_default.layout";
		if (name == "Map Page 9 0") return "LBmaster_Groups/gui/layouts/mapmenu/pages/page_9_0_default.layout";
		if (name == "Map Top Button") return "LBmaster_Groups/gui/layouts/mapmenu/topButton_default.layout";
		if (name == "MapLegendEntry") return "LBmaster_Groups/gui/layouts/mapmenu/map_marker.layout";
		if (name == "PlayerList_Normal") return "LBmaster_Groups/gui/layouts/playerlist/playerlistentry_default.layout";
		if (name == "PlayerList_Small") return "LBmaster_Groups/gui/layouts/playerlist/playerlistentry_small.layout";
		if (name == "PlayerList_Tiny") return "LBmaster_Groups/gui/layouts/playerlist/playerlistentry_tiny.layout";
		if (name == "3DMarker") return "LBmaster_Groups/gui/layouts/3dmarker.layout";
		if (name == "CompassMarker") return "LBmaster_Groups/gui/layouts/compass/compassMarker_default.layout";
		if (name == "MapMarker") return "LBmaster_Groups/gui/layouts/mapmenu/map_marker.layout";
		if (name == "MapMarker_Dragable") return "LBmaster_Groups/gui/layouts/mapmenu/map_marker_dragable.layout";
		if (name == "AdminMenu_LBGroupAdminPage") return "LBmaster_Groups/gui/layouts/admin/groupOverview.layout";
		if (name == "AdminMenu_LBChatAdminPage") return "LBmaster_Groups/gui/layouts/admin/chatadmin.layout";
		if (name == "AdminMenu_LBLevelsAdminPage") return "LBmaster_Groups/gui/layouts/admin/levels.layout";
		if (name == "AdminMenu_LBNoBuildZonesPage") return "LBmaster_Groups/gui/layouts/admin/noBuildZones.layout";
		if (name == "AdminMenu_LBSafezoneAdminPage") return "LBmaster_Groups/gui/layouts/admin/safezonemarkers.layout";
		if (name == "AdminMenu_LBTimeoutsAdminPage") return "LBmaster_Groups/gui/layouts/admin/timeouts.layout";
		if (name == "AdminMenu_LBTerritoryAdminPage") return "LBmaster_Groups/gui/layouts/admin/territoryconfig.layout";
		if (name == "AdminMenu_LBGroupMainConfigAdminPage") return "LBmaster_Groups/gui/layouts/admin/mainconfig.layout";
		if (name == "NoBuildZoneListEntry") return "LBmaster_Groups/gui/layouts/mapmenu/zonelistentry_default.layout";
		if (name == "Compass") return "LBmaster_Groups/gui/layouts/compass/compass_default.layout";
		if (name == "GPS") return "LBmaster_Groups/gui/layouts/gps/gps.layout";
		if (name == "PlayerListParent") return "LBmaster_Groups/gui/layouts/playerlist/playerlist.layout";
		if (name == "TextLengthTester") return "LBmaster_Groups/gui/layouts/textLengthTester.layout";
		if (name == "Chat") return "LBmaster_Groups/gui/layouts/chatmain.layout";
		if (name == "ChatItem") return "LBmaster_Groups/gui/layouts/day_z_chat_item.layout";
		if (name == "ChatInput") return "LBmaster_Groups/gui/layouts/day_z_chat_input.layout";
		if (name == "Map Marker List Entry") return "LBmaster_Groups/gui/layouts/mapmenu/markerlist/markerlistentry_default.layout";
		if (name == "Map Marker Add Popup") return "LBmaster_Groups/gui/layouts/mapmenu/markerpopup_default.layout";
		if (name == "GroupOverviewPlayerEntry") return "LBmaster_Groups/gui/layouts/mapmenu/groupOverviewPlayerEntry.layout";
		if (name == "GroupUI") return "LBmaster_Groups/gui/layouts/mapmenu/mapmenu_default.layout";
		if (name == "MapLegendTitle") return "LBmaster_Groups/gui/layouts/mapmenu/map_legend_title.layout";
		if (name == "ClanTagColorPicker") return "LBmaster_Groups/gui/layouts/mapmenu/changeClanTagColorPopup.layout";

		return super.GetLayoutPathOriginal(name);
	}

}
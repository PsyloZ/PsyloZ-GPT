class LBMarkerList {

	Widget listWidget;

	ref array<ref LBMarkerListEntry> entries = new array<ref LBMarkerListEntry>();
	ref TIntSet addedMarkerUIDs = new TIntSet();

	void CreateEntries(LBGroupUI groupUI) {
		PlayerBase pb = PlayerBase.Cast(g_Game.GetPlayer());
		if (!pb)
			return;
		LBGroup grp = pb.GetLBGroup();
		if (!LBLayoutConfig.Get.streamerModeEnabled) {
			AddSpacer("#lb_ag_txt_server_marker", LBMarkerType.SERVER_STATIC);
			foreach (LBServerMarker serverMarker : LBStaticMarkerManagerClient.Get().staticMarkers) {
				AddEntry(serverMarker, groupUI);
			}
		}
		if (grp) {
			LBGroupPermission perm = pb.GetPermission();
			if (perm && perm.CanSeeMarkerType(LBMarkerType.GROUP_MARKER)) {
				AddSpacer("#lb_ag_txt_group_marker", LBMarkerType.GROUP_MARKER);
				foreach (LBMarker groupMarker : grp.markers) {
					AddEntry(groupMarker, groupUI);
				}
			}
			if (perm && perm.CanSeeMarkerType(LBMarkerType.GROUP_PLAYER_MARKER)) {
				AddSpacer("#lb_ag_txt_players", LBMarkerType.GROUP_PLAYER_MARKER);
				foreach (LBGroupMember member : grp.members) {
					AddEntry(member, groupUI);
				}
			}
		}
		AddSpacer("#lb_ag_txt_private_marker", LBMarkerType.PRIVATE_MARKER);
		foreach (LBMarker privateMarker : LBPrivateMarkerManager.Get.privateMarkers) {
			AddEntry(privateMarker, groupUI);
		}
	}

	void AddSpacer(string name, LBMarkerType type) {
		LBMarkerListEntry entry = new LBMarkerListEntry();
		entry.InitSpacer(listWidget, name, type);
		entries.Insert(entry);
		addedMarkerUIDs.Clear();
	}

	void AddEntry(LBMarker marker, LBGroupUI groupUI) {
		if (addedMarkerUIDs.Find(marker.uid) != -1)
			return;
		addedMarkerUIDs.Insert(marker.uid);
		LBMarkerListEntry entry = new LBMarkerListEntry();
		entry.InitMarker(listWidget, marker, groupUI);
		entries.Insert(entry);
	}

	int ShouldUpdateList() {
		if (entries.Count() != 0)
			return 2;
		return 1;
	}

	void ClearAndDeleteEntries() {
		foreach (LBMarkerListEntry entry : entries) {
			delete entry;
		}
		entries.Clear();
	}

	void UpdateEntries(LBGroupUI groupUI, bool force = false) {
		if (!listWidget)
			return;
		int update = ShouldUpdateList();
		if (update == 1 || force) {
			ClearAndDeleteEntries();
			CreateEntries(groupUI);
		}
		LBLogger.Debug("Updating MarkerList", "AdvancedGroups");
		bool expanded = true;
		foreach (LBMarkerListEntry entry : entries) {
			if (entry.spacer) {
				expanded = entry.expanded;
				entry.Show(true);
				entry.UpdateWidget();
				continue;
			}
			if (expanded) {
				entry.Show(true);
				entry.UpdateWidget();
			} else {
				entry.Show(false);
			}
		}
	}

	LBMarkerListEntry OnIconPressed(Widget w) {
		foreach (LBMarkerListEntry entry : entries) {
			if (entry.icon_btn == w)
				return entry;
		}
		return null;
	}

	bool OnButtonPressed(Widget w) {
		foreach (LBMarkerListEntry entry : entries) {
			if (entry.OnButtonPressed(w))
				return true;
		}
		return false;
	}

}
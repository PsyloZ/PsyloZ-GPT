/*
class LBGroupManager : LBConfigLoader<LBGroup_> {
	override void InitVars() {
		InitVarsInternal("LBGroup/Groups", "[Shortname].json", LBConfigType.DATA); // (medium)
	}
}
*/
// This file is a Group file with all the info realted to a single group on the server.
//
// Do not edit this file while the server is running! All information will be overwritten.
//
// It's also recommended to use the ingame admin menu to make any changes to groups or delete them instead of manipulating the Json file!
class LBGroup { /*: LBConfigBasePlayer*/

	string name; // Long name of the Group
	string shortname; // Short name (Tag) also used as the filename of the group
	int level; // Current level of the Group
	int lastActivity = -1; // Unix Timestamp when a player was last active in the group (used to delete inactive groups)
	int creationDate = -1; // Unix Timestamp when the group was created
	bool showTagInChat = true; // Group Leaders can toggle if their group tag should be shown in tag if not set to force show them in the Chatconfig.json. This is saved here
	bool hasCustomChatColor = false; // Set to 1 to apply the custom tag color defined below. Otherwise it will be the handled by the Chat
	bool customChatColorAppliedByPlayer = false; // will be 1 if the tag was changed by a player to prevent people from joining groups to change their tag colors
	int chatColorR; // Custom Chat Tag Red color
	int chatColorG; // Custom Chat Tag Green color
	int chatColorB; // Custom Chat Tag Blue color
	bool hasATMAccount = false; // Tracks if the Player has a group account on Enhanced Banking
	int ATMBalance = 0; // Money on the groups bank account
	ref array<ref LBGroupMember> members = new array<ref LBGroupMember>(); // List of all Members in this group
	ref array<ref LBMarker> markers = new array<ref LBMarker>(); // List of all placed group Markers. This does not include pings. They are not persistent and not saved here.
	[NonSerialized()]
	ref array<ref LBMarker> pings = new array<ref LBMarker>();
	[NonSerialized()]
	int groupUpgradeCost = 0;
	[NonSerialized()]
	int maxPlayers;
	[NonSerialized()]
	int subGroupSize;
	[NonSerialized()]
	int subGroupCount;
	[NonSerialized()]
	int markerLimit = 0;
	[NonSerialized()]
	int plotpoleLimit = 0;

	[NonSerialized()]
	private ref LBGroupRef reference_;

#ifdef LBmaster_GroupDLCPlotpole
	int GetOwnedPlotpolesCount() {
		string tagLower = shortname + "";
		tagLower.ToLower();
		int count = 0;

		#ifdef RA_BaseBuilding_Scripts
			foreach (TerritoryHQ flag : TerritoryHQ.All_HQs) {
				if (!flag)
					continue;
				string flagTag = flag.ownerGroupTag + "";
				flagTag.ToLower();
				if (flagTag == tagLower) {
					count++;
				}
			}
		#else
			foreach (TerritoryFlag flag : TerritoryFlag.all_Flags) {
				if (!flag)
					continue;
				string flagTag = flag.ownerGroupTag + "";
				flagTag.ToLower();
				if (flagTag == tagLower) {
					count++;
				}
			}
		#endif


		
		LBLogger.Debug("Flagpole Count of " + shortname + ": " + count, "AdvancedGroups");
		return count;
	}
#endif

	void OnLoadServer() {
	}

	void ~LBGroup() {
		if (!g_Game || g_Game.IsServer())
			return;
		while (members.Get(0)) {
			delete members.Get(0);
			members.Remove(0);
		}
		while (markers.Get(0)) {
			delete markers.Get(0);
			markers.Remove(0);
		}
		while (pings.Get(0)) {
			delete pings.Get(0);
			pings.Remove(0);
		}
	}

	LBGroupRef GetReference() {
		if (!reference_) {
			reference_ = new LBGroupRef(shortname, this);
		}
		return reference_;
	}

	int GetTagHash() {
		return LBStringTools.ToLowerString(shortname).Hash();
	}

	void InitMarkers() {
		foreach (LBMarker marker : markers) {
			if (marker)
				marker.InitMarker();
		}
		foreach (LBGroupMember member : members) {
			if (member)
				member.InitMarker();
		}
		foreach (LBMarker ping : pings) {
			if (ping)
				ping.InitMarker();
		}
	}

	void RemoveMarkersForAdminPage() {
		foreach (LBMarker marker : markers) {
			if (marker)
				marker.RemoveFromAllList();
		}
		foreach (LBGroupMember member : members) {
			if (member)
				member.RemoveFromAllList();
		}
		foreach (LBMarker ping : pings) {
			if (ping)
				ping.RemoveFromAllList();
		}
	}

	void OnRPCClient(int type, ParamsReadContext ctx) {
		if (type == LBGroupRPCs.ADD) {
			LBMarker marker = new LBMarker();
			if (!marker.ReadFromCtx(ctx)) {
				LBLogger.Debug("Failed to receive new Marker from Server !", "AdvancedGroups");
				return;
			}
			AddMarkerLocal(marker);
		} else if (type == LBGroupRPCs.REMOVE) {
			int uid;
			if (!ctx.Read(uid)) {
				LBLogger.Debug("Failed to receive new Marker ID from Server !", "AdvancedGroups");
				return;
			}
			LBMarker mark = FindAnyMarkerByUID(uid);
			if (mark) {
				RemoveMarkerLocal(mark);
			}
		} else if (type == LBGroupRPCs.CHANGE_TAG_VISIBILITY) {
			bool enabled;
			if (!ctx.Read(enabled)) {
				LBLogger.Debug("Failed to receive Tag Visibility from Server !", "AdvancedGroups");
				return;
			}
			showTagInChat = enabled;
		} else if (type == LBGroupRPCs.ADD_CLIENT) {
			LBGroupMember member = new LBGroupMember();
			if (!member.ReadFromCtx(ctx)) {
				LBLogger.Debug("Failed to receive new Member from Server !", "AdvancedGroups");
				return;
			}
			AddMarkerLocal(member);
		} else if (type == LBGroupRPCs.UPGRADE) {
			int level1, maxPlayers1, subGroupCount1, subGroupSize1, maxMarkers1, plotpoleLimit1, upgradeCost1;
			if (!ctx.Read(level1) || !ctx.Read(maxPlayers1) || !ctx.Read(subGroupCount1) || !ctx.Read(subGroupSize1) || !ctx.Read(maxMarkers1) || !ctx.Read(plotpoleLimit1) || !ctx.Read(upgradeCost1)) {
				LBLogger.Debug("Failed to Read Upgrade Info", "AdvancedGroups");
				return;
			}
			level = level1;
			maxPlayers = maxPlayers1;
			subGroupCount = subGroupCount1;
			subGroupSize = subGroupSize1;
			markerLimit = maxMarkers1;
			plotpoleLimit = plotpoleLimit1;
			groupUpgradeCost = upgradeCost1;
			LB_Elevator_World elevator = GetElevatorWorld();
			if (elevator)
				elevator.OnGroupChanged();
		} else if (type == LBGroupRPCs.ATM_ACCOUNT_CHANGED) {
			bool hasAcc;
			if (!ctx.Read(hasAcc)) {
				LBLogger.Debug("Failed to get HasGroupATMAccount info !", "AdvancedGroups");
				return;
			}
			LBLogger.Debug("Successfully read HasGroupATMAccount. Now: " + hasAcc, "AdvancedGroups");
			this.hasATMAccount = hasAcc;
			elevator = GetElevatorWorld();
			if (elevator)
				elevator.OnGroupChanged();
		} else if (type == LBGroupRPCs.ATM_BALANCE_CHANGED) {
			int money;
			if (!ctx.Read(money)) {
				LBLogger.Debug("Failed to get money info !", "AdvancedGroups");
				return;
			}
			LBLogger.Debug("Successfully read money. Now: " + money, "AdvancedGroups");
			this.ATMBalance = money;
			elevator = GetElevatorWorld();
			if (elevator)
				elevator.OnGroupChanged();
		} else if (type > LBGroupRPCs.START_MARKER_RPC) {
			int uid2;
			if (!ctx.Read(uid2))
				return;
			LBLogger.Debug("Group RPC for MArker: " + type + " UID: " + uid2, "AdvancedGroups");
			LBMarker marker2 = FindAnyMarkerByUID(uid2);
			if (marker2)
				marker2.OnMarkerRPCClient(type, ctx);
		}
	}

	void OnPlayerOnline(PlayerBase player, PlayerIdentity identity) {}

	void OnPlayerOffline(PlayerBase player, string steamid) {}

	void KickPlayerClient(string steamid) {
		PromoteDemoteKickHelpter(steamid, LBGroupRPCs.KICK);
	}

	void DemotePlayerClient(string steamid) {
		PromoteDemoteKickHelpter(steamid, LBGroupRPCs.DEMOTE);
	}

	void PromotePlayerClient(string steamid) {
		PromoteDemoteKickHelpter(steamid, LBGroupRPCs.PROMOTE);
	}

	void PromoteDemoteKickHelpter(string steamid, int type) {
		ScriptRPC rpc = CreateRPCCall(type);
		rpc.Write(steamid);
		SendRPCToServer(rpc);
	}

	void LeaveGroupClient() {
		ScriptRPC rpc = CreateRPCCall(LBGroupRPCs.LEAVE);
		SendRPCToServer(rpc);
	}

	void UpgradeGroupClient() {
		ScriptRPC rpc = CreateRPCCall(LBGroupRPCs.UPGRADE);
		SendRPCToServer(rpc);
	}

	int GetUpgradeCost() {
		return groupUpgradeCost;
	}

	LBGroupMember GetMemberBySteamid(string steamid) {
		foreach (LBGroupMember member : members) {
			if (member.steamid == steamid)
				return member;
		}
		return null;
	}

	LBGroupMember GetDisabledMemberBySteamid(string steamid) {
		foreach (LBGroupMember member : members) {
			if (member.steamid == LBGroupMember.DISABLED_STEAMID_PREFIX + steamid)
				return member;
		}
		return null;
	}

	array<PlayerBase> GetOnlineMembersPlayerCharacters() {
		return null;
	}

	bool IsMember(string steamid) {
		return GetMemberBySteamid(steamid) != null;
	}

	bool AddMember(PlayerBase player) {
		if (player.GetLBGroup() != null)
			return false;
		return true;
	}

	void RemoveMember(PlayerBase player) {
		if (!player || !player.GetIdentity())
			return;
		string steamid = player.GetIdentity().GetPlainId();
		RemoveMember(steamid);
	}

	void RemoveMember(string steamid) {
		LBGroupMember member = GetMemberBySteamid(steamid);
		if (member == null)
			return;
		RemoveMember(member);
	}

	void RemoveMember(LBGroupMember member) {
		int uidd = member.uid;
		for (int i = 0; i < members.Count(); i++) {
			LBGroupMember mem = members.Get(i);
			if (!mem || mem.uid == uidd) {
				members.Remove(i);
				i--;
				if (mem)
					delete mem;
			}
		}
	}

	string GetLastActiveDate() {
		return LBDate.Init(lastActivity).ToFormattedString();
	}

	string GetCreatedDate() {
		return LBDate.Init(creationDate).ToFormattedString();
	}

	int GetMemberCount() {
		return members.Count();
	}

	string GetMemberString(int index, int column) {
		return members.Get(index).name;
	}

	int GetSubgroupMemberCount(int subGroup) {
		return GetSubgroupMembers(subGroup).Count();
	}

	void JoinSubgroupRequest(int grp) {
		ScriptRPC rpc = CreateRPCCall(LBGroupRPCs.JOIN_SUBGROUP);
		rpc.Write(grp);
		SendRPCToServer(rpc);
	}

	void MoveSubgroupRequest(int markerUid, int grp) {
		ScriptRPC rpc = CreateRPCCall(LBGroupRPCs.MOVE_SUBGROUP);
		rpc.Write(markerUid);
		rpc.Write(grp);
		SendRPCToServer(rpc);
	}

	bool IsPersistent() {
		return false;
	}

	array<ref LBGroupMember> GetSubgroupMembers(int subGroup) {
		if (!LBGroupMainConfig.Get.enableSubGroups)
			return members;
		array<ref LBGroupMember> memb = new array<ref LBGroupMember>();
		foreach (LBGroupMember member : members) {
			if (member.currentSubgroup == subGroup)
				memb.Insert(member);
		}
		return memb;
	}

	void WriteGroupToCtx(ParamsWriteContext ctx, bool steamids_ = true, bool markers_ = true, bool seePlayers = true) {
		ctx.Write(name);
		ctx.Write(shortname);
		ctx.Write(members.Count());
		LBLogger.Verbose("Writing Group to RPC. Members: " + members.Count() + " Markers: " + markers.Count() + " Pings: " + pings.Count() + " See Steamids: " + steamids_ + " See Markers: " + markers_ + " See Player Positions: " + seePlayers, "AdvancedGroups");
		foreach (LBGroupMember member : members) {
			member.WriteToCtx(ctx, steamids_, seePlayers);
		}
		if (markers_) {
			LBLogger.Verbose("Writing " + markers.Count() + " markers", "AdvancedGroups");
			ctx.Write(markers.Count());
			foreach (LBMarker marker : markers) {
				marker.WriteToCtx(ctx);
			}
			LBLogger.Verbose("Writing " + pings.Count() + " pings", "AdvancedGroups");
			ctx.Write(pings.Count());
			foreach (LBMarker ping : pings) {
				ping.WriteToCtx(ctx);
			}
		} else {
			LBLogger.Verbose("Writing no markers", "AdvancedGroups");
			ctx.Write(0);
			ctx.Write(0);
		}
		ctx.Write(level);
		ctx.Write(maxPlayers);
		ctx.Write(subGroupSize);
		ctx.Write(subGroupCount);
		ctx.Write(markerLimit);
		ctx.Write(plotpoleLimit);
		ctx.Write(showTagInChat);
		ctx.Write(creationDate);
		ctx.Write(lastActivity);
		ctx.Write(hasATMAccount);
		ctx.Write(ATMBalance);
		ctx.Write(hasCustomChatColor);
		ctx.Write(customChatColorAppliedByPlayer);
		ctx.Write(chatColorR);
		ctx.Write(chatColorG);
		ctx.Write(chatColorB);
		ctx.Write(groupUpgradeCost);
	}

	void ChangeTagColor(bool has, int r, int g, int b, bool byPlayer) {
		chatColorR = r;
		chatColorG = g;
		chatColorB = b;
		hasCustomChatColor = has;
		if (has)
			customChatColorAppliedByPlayer = byPlayer;
		LBGroupManager.Get().SaveGroup(this);
		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(has);
		rpc.Write(r);
		rpc.Write(g);
		rpc.Write(b);
		rpc.Write(customChatColorAppliedByPlayer);
		SendRPCToGroupMembers(rpc, LBGroupRPCs.CHANGE_TAG_COLOR);
	}

	bool ReadGroupFromCtx(ParamsReadContext ctx) {
		if (!ctx.Read(name))
			return false;
		if (!ctx.Read(shortname))
			return false;
		int count = 0;
		if (!ctx.Read(count))
			return false;
		for (int i = 0; i < count; i++) {
			LBGroupMember member = new LBGroupMember();
			if (!member.ReadFromCtx(ctx))
				return false;
			members.Insert(member);
		}
		count = 0;
		if (!ctx.Read(count))
			return false;
		for (i = 0; i < count; i++) {
			LBMarker marker = new LBMarker();
			if (!marker.ReadFromCtx(ctx))
				return false;
			markers.Insert(marker);
		}
		count = 0;
		if (!ctx.Read(count))
			return false;
		for (i = 0; i < count; i++) {
			marker = new LBMarker();
			if (!marker.ReadFromCtx(ctx))
				return false;
			pings.Insert(marker);
		}
		if (!ctx.Read(level))
			return false;
		if (!ctx.Read(maxPlayers))
			return false;
		if (!ctx.Read(subGroupSize))
			return false;
		if (!ctx.Read(subGroupCount))
			return false;
		if (!ctx.Read(markerLimit))
			return false;
		if (!ctx.Read(plotpoleLimit))
			return false;
		if (!ctx.Read(showTagInChat))
			return false;
		if (!ctx.Read(creationDate))
			return false;
		if (!ctx.Read(lastActivity))
			return false;
		if (!ctx.Read(hasATMAccount))
			return false;
		if (!ctx.Read(ATMBalance))
			return false;
		if (!ctx.Read(hasCustomChatColor))
			return false;
		if (!ctx.Read(customChatColorAppliedByPlayer))
			return false;
		if (!ctx.Read(chatColorR))
			return false;
		if (!ctx.Read(chatColorG))
			return false;
		if (!ctx.Read(chatColorB))
			return false;
		if (!ctx.Read(groupUpgradeCost))
			return false;
		return true;
	}

	void AddMarker(LBMarker marker) {
		if (markers.Count() >= markerLimit && marker.type != LBMarkerType.GROUP_PING) {
			SendErrorNotificationLOCAL("#lb_message_marker_limit_reached");
			return;
		}
		LBLogger.Debug("Sending Add Marker request to Server ...", "AdvancedGroups");
		ScriptRPC rpc = CreateRPCCall(LBGroupRPCs.ADD);
		marker.WriteToCtx(rpc);
		SendRPCToServer(rpc);
	}

	void ClearPing() {
		ScriptRPC rpc = CreateRPCCall(LBGroupRPCs.CLEAR_PING);
		SendRPCToServer(rpc);
	}

	void SendErrorNotificationLOCAL(string message, float show_time = 4) {
		NotificationSystem.AddNotificationExtended(show_time, "#lb_message_group_system", message, "set:ccgui_enforce image:MapDestroyed");
	}

	void RemoveMarker(LBMarker marker) {
		ScriptRPC rpc = CreateRPCCall(LBGroupRPCs.REMOVE);
		rpc.Write(marker.uid);
		SendRPCToServer(rpc);
	}

	void SendRPCToServer(ScriptRPC rpc) {
		PlayerBase pb = PlayerBase.Cast(g_Game.GetPlayer());
		if (!pb)
			return;
		rpc.Send(pb, LBGroupRPCs.GROUP_RPC, true);
	}

	ScriptRPC CreateRPCCall(int type) {
		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(type);
		return rpc;
	}

	void SendChatTagVisibilityRequest(bool visible) {
		ScriptRPC rpc = CreateRPCCall(LBGroupRPCs.CHANGE_TAG_VISIBILITY);
		rpc.Write(visible);
		SendRPCToServer(rpc);
	}

	void RenameTo(string newShortname, string newName) {

	}

	void SendPlayerInviteClient(string steamid) {
		ScriptRPC rpc = CreateRPCCall(LBGroupRPCs.INVITE);
		rpc.Write(steamid);
		SendRPCToServer(rpc);
	}

	void AddMarkerLocal(LBMarker marker) {
		if (marker.type == LBMarkerType.GROUP_PING) {
			pings.Insert(marker);
			marker.parentGroup = this;
			marker.InitMarker();
		} else if (marker.type == LBMarkerType.GROUP_MARKER) {
			markers.Insert(marker);
			marker.parentGroup = this;
			marker.InitMarker();
		} else if (marker.type == LBMarkerType.GROUP_PLAYER_MARKER) {
			LBGroupMember member = LBGroupMember.Cast(marker);
			if (!member)
				return;
			members.Insert(member);
			member.parentGroup = this;
			member.InitMarker();
		} else {
			LBLogger.Debug("Trying to add Marker to Group which is no Group Marker type. Type Got: " + marker.type, "AdvancedGroups");
		}

	}

	void RemoveMarkerLocal(LBMarker marker) {
		if (marker.type == LBMarkerType.GROUP_PING) {
			for (int i = 0; i < pings.Count(); i++) {
				LBMarker mark = pings.Get(i);
				if (mark && mark.uid == marker.uid) {
					pings.RemoveOrdered(i);
					i--;
					delete mark;
					if (!marker)
						break;
				}
			}
		} else if (marker.type == LBMarkerType.GROUP_MARKER) {
			for (i = 0; i < markers.Count(); i++) {
				mark = markers.Get(i);
				if (mark && mark.uid == marker.uid) {
					markers.Remove(i);
					i--;
					delete mark;
					if (!marker)
						break;
				}
			}
		} else if (marker.type == LBMarkerType.GROUP_PLAYER_MARKER) {
			LBGroupMember member = LBGroupMember.Cast(marker);
			if (!member)
				return;
			RemoveMember(member);
		} else {
			LBLogger.Debug("Trying to remove Marker form Group which is no Group Marker type. Type Got: " + marker.type, "AdvancedGroups");
		}
	}

	LBGroupLevel GetGroupLevel() {
		return LBGroupLevels.Get.FindLevelByUID(level);
	}

	LBMarker FindMarkerByUID(int uid) {
		foreach (LBMarker marker : markers) {
			if (marker.uid == uid)
				return marker;
		}
		return null;
	}

	LBMarker FindPingMarkerByUID(int uid) {
		foreach (LBMarker marker : pings) {
			if (marker.uid == uid)
				return marker;
		}
		return null;
	}

	LBGroupMember FindMemberByUID(int uid) {
		foreach (LBGroupMember member : members) {
			if (member.uid == uid)
				return member;
		}
		return null;
	}

	LBMarker FindAnyMarkerByUID(int uid) {
		LBLogger.Debug("Finding any Marker with UID: " + uid + " Markers: " + markers.Count() + " Members: " + members.Count() + " Pings: " + pings.Count(), "AdvancedGroups");
		LBMarker marker = FindMarkerByUID(uid);
		if (!marker)
			marker = FindMemberByUID(uid);
		if (!marker)
			marker = FindPingMarkerByUID(uid);
		LBLogger.Debug("Found Marker: " + marker, "AdvancedGroups");
		return marker;
	}

	bool FindNearestMarker(vector position, out LBMarker markero, out float distance) {
		if (markers.Count() == 0)
			return false;
		float bestDist = 0;
		LBMarker bestMarker = null;
		foreach (LBMarker marker : markers) {
			if (!bestMarker || vector.Distance(position, marker.position) < bestDist) {
				bestMarker = marker;
				bestDist = vector.Distance(position, marker.position) < bestDist;
			}
		}
		if (bestMarker) {
			markero = bestMarker;
			distance = bestDist;
			return true;
		}
		return false;
	}

	LBMarker AddGroupMarker(string name_, vector position, string icon, int color, string creatorId = "Server") {
		return null; // Implemented Serverside
	}

	bool RemoveGroupMarker(int uid) {
		return false;
	}

	bool RemoveGroupMarker(LBMarker marker) {
		return false;
	}

	void SendATMBalanceChanged() {
		ScriptRPC rpc = CreateRPCCall(LBGroupRPCs.ATM_BALANCE_CHANGED);
		rpc.Write(this.ATMBalance);
		SendRPCToGroupMembers(rpc);
	}

	void SendATMAccountChanged() {
		ScriptRPC rpc = CreateRPCCall(LBGroupRPCs.ATM_ACCOUNT_CHANGED);
		rpc.Write(this.hasATMAccount);
		SendRPCToGroupMembers(rpc);
	}

	void SendRPCToGroupMembers(ScriptRPC rpc, int otherRPCType = -1) {}
	void InitNumbers() {}
}
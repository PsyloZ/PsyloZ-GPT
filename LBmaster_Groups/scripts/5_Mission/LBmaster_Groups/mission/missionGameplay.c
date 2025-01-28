modded class MissionGameplay {

	// Global Chat
#ifndef LB_DISABLE_CHAT
	int currentChannel = 0;
	bool muted = false;
	bool setDefaultChannel = false;
	ref array<ref ChannelCfg> channels = new array<ref ChannelCfg>();
	static ref LBColorConfig battleyeChatColor = new LBColorConfig();

	ref map<string, int> lastSentClient = new map<string, int>();
#endif
	ref LBCompassHud compassHud;
	bool randomInitialized = false;
	bool local_speaking = false;
	int serverToClientTimeOffset = 0;

	ref LB_GPSHud gpsHud;

	int lastingameTime = 0;
	static int acceleration = 0;

	const int PING_TIMEOUT = 1000;
	int lastPing = 0;

	void MissionGameplay() {
		LBLogger.Debug("Initializing", "AdvancedGroups");
		LBLayoutConfig_.Event_StreamerModeChanged.Insert(OnStreamerModeChange);
		g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(LBMarker.UpdateAllMarkersSlow, 1000, true);
		g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(UpdateTimeAcceleration, 60000, true);
#ifndef LB_DISABLE_CHAT
		setDefaultChannel = false;
#endif
#ifdef PVEZ
		LBLogger.Debug("PVEZ Mod found", "AdvancedGroups");
#else
		LBLogger.Debug("PVEZ Mod not found", "AdvancedGroups");
#endif
		randomInitialized = false;
		LBLogger.Debug("Finished Initializing", "AdvancedGroups");
	}

	override void OnInitLB() {
		super.OnInitLB();
		LBTextLengthCalculator.Get();
		SendTextureRPC();
		g_Game.RPCSingleParam(null, LBGroupRPCs.CONFIG_SYNC_SERVER_TIME, new Param1<bool>(true), true);
#ifndef LB_DISABLE_CHAT
		g_Game.RPCSingleParam(null, LBGroupRPCs.LB_GLOBAL_MUTELIST, new Param1<bool>(true), true);
#endif
	}

	void ~MissionGameplay() {
		LBLogger.Debug("Cleanup...", "AdvancedGroups");
		if (LBLayoutConfig_.Event_StreamerModeChanged)
			LBLayoutConfig_.Event_StreamerModeChanged.Remove(OnStreamerModeChange);
		LBStaticMarkerManagerClient.Delete();
		LBPlayerList.Delete();
		if (g_Game && g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM))
			g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(LBMarker.UpdateAllMarkersSlow);
		if (compassHud)
			delete compassHud;
		if (g_Game && g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM))
			g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(UpdateTimeAcceleration);
		LBTextLengthCalculator.Delete();
		LBLogger.Debug("Cleanup finished", "AdvancedGroups");
	}

	void SendTextureRPC() {
		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(!LBMarkerVisibilityManager.Get.disableShowClantextures);
		rpc.Send(null, LBGroupRPCs.CLAN_CLOTHING_UPDATE, true);
	}

	void OnStreamerModeChange(bool enabled) {
		LBMarker.streamerMode = enabled;
		LBMarker.UpdateAllMarkersSlow();
	}

	void UpdateTimeAcceleration() {
		int year, month, day, hour, minute;
		g_Game.GetWorld().GetDate(year, month, day, hour, minute);
		int time = hour * 60 + minute;
		while (lastingameTime > time)
			time += 1440;
		if (lastingameTime == 0) {
			lastingameTime = time % 1440;
			return;
		}
		acceleration = time - lastingameTime;
		lastingameTime = time % 1440;
	}

	void SendTestBEMessage() {
		ChatMessageEventParams message = new ChatMessageEventParams(CCAdmin, "Original", "Test MEssage", "");
		m_Chat.Add(message);
		message = new ChatMessageEventParams(CCBattlEye, "Original", "Test MEssage", "");
		m_Chat.Add(message);
		message = new ChatMessageEventParams(CCAdmin, "LBmaster", "RGB:0:255:0:Test MEssage", "");
		m_Chat.Add(message);
		message = new ChatMessageEventParams(CCBattlEye, "LBmaster", "RGB:0:255:0:Test MEssage", "");
		m_Chat.Add(message);
	}

#ifndef LB_DISABLE_CHAT

	string GetDirectChannelName() {
		foreach (ChannelCfg channel : channels) {
			if (channel.directChannel)
				return channel.channelName;
		}
		return "UNKNOWN";
	}

	void OnChannelConfigReceived(ParamsReadContext ctx) {
		LBLogger.Debug("Received Channel RPC", "AdvancedGroups");
		int count;
		if (!ctx.Read(count))
			return;
		channels.Clear();
		int def = 0;
		for (int i = 0; i < count; i++) {
			ChannelCfg cfgchannel;
			if (!ctx.Read(cfgchannel))
				return;
			channels.Insert(cfgchannel);
			if (cfgchannel.defaultChannel)
				def = i;
		}
		LBLogger.Debug("Received " + channels.Count() + " Channels.", "AdvancedGroups");
		if (!setDefaultChannel) {
			currentChannel = def;
			UpdateChannel();
			setDefaultChannel = true;
		}
		if (!ctx.Read(battleyeChatColor)) {
			LBLogger.Debug("Could not get Battleye Chat color from Server !", "AdvancedGroups");
		}
	}
#endif

	bool GetServerInfoLB(out string ip, out int port) {
		MenuData menu_data = g_Game.GetMenuData();
		GetServersResultRow info = OnlineServices.GetCurrentServerInfo();
		if (g_Game.GetHostAddress(ip, port))
			return true;

		if (info) {
			ip = info.m_HostIp;
			port = info.m_HostPort;
			return true;
		} else if (menu_data && menu_data.GetLastPlayedCharacter() != GameConstants.DEFAULT_CHARACTER_MENU_ID) {
			int char_id = menu_data.GetLastPlayedCharacter();
			string address, name;

			menu_data.GetLastServerAddress(char_id, address);
			port = menu_data.GetLastServerPort(char_id);
			ip = address;
			return true;
		}
		return false;
	}

	override void OnUpdate(float timeslice) {
		bool openMapInGroupMenu = false;
		if (GetUApi() && GetUApi().GetInputByName("UALBMGroupOpenMapGroup").LocalPress())
			openMapInGroupMenu = true;
		if (GetUApi() && GetUApi().GetInputByName("UALBMGroupOpenMap").LocalPress() || openMapInGroupMenu) {
			if (LBPlayerUtils.IsClientPlayerAlive()) {
				LBGroupUI openedMapUI = LBGroupUI.Cast(LBMenuManager.Get().GetPersistentMenu(LBGroupUI));
				if (g_Game.GetUIManager().GetMenu() && g_Game.GetUIManager().GetMenu() == openedMapUI && !openMapInGroupMenu) {
					if (!openedMapUI.typing)
						openedMapUI.CloseMe();
				} else if (!g_Game.GetUIManager().GetMenu() && !g_Game.GetUIManager().IsCursorVisible()) {
					LBMenuManager.Get().OpenMenu(LBGroupUI);
					if (openMapInGroupMenu) {
						openedMapUI.OpenGroupPage();
					}
				}
			}
		} else if (GetUApi() && GetUApi().GetInputByName("UALBMGroupTacticalPing").LocalPress()) {
			if (IsNoMenuOpen()) {
				int now = g_Game.GetTime();
				if (now - PING_TIMEOUT > lastPing) {
					lastPing = now;
					AddPing();
				}
			}
		} else if (GetUApi() && GetUApi().GetInputByName("UALBMGroupTacticalPingClear").LocalPress()) {
			if (IsNoMenuOpen())
				ClearPing();
		} else if (GetUApi() && GetUApi().GetInputByName("UALBMGroupAcceptInvite").LocalPress()) {
			if (IsNoMenuOpen())
				GetElevatorMission().AcceptGroupInvite();
		} else if (GetUApi() && GetUApi().GetInputByName("UALBMGroupToggleCompass").LocalPress()) {
			if (IsNoMenuOpen())
				ToggleCompass();
		} else if (GetUApi() && GetUApi().GetInputByName("UALBMGroupTogglePlayerList").LocalPress()) {
			if (IsNoMenuOpen())
				TogglePlayerList();
		} else if (GetUApi() && GetUApi().GetInputByName("UALBMGroupToggleMiniMap").LocalPress()) {
			if (IsNoMenuOpen())
				ToggleGPS();
		} else if (GetUApi() && GetUApi().GetInputByName("UALBMGroupToggleVisibility").LocalPress()) {
			if (!g_Game.GetUIManager().GetMenu() && !g_Game.GetUIManager().IsCursorVisible()) {
				LBMarkerVisibilityManager.Get.GetNextState();
				LBMarker.UpdateAllMarkersSlow();
				string state = LBMarkerVisibilityManager.Get.GetCurrentStateName();
				PlayerBase pb = PlayerBase.Cast(g_Game.GetPlayer());
				pb.MessageImportant("#lb_ag_info_marker_state " + state);
			}
		} else if (GetUApi() && GetUApi().GetInputByName("UALBMGroupDeleteMarker").LocalPress()) {
			openedMapUI = LBGroupUI.Cast(LBMenuManager.Get().GetPersistentMenu(LBGroupUI));
			if (g_Game.GetUIManager().GetMenu() && g_Game.GetUIManager().GetMenu() == openedMapUI) {
				if (!openedMapUI.typing)
					openedMapUI.addPopup.DeleteMarkerUnderMouse();
			}
		}
#ifndef LB_DISABLE_CHAT
		if (GetUApi() && IsNoMenuOpen()) {
			UAInput switchChatChannel = GetUApi().GetInputByName("UALBMSwitchChatChannel");
			if (switchChatChannel && switchChatChannel.LocalPress()) {
				if (channels.Count() > 1) {
					SwitchNextChannel();
					ChannelCfg channel = GetCurrentChannel();
					string currentChannelName = "#lb_ag_unknown";
					if (channel)
						currentChannelName = channel.channelName;
					NotificationSystem.AddNotificationExtended(4.0, "#lb_global_chat", "#lb_chat_channel " + currentChannelName, "set:ccgui_enforce image:MapUserMarker");
					//g_Game.Chat("Channel: " + GetCurrentChannel(), "colorAction");
				}
			}
		}
#endif

		if (compassHud) {
			compassHud.UpdateHud();
		}
		if (LBGroupMainConfig.Get && LBGroupMainConfig.Get.enablePlayerList) {
			LBPlayerList.Get().UpdateVisibility();
		}
		LBMarker.UpdateAllMarkers();
#ifndef LB_DISABLE_CHAT
		if (m_Chat) {
			m_Chat.UpdateChatVisibility();
		}
#endif
		//*/
		if (gpsHud)
			gpsHud.UpdateHud();
		if (g_Game.GetPlayer()) {
			bool speaking = false;
			if (g_Game.GetPlayer().IsPlayerSpeaking() > 0.001)
				speaking = true;
			if (speaking != local_speaking) {
				g_Game.RPCSingleParam(null, LBGroupRPCs.VON_CHANGE, new Param1<bool>(speaking), true);
			}
			local_speaking = speaking;
		}
		super.OnUpdate(timeslice);
	}

	bool IsNoMenuOpen() {
		return g_Game && g_Game.GetUIManager() && !g_Game.GetUIManager().GetMenu();
	}

	void ToggleCompass() {
		if (LBGroupMainConfig.Get && LBGroupMainConfig.Get.enableCompassHud) {
			LBMarkerVisibilityManager.Get.compassEnabled = !LBMarkerVisibilityManager.Get.compassEnabled;
			LBMarkerVisibilityManager.Loader.Save();
		}
	}

	void OnGPSAndCompassChange() {
		if (LBGroupMainConfig.Get.enableCompassHud) {
			LBLogger.Debug("Creating Compass Hud", "AdvancedGroups");
			compassHud = new LBCompassHud();
			compassHud.InitWidgets();
		} else if (compassHud) {
			delete compassHud;
		}
		LBLogger.Debug("Loading No Build Zones...", "AdvancedGroups");

		//g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SendTestBEMessage, 30000, false);

		if (LBGroupMainConfig.Get.enableGPS) {
			gpsHud = new LB_GPSHud();
			gpsHud.Init();
		} else if (gpsHud) {
			delete gpsHud;
		}
	}

	void ToggleGPS() {
		if (LBGroupMainConfig.Get.enableGPS) {
			LBMarkerVisibilityManager.Get.gpsEnabled = !LBMarkerVisibilityManager.Get.gpsEnabled;
			LBMarkerVisibilityManager.Loader.Save();
		}
	}

	void TogglePlayerList() {
		if (LBGroupMainConfig.Get.enablePlayerList) {
			LBMarkerVisibilityManager.Get.playerlistEnabled = !LBMarkerVisibilityManager.Get.playerlistEnabled;
			LBMarkerVisibilityManager.Loader.Save();
		}
	}

	void AddPing() {
		PlayerBase pb = PlayerBase.Cast(g_Game.GetPlayer());
		if (!pb || !pb.GetLBGroup())
			return;
		LBGroup grp = pb.GetLBGroup();
		string name;
		g_Game.GetPlayerName(name);
		LBMarker marker = new LBMarker();
		vector camPos = g_Game.GetCurrentCameraPosition();
		vector camDir = g_Game.GetCurrentCameraDirection().Normalized() * 2000.0;
		Object hitObj;
		vector hitPos, hitNormal;
		float fraction;
		PhxInteractionLayers layers = PhxInteractionLayers.ITEM_SMALL | PhxInteractionLayers.ITEM_LARGE | PhxInteractionLayers.VEHICLE_NOTERRAIN | PhxInteractionLayers.BUILDING | PhxInteractionLayers.CHARACTER | PhxInteractionLayers.VEHICLE | PhxInteractionLayers.ROADWAY | PhxInteractionLayers.FIREGEOM | PhxInteractionLayers.DOOR | PhxInteractionLayers.WATERLAYER | PhxInteractionLayers.TERRAIN | PhxInteractionLayers.FENCE | PhxInteractionLayers.AI;
		DayZPhysics.RayCastBullet(camPos, camPos + camDir, layers, g_Game.GetPlayer(), hitObj, hitPos, hitNormal, fraction);
		marker.SetupMarker(LBMarkerType.GROUP_PING, name, "", hitPos);
		marker.colorR = 255;
		marker.colorG = 255;
		marker.colorB = 0;
		marker.icon = LBMarkerVisibilityManager.Get.pingMarkerIcon;
		marker.currentSubgroup = pb.GetMyGroupMarker().currentSubgroup;
		grp.AddMarker(marker);
	}

	void ClearPing() {
		PlayerBase pb = PlayerBase.Cast(g_Game.GetPlayer());
		if (!pb || !pb.GetLBGroup())
			return;
		LBGroup grp = pb.GetLBGroup();
		grp.ClearPing();
	}
#ifndef LB_DISABLE_CHAT
	void DisplayVoiceLevels(bool b) {
		m_VoiceLevels.Show(b);
	}

	ChannelCfg GetCurrentChannel() {
		return channels.Get(currentChannel);
	}

	void SendChatMessage(string message) {
		if (muted && message[0] != "!") {
			PlayerBase pb = PlayerBase.Cast(g_Game.GetPlayer());
			if (!pb)
				return;
			pb.MessageImportant("#lb_ag_err_you_are_muted");
			return;
		}
		ChannelCfg cfgchannel = channels.Get(currentChannel);
		if (!cfgchannel) {
			LBLogger.Debug("Failed to get Channel Config for Channel " + currentChannel, "AdvancedGroups");
			return;
		}
		if (message[0] == "!") {
			g_Game.ChatPlayer(message);
			message = "+" + message;
		} else if (cfgchannel.directChannel) {
			g_Game.ChatPlayer(message);
			message = "+" + message;
		} else {
			message = "+" + message;
			g_Game.ChatPlayer(message);
		}
		if (g_Game.IsMultiplayer()) {
			ScriptRPC rpc = new ScriptRPC();
			rpc.Write(currentChannel);
			rpc.Write(message);
			rpc.Send(NULL, LBGroupRPCs.LB_GLOBAL_CHAT, true);
			LBLogger.Debug("Sending Multiplayer Chat Message", "AdvancedGroups");
		} else {
			string name;
			g_Game.GetPlayerName(name);
			ChatMessageEventParams chat_params = new ChatMessageEventParams(CCDirect, name, message, "");
			m_Chat.Add(chat_params);
			LBLogger.Debug("Sending Singleplayer Chatmessage", "AdvancedGroups");
		}
	}

	void SwitchNextChannel() {
		currentChannel++;
		UpdateChannel();
	}

	void UpdateChannel() {
		if (!HasWritableChannel(channels))
			return;
		currentChannel = currentChannel % channels.Count();
		ChannelCfg cfgchannel = channels.Get(currentChannel);
		if (cfgchannel.groupChannel) {
			PlayerBase pb;
			if (!g_Game.GetPlayer() || !Class.CastTo(pb, g_Game.GetPlayer())) {
				SwitchNextChannel();
				return;
			}
			if (!pb.GetLBGroup()) {
				SwitchNextChannel();
				return;
			}
		}
		if (!cfgchannel.canReceiveMessagesFromPlayers || (cfgchannel.writeChannelPermission != "" && !LBAdmins.Get().HasPermission(cfgchannel.writeChannelPermission)))
			SwitchNextChannel();
	}

	bool HasWritableChannel(array<ref ChannelCfg> channels_) {
		if (!channels_ || channels_.Count() == 0)
			return false;
		foreach (ChannelCfg channel : channels_) {
			if (channel.canReceiveMessagesFromPlayers && (channel.writeChannelPermission == "" || LBAdmins.Get().HasPermission(channel.writeChannelPermission)))
				return true;
		}
		return false;
	}
#endif

}

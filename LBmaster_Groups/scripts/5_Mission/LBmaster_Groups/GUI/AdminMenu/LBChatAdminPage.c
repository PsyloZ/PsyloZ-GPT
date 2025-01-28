#ifndef LB_DISABLE_CHAT
[RegisterLBAdminPage(LBChatAdminPage, "LBmaster_Groups/logo/logo.paa", "#lb_ag_admin_menu_chat", "chat.view")]
class LBChatAdminPage : LBAdmin_Menu_Page {

	ref array<ref Param2<string, string>> onlinePlayerList = new array<ref Param2<string, string>>();
	TextListboxWidget list_bad_words, list_prefix_members, list_muted, list_online;
	SliderWidget slider_be_color_a, slider_be_color_r, slider_be_color_g, slider_be_color_b, slider_channel_color_a, slider_channel_color_r, slider_channel_color_g, slider_channel_color_b, slider_prefix_color_r, slider_prefix_color_g, slider_prefix_color_b;
	XComboBoxWidget combo_channel, combo_prefix;
	ButtonWidget btn_save, btn_add_word, btn_remove_word, btn_add_steamid, btn_remove_steamid, btn_unmute_selected, btn_mute_steamid, btn_mute_selected, btn_delete_prefix, btn_create_prefix, btn_delete_channel, btn_create_channel;
	CheckBoxWidget chckbx_display_tags, chckbx_force_display_tags, chckbx_allow_vote, chckbx_filter_badwords, chckbx_block_filtered_msg, chckbx_global, chckbx_group, chckbx_direct, chckbx_default, chckbx_channel_muted;
	EditBoxWidget input_min_players_online, input_mute_time, input_min_players_voting, input_block_message, input_mute_bad_word, input_add_bad_word, input_channel_name, input_prefix_name, input_permission, input_add_to_prefix, input_mute_duration, input_mute_steamid, input_search_online, input_slow_mode_seconds;
	Widget battleye_color_preview, channel_color_preview, prefix_color_preview;

	override void OnShow() {
		FillOnlinePlayers();
		linked.LoadLinkedVars();
	}

	override void RegisterAllLinkedVars() {

		ApplyWidgetPermission("panel_general", "chat.change");
		ApplyWidgetPermission("panel_channel", "chat.change");
		ApplyWidgetPermission("panel_prefix", "chat.prefix.change");
		ApplyWidgetPermission("panel_mute", "chat.mute");

		linked.RegisterLinkedVar("GetConfig().displayGroupTagsInfrontOfName", chckbx_display_tags);
		linked.RegisterLinkedVar("GetConfig().forceDisplayGroupTagsInChat", chckbx_force_display_tags);
		linked.RegisterLinkedVar("GetConfig().enableMuteVote", chckbx_allow_vote);
		linked.RegisterLinkedVar("GetConfig().muteVoteMinPlayers", input_min_players_online);
		linked.RegisterLinkedVar("GetConfig().muteVotePercentile", input_min_players_voting);
		linked.RegisterLinkedVar("GetConfig().muteVoteMuteTimeMins", input_mute_time);
		linked.RegisterLinkedVar("GetConfig().colorBattleyeMessage.a", slider_be_color_a).SetChangeTrigger("UpdateBattleyeColorPreview()");
		linked.RegisterLinkedVar("GetConfig().colorBattleyeMessage.r", slider_be_color_r).SetChangeTrigger("UpdateBattleyeColorPreview()");
		linked.RegisterLinkedVar("GetConfig().colorBattleyeMessage.g", slider_be_color_g).SetChangeTrigger("UpdateBattleyeColorPreview()");
		linked.RegisterLinkedVar("GetConfig().colorBattleyeMessage.b", slider_be_color_b).SetChangeTrigger("UpdateBattleyeColorPreview()");
		linked.RegisterLinkedVar("GetConfig().enabledBadWordsCensor", chckbx_filter_badwords);
		linked.RegisterLinkedVar("GetConfig().blockBadWordContainingMessages", chckbx_block_filtered_msg);
		linked.RegisterLinkedVar("GetConfig().badWordsBlockedMessage", input_block_message);
		linked.RegisterLinkedVar("GetConfig().badWordsMuteTime", input_mute_bad_word);
		linked.RegisterLinkedList("GetConfig().badWords", list_bad_words, btn_add_word, btn_remove_word, input_add_bad_word);
		linked.RegisterLinkedList("GetConfig().prefixGroups", combo_prefix, btn_create_prefix, btn_delete_prefix).SetFunctions("RemoveCurrentPrefix", "CreateNewPrefix", "GetPrefixGroupCount", "GetPrefixGroup");
		linked.RegisterLinkedVar("GetCurrentPrefixGroup().colorR", slider_prefix_color_r).SetReloadTrigger(combo_prefix).SetChangeTrigger("UpdatePrefixColorPreview()");
		linked.RegisterLinkedVar("GetCurrentPrefixGroup().colorG", slider_prefix_color_g).SetReloadTrigger(combo_prefix).SetChangeTrigger("UpdatePrefixColorPreview()");
		linked.RegisterLinkedVar("GetCurrentPrefixGroup().colorB", slider_prefix_color_b).SetReloadTrigger(combo_prefix).SetChangeTrigger("UpdatePrefixColorPreview()");
		linked.RegisterLinkedVar("GetCurrentPrefixGroup().prefix", input_prefix_name).SetExtraOutput(combo_prefix).SetReloadTrigger(combo_prefix);
		linked.RegisterLinkedVar("GetCurrentPrefixGroup().permissionToApplyGroup", input_permission).SetReloadTrigger(combo_prefix);
		linked.RegisterLinkedList("GetCurrentPrefixGroup().members", list_prefix_members, btn_add_steamid, btn_remove_steamid, input_add_to_prefix).SetReloadTrigger(combo_prefix);
		linked.RegisterLinkedList("GetConfig().channels", combo_channel, btn_create_channel, btn_delete_channel).SetFunctions("RemoveCurrentChannel", "CreateNewChannel", "GetChannelCount", "GetChannelName");
		linked.RegisterLinkedVar("GetCurrentChannelCfg().channelName", input_channel_name).SetExtraOutput(combo_channel).SetReloadTrigger(combo_channel);
		linked.RegisterLinkedVar("GetCurrentChannelCfg().channelColor.a", slider_channel_color_a).SetReloadTrigger(combo_channel).SetChangeTrigger("UpdateChannelColorPreview()");
		linked.RegisterLinkedVar("GetCurrentChannelCfg().channelColor.r", slider_channel_color_r).SetReloadTrigger(combo_channel).SetChangeTrigger("UpdateChannelColorPreview()");
		linked.RegisterLinkedVar("GetCurrentChannelCfg().channelColor.g", slider_channel_color_g).SetReloadTrigger(combo_channel).SetChangeTrigger("UpdateChannelColorPreview()");
		linked.RegisterLinkedVar("GetCurrentChannelCfg().channelColor.b", slider_channel_color_b).SetReloadTrigger(combo_channel).SetChangeTrigger("UpdateChannelColorPreview()");
		linked.RegisterLinkedVar("GetCurrentChannelCfg().globalChannel", chckbx_global).SetReloadTrigger(combo_channel);
		linked.RegisterLinkedVar("GetCurrentChannelCfg().groupChannel", chckbx_group).SetReloadTrigger(combo_channel);
		linked.RegisterLinkedVar("GetCurrentChannelCfg().directChannel", chckbx_direct).SetReloadTrigger(combo_channel);
		linked.RegisterLinkedVar("GetCurrentChannelCfg().defaultChannel", chckbx_default).SetReloadTrigger(combo_channel);
		linked.RegisterLinkedVar("GetCurrentChannelCfg().muted", chckbx_channel_muted).SetReloadTrigger(combo_channel);
		linked.RegisterLinkedVar("GetCurrentChannelCfg().slowModeSecondsBetweenMessages", input_slow_mode_seconds).SetReloadTrigger(combo_channel);
		linked.RegisterLinkedList("GetMutes().mutedPlayers", list_muted).SetColumnCount(3).SetFunctions("", "", "GetMutedCount", "GetMutedString");
		linked.RegisterLinkedList("onlinePlayerList", list_online).SetColumnCount(2).SetSearchBar(input_search_online, "IsOnlinePlayerSearched").SetFunctions("", "", "GetOnlineCount", "GetOnlinePlayer");
	}

	LBMuteConfig_ GetMutes() {
		return LBMuteConfig.Get;
	}

	ChatConfig_ GetConfig() {
		return ChatConfig.Get;
	}

	void UpdateBattleyeColorPreview() {
		battleye_color_preview.SetColor(ARGB(slider_be_color_a.GetCurrent(), slider_be_color_r.GetCurrent(), slider_be_color_g.GetCurrent(), slider_be_color_b.GetCurrent()));
	}

	void UpdateChannelColorPreview() {
		channel_color_preview.SetColor(ARGB(slider_channel_color_a.GetCurrent(), slider_channel_color_r.GetCurrent(), slider_channel_color_g.GetCurrent(), slider_channel_color_b.GetCurrent()));
	}

	void UpdatePrefixColorPreview() {
		prefix_color_preview.SetColor(ARGB(255, slider_prefix_color_r.GetCurrent(), slider_prefix_color_g.GetCurrent(), slider_prefix_color_b.GetCurrent()));
	}

	override void OnRPC(Object object, int rpc_type, ParamsReadContext ctx) {
		if (rpc_type == LBmaster_Core_RPCs.CONFIG_SYNC) {
			linked.LoadLinkedVars();
		}
	}

	int GetOnlineCount() {
		return onlinePlayerList.Count();
	}

	bool StringContainsLower(string str1, string other) {
		str1.ToLower();
		other.ToLower();
		return str1.Contains(other);
	}

	bool IsOnlinePlayerSearched(int index, string search) {
		string name = onlinePlayerList.Get(index).param1;
		string steamid = onlinePlayerList.Get(index).param2;
		return StringContainsLower(name, search) || StringContainsLower(steamid, search);
	}

	string GetOnlinePlayer(int index, int column) {
		if (column == 0) {
			return onlinePlayerList.Get(index).param1;
		}
		return onlinePlayerList.Get(index).param2;
	}

	void FillOnlinePlayers() {
		if (!ClientData.m_PlayerList || !ClientData.m_PlayerList.m_PlayerList)
			return;
		array<ref SyncPlayer> list = ClientData.m_PlayerList.m_PlayerList;
		onlinePlayerList.Clear();
		foreach (SyncPlayer player : list) {
			onlinePlayerList.Insert(new Param2<string, string>(player.m_PlayerName, player.m_UID));
		}
	}

	void MutePlayer(string steamid = "") {
		if (steamid == "") {
			int row = linked.SearchedIndexToListIndex(input_search_online, list_online.GetSelectedRow());
			if (row < 0 || row >= onlinePlayerList.Count())
				return;
			steamid = onlinePlayerList.Get(row).param2;
		} else {
			input_mute_steamid.SetText("");
		}
		int duration = input_mute_duration.GetText().ToInt();
		if (duration <= 0)
			return;
		g_Game.RPCSingleParam(null, LBGroupRPCs.ADMIN_MUTE_STEAMID, new Param2<string, int>(steamid, duration), true);
		input_mute_duration.SetText("");
	}

	void UnmuteSelectedPlayer() {
		int row = list_muted.GetSelectedRow();
		if (row < 0 || row >= GetMutes().mutedPlayers.Count())
			return;
		string steamid = GetMutes().mutedPlayers.Get(row).param1;
		g_Game.RPCSingleParam(null, LBGroupRPCs.ADMIN_UNMUTE_PLAYER, new Param1<string>(steamid), true);
	}

	override bool OnClick(Widget w, int x, int y, int button) {
		super.OnClick(w, x, y, button);
		if (w == btn_mute_selected) {
			MutePlayer();
			return true;
		} else if (w == btn_mute_steamid) {
			MutePlayer(input_mute_steamid.GetText());
			return true;
		} else if (w == btn_unmute_selected) {
			UnmuteSelectedPlayer();
			return true;
		} else if (w == btn_save) {
			ChatConfig.Loader.Save();
		} else if (w == btn_create_prefix) {
			linked.OnVarChange(combo_prefix, -1);
		} else if (w == btn_create_channel) {
			linked.OnVarChange(combo_channel, -1);
		}
		return false;
	}

	ChannelCfg GetCurrentChannelCfg() {
		int current = combo_channel.GetCurrentItem();
		if (current < 0 || current >= combo_channel.GetNumItems())
			return null;
		return ChatConfig.Get.channels.Get(current);
	}

	PrefixGroup GetCurrentPrefixGroup() {
		int current = combo_prefix.GetCurrentItem();
		if (current < 0 || current >= combo_prefix.GetNumItems())
			return null;
		return ChatConfig.Get.prefixGroups.Get(current);
	}
}
#endif
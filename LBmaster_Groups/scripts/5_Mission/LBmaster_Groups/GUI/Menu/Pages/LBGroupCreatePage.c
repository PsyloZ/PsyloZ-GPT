class LBGroupCreatePage : LBGroupPage {

	EditBoxWidget input_groupname, input_groupnametag;
	ButtonWidget btn_create, btn_accept;
	TextWidget txt_obfName;

	override bool InitPage(LBGroupUI parentUI) {
		bool worked = super.InitPage(parentUI, 1, 0, "#lb_page_group", false, 450);
		if (buttonWidget)
			parentUI.groupButton = buttonWidget;
		return worked;
	}

	override bool OnClick(Widget w) {
		if (w == btn_create) {
			string groupname = input_groupname.GetText();
			string grouptag = input_groupnametag.GetText();
			SendCreateGroupRPC(groupname, grouptag);
			return true;
		} else if (w == btn_accept) {
			GetElevatorMission().AcceptGroupInvite();
			SetInviteButton(false, "");
		}
		return false;
	}

	void SetInviteButton(bool show, string group) {
		btn_accept.Show(show);
		btn_accept.SetText(LBTranslatedString("#lb_ag_invite_accept", {"%name%", group}).Get());
	}

	override bool OnTopButtonClicked(Widget w) {
		if (super.OnTopButtonClicked(w)) {
			PlayerBase pb = PlayerBase.Cast(g_Game.GetPlayer());
			if (!pb)
				return false;
			return pb.GetLBGroup() == null;
		}
		return false;
	}

	override bool CanDisplayButton() {
		return LBGroupMainConfig.Get.IsGroupCreationEnabled();
	}

	override void InitMainWidget() {
		ConnectClassWidgetVariables(this, rootWidget, {"rootWidget", "buttonWidget"});
		TextWidget groupCostWidget = TextWidget.Cast(rootWidget.FindAnyWidget("groupCreationInfo"));
		groupCostWidget.SetText("#lb_group_create_info " + LBCurrencyConfig.Get.GetFormattedMoneyString(LBGroupMainConfig.Get.groupCreationCost));

		txt_obfName.Show(LBGroupMainConfig.Get.groupManagePageObfuscatePlayernames);
		txt_obfName.SetText("#lb_invite_name " + GetObfName());
	}

	string GetObfName() {
		string steamid = LBAdmins.Get().GetMySteamid();
		foreach (SyncPlayer player : ClientData.m_PlayerList.m_PlayerList) {
			if (player.m_UID == steamid) {
				return LBPlayerNameObfuscation.GetObfuscatedName(player.m_PlayerName, player.m_UID);
			}
		}
		return "";
	}

	void SendCreateGroupRPC(string name, string tag) {
		g_Game.RPCSingleParam(null, LBGroupRPCs.GROUP_CREATE, new Param2<string, string>(name, tag), true);
	}

}
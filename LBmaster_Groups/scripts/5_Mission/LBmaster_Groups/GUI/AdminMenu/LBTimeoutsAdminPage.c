[RegisterLBAdminPage(LBTimeoutsAdminPage, "LBmaster_Groups/logo/logo.paa", "#lb_ag_admin_menu_timeouts", "groups.timeout.change")]
class LBTimeoutsAdminPage : LBAdmin_Menu_Page {

	ButtonWidget btn_reset_all, btn_save;
	CheckBoxWidget chckbx_enabled;
	EditBoxWidget input_different, input_same;

	override array<typename> GetEditedConfigs() {
		return {LBGroupTimeoutConfig};
	}

	override void OnShow() {
		super.OnShow();
		linked.LoadLinkedVars();
	}

	override void RegisterAllLinkedVars() {
		linked.RegisterLinkedVar("GetConfig().enableTimeout", chckbx_enabled);
		linked.RegisterLinkedVar("GetConfig().timeoutDifferentGroupDurationSeconds", input_different);
		linked.RegisterLinkedVar("GetConfig().timeoutSameGroupDurationSeconds", input_same);

	}

	override bool OnClick(Widget w, int x, int y, int button) {
		super.OnClick(w, x, y, button);
		if (w == btn_reset_all) {
			g_Game.RPCSingleParam(null, LBGroupRPCs.ADMIN_CLEAR_TIMEOUTS, new Param1<bool>(true), true);
			return true;
		}
		return false;
	}

	LBGroupTimeoutConfig_ GetConfig() {
		return LBGroupTimeoutConfig.Get;
	}
}
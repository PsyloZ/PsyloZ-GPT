[RegisterLBAdminPage(LBLevelsAdminPage, "LBmaster_Groups/logo/logo.paa", "#lb_ag_admin_menu_levels", "group.levels.change")]
class LBLevelsAdminPage : LBAdmin_Menu_Page {

	ButtonWidget btn_save;
	TextListboxWidget list_levels;
	ButtonWidget btn_add, btn_remove, btn_up, btn_down;
	EditBoxWidget edit_max, edit_cost, edit_sub_count, edit_sub_size, edit_markers, edit_pings, edit_plotpole;

	override array<typename> GetEditedConfigs() {
		return {LBGroupLevels};
	}

	override void OnShow() {
		super.OnShow();
		linked.LoadLinkedVars();
	}

	override void RegisterAllLinkedVars() {
		linked.RegisterLinkedList("GetConfig().allLevels", list_levels, btn_add, btn_remove).SetFunctions("RemoveCurrentLevel", "CreateNewLevel", "GetLevelCount", "GetLevel");
		linked.RegisterListManager("GetConfig().allLevels", new LBListManager<ref LBGroupLevel>());
		linked.RegisterLinkedVar("GetConfig().allLevels[list_levels].maxPlayerCount", edit_max);
		linked.RegisterLinkedVar("GetConfig().allLevels[list_levels].upgradeCost", edit_cost);
		linked.RegisterLinkedVar("GetConfig().allLevels[list_levels].subgroupCount", edit_sub_count);
		linked.RegisterLinkedVar("GetConfig().allLevels[list_levels].subgroupSize", edit_sub_size);
		linked.RegisterLinkedVar("GetConfig().allLevels[list_levels].groupMarkerLimitAdded", edit_markers);
		linked.RegisterLinkedVar("GetConfig().allLevels[list_levels].groupPingsLimitAdded", edit_pings);
		linked.RegisterLinkedVar("GetConfig().allLevels[list_levels].groupPlotpolesLimitAdded", edit_plotpole);
	}

	LBGroupLevels_ GetConfig() {
		return LBGroupLevels.Get;
	}
}
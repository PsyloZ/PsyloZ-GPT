#ifdef LBmaster_GroupDLCPlotpole
[RegisterLBAdminPage(LBTerritoryAdminPage, "LBmaster_Groups/logo/logo.paa", "#lb_ag_admin_territory", "groups.territory.change")]
class LBTerritoryAdminPage : LBAdmin_Menu_Page {

	Widget panel_pvez;
	TextListboxWidget list_unauth_except, list_force_except, list_flags;
	TextWidget txt_refresh_out, txt_uptime_out;
	CheckBoxWidget chckbx_enable, chckbx_sync_cf, chckbx_reset_lifetime, chckbx_prevent_unauth, chckbx_force_in_terr, chckbx_prevent_build, chckbx_prevent_dismantle, chckbx_prevent_destroy, chckbx_lower_group_del, chckbx_instant_destroy, chckbx_return_flag, chckbx_allow_flag_dest, chckbx_allow_destroy_with, chckbx_instant_build, chckbx_auto_attach, chckbx_auto_raise, chckbx_display_map, chckbx_allow_flag_lower, chckbx_unclaimed_dismantle, chckbx_unclaimed_destroy;
	EditBoxWidget edit_refresh_time, edit_uptime, edit_max_dismantle, edit_max_lower, edit_radius_pvp, edit_up_pvp, edit_down_pvp, edit_dist_enemy, edit_dist_friendly, edit_max_count, edit_down_pve, edit_up_pve, edit_radius_pve;
	ButtonWidget btn_add_unauth_except, btn_del_unauth_except, btn_add_force_except, btn_del_force_except, btn_add_flag, btn_del_flag;

	override array<typename> GetEditedConfigs() {
		return {LBTerritoryConfig};
	}

	override void OnShow() {
		super.OnShow();
		linked.LoadLinkedVars();
	}

	override void RegisterAllLinkedVars() {
		TStringSet itemSet = LBInherit.Get().GetAllChildren({"Inventory_Base"}, false, true, true);
		linked.RegisterLinkedVar("GetConfig().enablePlotpoleExtension", chckbx_enable);
		linked.RegisterLinkedVar("GetConfig().syncPlotpolesToCFCloud", chckbx_sync_cf);
		linked.RegisterLinkedVar("GetConfig().doObjectLifetimeReset", chckbx_reset_lifetime);
		linked.RegisterLinkedVar("GetConfig().flagLifetimeRefreshTime", edit_refresh_time).SetChangeTrigger("UpdateRefreshTime()");
		linked.RegisterLinkedVar("GetConfig().flagUptimeDuration", edit_uptime).SetChangeTrigger("UpdateUptimeTime()");
		linked.RegisterLinkedVar("GetConfig().preventUnauthorizedDeploying", chckbx_prevent_unauth);
		linked.RegisterLinkedList("GetConfig().deployInOthersTerritoryExceptions", list_unauth_except, btn_add_unauth_except, btn_del_unauth_except).EnableItemSelector(false).EnableInListSearch(itemSet);
		linked.RegisterLinkedVar("GetConfig().forceDeployingInTerritory", chckbx_force_in_terr);
		linked.RegisterLinkedList("GetConfig().forceExceptions", list_force_except, btn_add_force_except, btn_del_force_except).EnableItemSelector(false).EnableInListSearch(itemSet);
		linked.RegisterLinkedVar("GetConfig().preventUnauthorizedBuilding", chckbx_prevent_build);
		linked.RegisterLinkedVar("GetConfig().preventUnauthorizedDismantling", chckbx_prevent_dismantle);
		linked.RegisterLinkedVar("GetConfig().preventUnauthorizedDestroying", chckbx_prevent_destroy);
		linked.RegisterLinkedVar("GetConfig().lowerFlagWhenGroupDeleted", chckbx_lower_group_del);
		linked.RegisterLinkedVar("GetConfig().instantDestroyPlotpole", chckbx_instant_destroy);
		linked.RegisterLinkedVar("GetConfig().returnFlagpoleKitOnInstantDestroy", chckbx_return_flag);
		linked.RegisterLinkedVar("GetConfig().allowOthersPlotpoleDestroy", chckbx_allow_flag_dest);
		linked.RegisterLinkedVar("GetConfig().allowDestroyWithFlagAttached", chckbx_allow_destroy_with);
		linked.RegisterLinkedVar("GetConfig().maxDistanceToDismantleFlag", edit_max_dismantle);
		linked.RegisterLinkedVar("GetConfig().instantBuildPlotpole", chckbx_instant_build);
		linked.RegisterLinkedVar("GetConfig().autoAttachFlag", chckbx_auto_attach);
		linked.RegisterLinkedVar("GetConfig().autoRaiseFlag", chckbx_auto_raise);
		linked.RegisterLinkedVar("GetConfig().displayPlotpolesOnMap", chckbx_display_map);
		linked.RegisterLinkedVar("GetConfig().allowOthersPlotpoleLowerFlag", chckbx_allow_flag_lower);
		linked.RegisterLinkedVar("GetConfig().maxDistanceToLowerFlag", edit_max_lower);
		linked.RegisterLinkedVar("GetConfig().allowDismantleInUnclaimedTeritorry", chckbx_unclaimed_dismantle);
		linked.RegisterLinkedVar("GetConfig().allowDestroyInUnclaimedTeritorry", chckbx_unclaimed_destroy);
		itemSet = LBInherit.Get().GetAllChildren({"Flag_Base"}, false, true, true);
		linked.RegisterLinkedList("GetConfig().autoFlagAttachedItemnames", list_flags, btn_add_flag, btn_del_flag).EnableItemSelector(false, "Flag_Base").EnableInListSearch(itemSet);
		linked.RegisterLinkedVar("GetConfig().plotpoleRadius", edit_radius_pvp);
		linked.RegisterLinkedVar("GetConfig().plotpoleHeightUp", edit_up_pvp);
		linked.RegisterLinkedVar("GetConfig().plotpoleHeightDown", edit_down_pvp);
		linked.RegisterLinkedVar("GetConfig().plotpoleRadius_InsidePvEZone", edit_radius_pve);
		linked.RegisterLinkedVar("GetConfig().plotpoleHeightUp_InsidePvEZone", edit_up_pve);
		linked.RegisterLinkedVar("GetConfig().plotpoleHeightDown_InsidePvEZone", edit_down_pve);
		linked.RegisterLinkedVar("GetConfig().plotpoleDistanceMinHostile", edit_dist_enemy);
		linked.RegisterLinkedVar("GetConfig().plotpoleDistanceMinFriendly", edit_dist_friendly);
		linked.RegisterLinkedVar("GetConfig().defaultPlotpoleCountPerGroup", edit_max_count);
#ifndef PVEZ
		panel_pvez.Show(false);
#endif

	}

	void UpdateRefreshTime() {
		txt_refresh_out.SetText(LBDate.Init(edit_refresh_time.GetText().ToInt()).ToDiffString());
	}

	void UpdateUptimeTime() {
		txt_uptime_out.SetText(LBDate.Init(edit_uptime.GetText().ToInt()).ToDiffString());
	}

	LBTerritoryConfig_ GetConfig() {
		return LBTerritoryConfig.Get;
	}

}
#endif
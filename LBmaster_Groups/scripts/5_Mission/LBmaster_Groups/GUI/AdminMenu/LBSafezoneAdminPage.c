[RegisterLBAdminPage(LBSafezoneAdminPage, "LBmaster_Groups/logo/logo.paa", "#lb_ag_admin_menu_safezone_marker", "safezone.markers.change")]
class LBSafezoneAdminPage : LBAdmin_Menu_Page {

	ButtonWidget btn_save;
	CheckBoxWidget chckbx_enable, chckbx_showEverywhere, chckbx_lineofsight, chckbx_obfuscate, chckbx_ownTag;
	EditBoxWidget edit_distance, edit_player_prefix, edit_admin_prefix, edit_a, edit_r, edit_g, edit_b, edit_a0, edit_r0, edit_g0, edit_b0;
	SliderWidget slider_a, slider_r, slider_g, slider_b, slider_a0, slider_r0, slider_g0, slider_b0;
	Widget player_color_out, admin_color_out;

	override array<typename> GetEditedConfigs() {
		return {LBSafezoneMarkers};
	}

	override void OnShow() {
		super.OnShow();
		linked.LoadLinkedVars();

		edit_a.SetText("" + ((int) slider_a.GetCurrent()));
		edit_r.SetText("" + ((int) slider_r.GetCurrent()));
		edit_g.SetText("" + ((int) slider_g.GetCurrent()));
		edit_b.SetText("" + ((int) slider_b.GetCurrent()));
		edit_a0.SetText("" + ((int) slider_a0.GetCurrent()));
		edit_r0.SetText("" + ((int) slider_r0.GetCurrent()));
		edit_g0.SetText("" + ((int) slider_g0.GetCurrent()));
		edit_b0.SetText("" + ((int) slider_b0.GetCurrent()));
	}

	override void RegisterAllLinkedVars() {
		linked.RegisterLinkedVar("GetConfig().enablePlayerMarkers", chckbx_enable);
		linked.RegisterLinkedVar("GetConfig().showMarkersEverywhere", chckbx_showEverywhere);
		linked.RegisterLinkedVar("GetConfig().checkLineOfSight", chckbx_lineofsight);
		linked.RegisterLinkedVar("GetConfig().obfuscatePlayerNames", chckbx_obfuscate);
		linked.RegisterLinkedVar("GetConfig().showOwnPlayerTag", chckbx_ownTag);
		linked.RegisterLinkedVar("GetConfig().maxPlayerDistance", edit_distance);
		linked.RegisterLinkedVar("GetConfig().playerTagPrefix", edit_player_prefix);
		linked.RegisterLinkedColor(slider_a, slider_r, slider_g, slider_b, "GetConfig().playerTagColor", player_color_out);
		linked.RegisterLinkedColor(slider_a0, slider_r0, slider_g0, slider_b0, "GetConfig().adminTagColor", admin_color_out);
		linked.RegisterLinkedVar("GetConfig().adminTagPrefix", edit_admin_prefix);

	}

	override bool OnChange(Widget w, int x, int y, bool finished) {
		super.OnChange(w, x, y, finished);

		if (w == slider_a)
			edit_a.SetText("" + ((int) slider_a.GetCurrent()));
		else if (w == slider_r)
			edit_r.SetText("" + ((int) slider_r.GetCurrent()));
		else if (w == slider_g)
			edit_g.SetText("" + ((int) slider_g.GetCurrent()));
		else if (w == slider_b)
			edit_b.SetText("" + ((int) slider_b.GetCurrent()));
		else if (w == slider_a0)
			edit_a0.SetText("" + ((int) slider_a0.GetCurrent()));
		else if (w == slider_r0)
			edit_r0.SetText("" + ((int) slider_r0.GetCurrent()));
		else if (w == slider_g0)
			edit_g0.SetText("" + ((int) slider_g0.GetCurrent()));
		else if (w == slider_b0)
			edit_b0.SetText("" + ((int) slider_b0.GetCurrent()));

		if (w == edit_a) {
			slider_a.SetCurrent(edit_a.GetText().ToInt());
			GetConfig().playerTagColor.a = edit_a.GetText().ToInt();
		} else if (w == edit_r) {
			slider_r.SetCurrent(edit_r.GetText().ToInt());
			GetConfig().playerTagColor.r = edit_r.GetText().ToInt();
		} else if (w == edit_g) {
			slider_g.SetCurrent(edit_g.GetText().ToInt());
			GetConfig().playerTagColor.g = edit_g.GetText().ToInt();
		} else if (w == edit_b) {
			slider_b.SetCurrent(edit_b.GetText().ToInt());
			GetConfig().playerTagColor.b = edit_b.GetText().ToInt();
		} else if (w == edit_a0) {
			slider_a0.SetCurrent(edit_a0.GetText().ToInt());
			GetConfig().adminTagColor.a = edit_a0.GetText().ToInt();
		} else if (w == edit_r0) {
			slider_r0.SetCurrent(edit_r0.GetText().ToInt());
			GetConfig().adminTagColor.r = edit_r0.GetText().ToInt();
		} else if (w == edit_g0) {
			slider_g0.SetCurrent(edit_g0.GetText().ToInt());
			GetConfig().adminTagColor.g = edit_g0.GetText().ToInt();
		} else if (w == edit_b0) {
			slider_b0.SetCurrent(edit_b0.GetText().ToInt());
			GetConfig().adminTagColor.b = edit_b0.GetText().ToInt();
		}
		return false;
	}

	LBSafezoneMarkers_ GetConfig() {
		return LBSafezoneMarkers.Get;
	}
}
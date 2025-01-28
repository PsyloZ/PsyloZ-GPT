[RegisterLBAdminPage(LBNoBuildZonesPage, "LBmaster_Groups/logo/logo.paa", "#lb_ag_admin_menu_no_build", "nobuild.change")]
class LBNoBuildZonesPage : LBAdmin_Menu_Page {

	SliderWidget slider_size;
	Widget zones_w, slider_color;
	EditBoxWidget txt_size, txt_name, edit_notification_title, edit_blocked_message;
	ButtonWidget btn_add, btn_save, btn_add_item, btn_remove_item;
	CheckBoxWidget chckbx_show_territorry_flags, chckbx_enable, chckbx_show;
	SliderWidget slider_color_r, slider_color_g, slider_color_b;
	TextListboxWidget list_ignored_items;

	bool placing = false;
	MapMarkerWrapperCircle circle;
	ref array<ButtonWidget> deleteButtons = new array<ButtonWidget>();
	ref array<Widget> button_border = new array<Widget>();
	ref array<MapMarkerWrapperCircle> circles = new array<MapMarkerWrapperCircle>();

	int currentMarkedZoneIndex = -1;

	private ref LBMapMarkerManager mapMarkerManager;
	private MapWidget mapWidget;

	override array<typename> GetEditedConfigs() {
		return {LB_NoBuildConfig};
	}

	override void OnShow() {
		super.OnShow();
		StopPlacing();
		circles.Clear();
		linked.LoadLinkedVars();
		AddMarkers();
	}

	override void OnHide() {
		super.OnHide();
		circles.Clear();
		StopPlacing();
	}

	LB_NoBuildConfig_ GetLB_NoBuildConfig() {
		return LB_NoBuildConfig.Get;
	}

	override void RegisterAllLinkedVars() {
		linked.RegisterLinkedVar("GetLB_NoBuildConfig().displayOnMap", chckbx_show);
		linked.RegisterLinkedVar("GetLB_NoBuildConfig().enabled", chckbx_enable);
		linked.RegisterLinkedVar("GetLB_NoBuildConfig().notificationTitle", edit_notification_title);
		linked.RegisterLinkedVar("GetLB_NoBuildConfig().notificationMessage", edit_blocked_message);
		linked.RegisterLinkedVar("GetLB_NoBuildConfig().circleColorR", slider_color_r).SetChangeTrigger("UpdateColor()");
		linked.RegisterLinkedVar("GetLB_NoBuildConfig().circleColorG", slider_color_g).SetChangeTrigger("UpdateColor()");
		linked.RegisterLinkedVar("GetLB_NoBuildConfig().circleColorB", slider_color_b).SetChangeTrigger("UpdateColor()");
		TStringSet itemSet = LBInherit.Get().GetAllChildren({"Inventory_Base"}, false, true, true);
		linked.RegisterLinkedList("GetLB_NoBuildConfig().ignoreItems", list_ignored_items, btn_add_item, btn_remove_item, null).EnableItemSelector(false).EnableInListSearch(itemSet, ARGB(255, 0, 255, 0), ARGB(255, 255, 40, 40));

		ApplyWidgetPermission("panel_edit", "nobuild.change");
	}

	void UpdateColor() {
		slider_color.SetColor(ARGB(255, slider_color_r.GetCurrent(), slider_color_g.GetCurrent(), slider_color_b.GetCurrent()));
	}

	override void InitWidgets() {
		super.InitWidgets();
		mapMarkerManager = new LBMapMarkerManager(mapWidget);
	}

	override bool OnClick(Widget w, int x, int y, int button) {
		if (super.OnClick(w, x, y, button))
			return true;
		if (w == btn_add) {
			TogglePlacing();
			return true;
		} else if (w == mapWidget && placing) {
			vector pos = mapMarkerManager.GetMousePosWld();
			int radius = GetSliderRadius();
			LBLogger.Info("Placing Circle: " + pos + " " + radius + " " + w, "AdvancedGroups");
			LB_NoBuildEntry zone = new LB_NoBuildEntry();
			zone.x = pos[0];
			zone.y = pos[2];
			zone.r = radius;
			zone.name = txt_name.GetText();
			LB_NoBuildConfig.Get.zones.Insert(zone);
			AddMarkers();
			StartPlacing();
		} else {
			int i = 0;
			foreach (ButtonWidget btn : deleteButtons) {
				if (w == btn) {
					LB_NoBuildConfig.Get.zones.RemoveOrdered(i);
					AddMarkers();
					return true;
				}
				i++;
			}
		}
		return false;
	}

	void AddZonesToList() {
		LBWidgetUtils.DeleteAllChildren(zones_w);
		deleteButtons.Clear();
		button_border.Clear();
		foreach (LB_NoBuildEntry zone : LB_NoBuildConfig.Get.zones) {
			Widget zoneWidget = LBLayoutManager.Get().CreateLayout("NoBuildZoneListEntry", zones_w);
			TextWidget name = TextWidget.Cast(zoneWidget.FindAnyWidget("name"));
			name.SetText(zone.name + "  X:" + zone.x + " Z:" + zone.y + " R:" + zone.r);
			deleteButtons.Insert(ButtonWidget.Cast(zoneWidget.FindAnyWidget("btn_0")));
			button_border.Insert(zoneWidget.FindAnyWidget("button_border"));
		}
	}

	void AddMarkers() {
		circles.Clear();
		mapMarkerManager.ClearMarkers();
		foreach (LB_NoBuildEntry zone : LB_NoBuildConfig.Get.zones) {
			MapMarkerWrapperCircle circle_ = mapMarkerManager.AddCircleNonScaling(Vector(zone.x, 0, zone.y), zone.r, ARGB(255, 255, 0, 0), 7456341, true);
			circles.Insert(circle_);
		}
		AddZonesToList();
		if (placing) {
			StartPlacing();
		}
		mapMarkerManager.AddMarkerObject(g_Game.GetPlayer(), "#lb_ag_me", LBColorManager.Get.GetColor("Own Player Map Marker"), LBMarkerVisibilityManager.Get.playerMarkerIcon);
		mapMarkerManager.UpdateFrame(true);
	}

	override void OnUpdateFrame() {
		super.OnUpdateFrame();
		if (mapMarkerManager)
			mapMarkerManager.UpdateFrame();
		if (circle) {
			vector pos = mapMarkerManager.GetMousePosWld();
			int radius = GetSliderRadius();
			LBLogger.Verbose("Placing Circle at: " + pos + " Radius: " + radius, "AdvancedGroups");
			circle.SetPosition(pos);
			circle.SetRadius(radius);
		}
		int lastIndex = currentMarkedZoneIndex;
		CalcNearestZoneToCursor();
		if (lastIndex != currentMarkedZoneIndex) {
			LBLogger.Verbose("Moved to new Zone: " + lastIndex + " -> " + currentMarkedZoneIndex, "AdvancedGroups");
			MapMarkerWrapperCircle circle_ = circles.Get(currentMarkedZoneIndex);
			Widget border = button_border.Get(currentMarkedZoneIndex);
			if (circle_)
				circle_.SetColor(ARGB(255, 0, 255, 0));
			if (border)
				border.SetColor(ARGB(255, 0, 255, 0));
			MapMarkerWrapperCircle circle2 = circles.Get(lastIndex);
			Widget border2 = button_border.Get(lastIndex);
			if (circle2)
				circle2.SetColor(ARGB(255, 255, 0, 0));
			if (border2)
				border2.SetColor(ARGB(255, 255, 255, 255));

		}
		if (GetUApi().GetInputByName("UALBMGroupDeleteMarker").LocalPress()) {
			LB_NoBuildConfig.Get.zones.RemoveOrdered(currentMarkedZoneIndex);
			AddMarkers();
		}
	}

	void CalcNearestZoneToCursor() {
		int nearestIndex = -1;
		float distance = -1;
		vector pos = mapMarkerManager.GetMousePosWld();
		int i = 0;
		foreach (LB_NoBuildEntry zone : LB_NoBuildConfig.Get.zones) {
			float dist = vector.Distance(pos, Vector(zone.x, 0, zone.y));
			if (distance < 0 || dist < distance) {
				nearestIndex = i;
				distance = dist;
			}
			i++;
		}
		currentMarkedZoneIndex = nearestIndex;
	}

	void StartPlacing() {
		StopPlacing();
		placing = true;
		circle = mapMarkerManager.AddCircleNonScaling(vector.Zero, GetSliderRadius(), ARGB(255, 255, 0, 0), 7456342, true);
	}

	void StopPlacing() {
		placing = false;
		mapMarkerManager.RemoveLayer(7456342);
		circle = null;
	}

	void TogglePlacing() {
		if (placing)
			StopPlacing();
		else
			StartPlacing();
	}

	int GetSliderRadius() {
		return Math.Min(Math.Max(10, slider_size.GetCurrent()), 2000);
	}

	override bool OnChange(Widget w, int x, int y, bool finished) {
		if (super.OnChange(w, x, y, finished))
			return true;
		if (w == slider_size) {
			int radius = GetSliderRadius();
			txt_size.SetText("" + radius + "m");
			return true;
		}
		return false;
	}

	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y) {
		if (super.OnMouseLeave(w, enterW, x, y))
			return true;
		if (w == txt_size) {
			int dist = txt_size.GetText().ToInt();
			txt_size.SetText("" + dist + "m");
			slider_size.SetCurrent(dist);
			SetFocus(slider_size);
			return true;
		}
		return false;
	}

	override bool OnMouseEnter(Widget w, int x, int y) {
		if (super.OnMouseEnter(w, x, y))
			return true;
		if (w == txt_size) {
			int dist = txt_size.GetText().ToInt();
			txt_size.SetText("" + dist);
		}
		return false;
	}
}
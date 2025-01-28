class LB_GPSHud : Managed {

	private Widget layoutRoot, iconPane, drawCanvas, panelMap;
	private MapWidget mapWidget;
	private TextWidget txt_angle, txt_speed, txt_coords;
	private ref LBMapMarkerManager mapMarkerManager;
	int lastGroupMarkerCount = 0, lastServerMarkerCount = 0, lastPrivateMarkerCount = 0, lastPlayerMarkerCount = 0, lastCustomMarkerCount = 0;
	bool lastNoBuildEnabled = false;
	int lastServerMarkerHash;
	ref MapMarkerWrapperObject markerWrapper;
	bool visible = false;
	float zoom = 0.25;
	float speed = 0;
	vector lastPos = vector.Zero;
	ref Timer speedTimer = new Timer();
	ref Timer coordTimer = new Timer();

	int lastGPSCheck = 0;
	bool lastGPSCheckResult = false;

	static bool foundWorldSize = false;

	void Init() {
		layoutRoot = LBLayoutManager.Get().CreateLayout("GPS");
		if (!layoutRoot)
			return;
		ConnectClassWidgetVariables(this, layoutRoot);
		mapMarkerManager = new LBMapMarkerManager(mapWidget);
		mapMarkerManager.isMap = false;
		g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(CheckNewMarkers, 100, true, false);
		LBColorManager_.Event_OnColorChange.Insert(OnColorChanged);
		LBPositionManager_.Event_OnPositionChange.Insert(OnPositionChange);
		LBLayoutConfig_.Event_GPSChanged.Insert(OnSizeChange);
		LBLogger.Debug("Display Speed: " + LBGroupMainConfig.Get.gpsDisplaySpeed + " Display Coords: " + LBGroupMainConfig.Get.gpsDisplayCoords + " Display Angle: " + LBGroupMainConfig.Get.gpsDisplayAngle, "AdvancedGroups");
		InitDisplays();
		UpdatePosition();
		OnSizeChange();
		LBWidgetUtils.Event_OnScreenSizeChanged.Insert(OnSizeChange);
	}

	void ~LB_GPSHud() {
		if (g_Game && g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM)) {
			g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(CheckNewMarkers);
		}
		if (LBColorManager_.Event_OnColorChange)
			LBColorManager_.Event_OnColorChange.Remove(OnColorChanged);
		if (LBPositionManager_.Event_OnPositionChange)
			LBPositionManager_.Event_OnPositionChange.Remove(OnPositionChange);
		if (LBLayoutConfig_.Event_GPSChanged)
			LBLayoutConfig_.Event_GPSChanged.Remove(OnSizeChange);
		if (layoutRoot)
			layoutRoot.Unlink();
		delete mapMarkerManager;
		speedTimer.Stop();
		coordTimer.Stop();
		LBWidgetUtils.Event_OnScreenSizeChanged.Remove(OnSizeChange);
	}

	void InitDisplays() {
		if (LBGroupMainConfig.Get.gpsDisplaySpeed) {
			speedTimer.Run(0.5, this, "UpdateSpeed", null, true);
			LBLogger.Debug("Started Timer 1", "AdvancedGroups");
			txt_speed.Show(true);
		} else {
			speedTimer.Stop();
			txt_speed.Show(false);
		}
		if (LBGroupMainConfig.Get.gpsDisplayCoords) {
			coordTimer.Run(0.4, this, "UpdateCoords", null, true);
			LBLogger.Debug("Started Timer 2", "AdvancedGroups");
			txt_coords.Show(true);
		} else {
			coordTimer.Stop();
			txt_coords.Show(false);
		}
		txt_angle.Show(LBGroupMainConfig.Get.gpsDisplayAngle);
	}

	bool CanEnableGPS() {
		int time = g_Game.GetTime();
		if (time - lastGPSCheck >= 1000) {
			lastGPSCheckResult = CanEnableGPSInternal();
			lastGPSCheck = time;
		}
		return lastGPSCheckResult;
	}

	private bool CanEnableGPSInternal() {
		PlayerBase player = PlayerBase.Cast(g_Game.GetPlayer());
		if (!player)
			return false;
		HumanCommandVehicle veh = player.GetCommand_Vehicle();
		Transport trans = null;
		if (veh)
			trans = veh.GetTransport();

		if (LBGroupMainConfig.Get.gpsOnlyInVehicles) {
			if (!trans)
				return false;
			bool hasGPS = false;
			if (!LBGroupMainConfig.Get.gpsRequireItem || HasGPSInInventory(player))
				hasGPS = true;
			string type = trans.GetType();
			TStringSet vehicles = LBInherit.Get().GetAllChildren(LBGroupMainConfig.Get.vehiclesWithGPS, false, true, true);
			return vehicles.Find(type) != -1 && hasGPS;
		}
		return !LBGroupMainConfig.Get.gpsRequireItem || HasGPSInInventory(player);
	}

	bool HasGPSInInventory(PlayerBase player) {
		return LBPlayerUtils.HasItemsInInventory(player, LBGroupMainConfig.Get.gpsItems);
	}

	void OnColorChanged() {
		CheckNewMarkers(true);
	}

	void UpdateSpeed() {
		Man player = g_Game.GetPlayer();
		if (player) {
			vector pos = player.GetPosition();
			if (lastPos != vector.Zero) {
				float dist = vector.Distance(pos, lastPos);
				speed = dist * 2 * 3.6;
				txt_speed.SetText(FloatToString(speed, true) + " km/h");
			}
			lastPos = pos;
		}
	}

	void UpdateCoords() {
		Man player = g_Game.GetPlayer();
		if (player) {
			vector pos = player.GetPosition();
			string format = FloatToString(pos[0], false) + "  " + FloatToString(pos[1], false) + "  " + FloatToString(pos[2], false);
			txt_coords.SetText(format);
		}

	}

	string FloatToString(float f, bool addPoint) {
		string txt = "" + f;
		int index = txt.IndexOf(".");
		if (addPoint) {
			if (index > 0)
				txt = txt.Substring(0, index + 2);
			else
				txt = txt + ".0";
		} else {
			if (index > 0)
				txt = txt.Substring(0, index);
		}
		return txt;
	}

	void OnSizeChange() {
		zoom = LBLayoutConfig.Get.gpsZoom;
		LBLogger.Info("On GPS Size changed: " + zoom, "AdvancedGroups");
		float width, height;
		if (GetSize(width, height)) {
			SetSize(width, height);
		}
		int index = LBLayoutConfig.Get.gpsSizeIndex;
		txt_coords.Show(LBGroupMainConfig.Get.gpsDisplayCoords && (index == 0 || index == 3));
		UpdatePosition();
	}

	void SetSize(float width, float height) {
		layoutRoot.SetSize(width, height);
	}

	bool GetSize(out float width, out float height) {
		int index = LBLayoutConfig.Get.gpsSizeIndex;
		if (index == 2) {
			width = 175 * LBWidgetUtils.widthScale;
			height = 175 * LBWidgetUtils.widthScale;
			return true;
		}
		if (index == 1) {
			width = 220 * LBWidgetUtils.widthScale;
			height = 220 * LBWidgetUtils.widthScale;
			return true;
		}
		if (index == 0) {
			width = 300 * LBWidgetUtils.widthScale;
			height = 300 * LBWidgetUtils.widthScale;
			return true;
		}
		if (index == 3) {
			width = 350 * LBWidgetUtils.widthScale;
			height = 350 * LBWidgetUtils.widthScale;
			return true;
		}
		return false;
	}

	void OnPositionChange() {
		UpdatePosition();
	}

	void UpdatePosition() {
		vector screenLocation = LBPositionManager.Get.GetPosition("Minimap");
		int index = LBPositionManager.Get.GetIndex("Minimap");
		LBLogger.Verbose("Updating Position of Minimap " + screenLocation + " " + index, "AdvancedGroups");
		LBWidgetUtils.SetWidgetAlignmentIndex(layoutRoot, index);
		LBWidgetUtils.SetWidgetPositionIndex(layoutRoot, screenLocation, index);
		LBLogger.Verbose("Updated Position to: " + screenLocation, "AdvancedGroups");
	}

	void CheckNewMarkers(bool force = false) {
		LBGroupUI openedMapUI = LBGroupUI.Cast(LBMenuManager.Get().GetPersistentMenu(LBGroupUI));
		if (force || NeedMarkerRefresh()) {
			openedMapUI.AddMapMarker(mapWidget, mapMarkerManager, false);
			if (g_Game.GetPlayer())
				markerWrapper = mapMarkerManager.AddMarkerObject(g_Game.GetPlayer(), "", LBColorManager.Get.GetColor("Own Player Map Marker"), "LBmaster_Groups\\gui\\icons\\marker-stroked.paa");
		}
	}

	void UpdateHud() {
		IngameHud hud = IngameHud.Cast(g_Game.GetMission().GetHud());
		if (hud) {
			bool visible_ = false;
			if (hud.IsHudVisible() && LBMarkerVisibilityManager.Get.gpsEnabled && LBPlayerUtils.IsClientPlayerAlive() && !g_Game.GetUIManager().GetMenu())
				visible_ = true;
			Show(visible_);
			if (visible_) {
				Update();
			}
		} else {
			Show(false);
		}
	}

	bool IsVisible() {
		return visible;
	}

	void Show(bool show) {
		visible = show;
		layoutRoot.Show(show && CanEnableGPS());
	}

	void UpdateGPSItemVisibility() {
		Show(visible);
	}

	void OnGroupChanged() {
		CheckNewMarkers(true);
	}

	bool NeedMarkerRefresh() {
		PlayerBase pb = PlayerBase.Cast(g_Game.GetPlayer());
		bool need = false;
		bool noBuild = false;
		if (LBMarkerVisibilityManager.Get != null && LBMarkerVisibilityManager.Get.showNoBuildZones && LB_NoBuildConfig.Get != null && LB_NoBuildConfig.Get.enabled)
			noBuild = true;
		if (noBuild != lastNoBuildEnabled) {
			lastNoBuildEnabled = noBuild;
			need = true;
		}
		int groupMarkers = 0;
		if (pb && pb.GetLBGroup()) {
			LBGroup grp = pb.GetLBGroup();
			groupMarkers += grp.markers.Count();
			groupMarkers += grp.pings.Count();
			groupMarkers += grp.members.Count();
		}
		if (groupMarkers != lastGroupMarkerCount) {
			lastGroupMarkerCount = groupMarkers;
			need = true;
		}
		LBStaticMarkerManagerClient mgr = LBStaticMarkerManagerClient.Get();
		int staticHash = 0;
		foreach (LBServerMarker markServ : mgr.staticMarkers) {
			staticHash += markServ.CalcHash();
		}
		if (staticHash != lastServerMarkerHash) {
			lastServerMarkerHash = staticHash;
			need = true;
		}
		int clientMarkers = LBPrivateMarkerManager.Get.privateMarkers.Count();
		if (clientMarkers != lastPrivateMarkerCount) {
			lastPrivateMarkerCount = clientMarkers;
			need = true;
		}
		LBGroupMainConfig_ cfg = LBGroupMainConfig.Get;
		if (cfg && cfg.canSeeOwnPlayerOnMap && lastPlayerMarkerCount != 1) {
			lastPlayerMarkerCount = 1;
			need = true;
		} else if (cfg && !cfg.canSeeOwnPlayerOnMap && lastPlayerMarkerCount != 0) {
			lastPlayerMarkerCount = 0;
			need = true;
		}
		return need;
	}

	void Update() {
		if (!visible)
			return;
		mapMarkerManager.UpdateFrame();
		vector pos = g_Game.GetCurrentCameraPosition();
		float angle = GetCurrentAngle();
		string angletxt = "" + angle;
		int index = angletxt.IndexOf(".");
		if (index > 0)
			angletxt = angletxt.Substring(0, index);
		txt_angle.SetText(angletxt);
		mapWidget.SetScale(zoom);

		float finalX = pos[0] + zoom * 10;
		float finalY = pos[2] + zoom * 10;
		vector finalPos = Vector(finalX, 0, finalY);
		mapWidget.SetMapPos(finalPos);
		if (markerWrapper && markerWrapper.icon)
			markerWrapper.icon.SetRotation(0, 0, angle - 180);
	}

	float GetCurrentAngle() {
		vector dir = g_Game.GetCurrentCameraDirection();
		vector angles = dir.VectorToAngles();
		if (angles[0] < 0)
			return angles[0] + 360;
		if (angles[0] > 360)
			return angles[0] - 360;
		return angles[0];
	}

}
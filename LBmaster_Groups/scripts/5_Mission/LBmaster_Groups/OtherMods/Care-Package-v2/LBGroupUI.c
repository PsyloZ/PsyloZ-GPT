#ifdef CarePackageV2
modded class LBGroupUI {

	override void AddCustomMarkersOnMapOpen() {

		GetRPCManager().SendRPC("CarePackage_Server", "CarePackageLocation_Server", NULL);

		super.AddCustomMarkersOnMapOpen();

		if (mapWidget) {
			if (g_Game.GetClientCarePackageMarkerArrayLength() > 0)
				for (int i = 0; i < g_Game.GetClientCarePackageMarkerArrayLength(); i++) {
					if (g_Game.GetClientCarePackageMarker(i) != "0 0 0") {
						mapWidget.AddUserMark(g_Game.GetClientCarePackageMarker(i), "CarePackage", ARGB(255, 0, 255, 0), "CarePackage\\Icon.paa");
					}
				}
		}
	}
}
#endif
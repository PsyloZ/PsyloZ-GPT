#ifdef DZ_Expansion_Quests
modded class ExpansionQuestModule {

	override bool HasQuestMarker(int questID, int objectiveIndex) {
		return LBStaticMarkerManagerClient.Get().FindMarkerByUID(GetQuestMarkerIdLB(questID, objectiveIndex)) != null;
	}

	override protected void CreateMarkerClient(vector pos, string text, int questID, bool is3D, int objectiveIndex, int visibility) {
		LBServerMarker marker = new LBServerMarker();
		ExpansionIcon icon = ExpansionIcons.Get("Questionmark");
		string markerIcon = "Questionmark";
		if (icon)
			markerIcon = icon.IconPath;
		marker.SetupMarker(LBMarkerType.SERVER_DYNAMIC, text, markerIcon, pos);
		marker.uid = GetQuestMarkerIdLB(questID, objectiveIndex);
		marker.display3d = is3D;
		marker.SetColorInt(ARGB(255, 241, 196, 15));
		//if ((visibility & EXPANSION_MARKER_VIS_MAP) == 0)
		//	marker.displayMap = false;
		LBStaticMarkerManagerClient.Get().AddNewMarker(marker);
	}

	override protected void RemoveMarkersClient(int questID, int objectiveIndex) {
		LBStaticMarkerManagerClient.Get().DeleteMarker(GetQuestMarkerIdLB(questID, objectiveIndex));
	}

	int GetQuestMarkerIdLB(int questId, int objectiveIndex = 0) {
		return 100000 + questId * 4547 + objectiveIndex * 5747337;
	}
}
#endif
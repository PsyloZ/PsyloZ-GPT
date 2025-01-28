class LBGroupManager {

	static ref TStringArray illegalFilenames = {"CON", "PRN", "AUX", "NUL", "LST"};
	static ref TStringArray illegalFilenamesNum = {"COM", "LPT"};

	static ref LBGroupManager g_LBGroupManager;

	static LBGroupManager Get() {
		if (!g_LBGroupManager) {
			LBConfigManager.Get().LoadImmediate("LBATMConfig_");
			LBConfigManager.Get().LoadImmediate("LBGroupPermissions_");
			LBConfigManager.Get().LoadImmediate("LBTerritoryConfig_");
			LBConfigManager.Get().LoadImmediate("LBClanTagColorConfig_");
			g_LBGroupManager = Load();

		}
		return g_LBGroupManager;
	}

	static void Delete() {
		if (g_LBGroupManager)
			delete g_LBGroupManager;
	}

	static LBGroupManager Load() {
		LBGroupManager groupMgr = new LBGroupManager;
		groupMgr.LoadAllGroups();
		LBLogger.Debug("Loaded LBGroupManager", "AdvancedGroups");
		return groupMgr;
	}

	LBGroup GetGroupByHash(int hash);
	LBGroup CreateNewGroup(string name, string shortname, PlayerBase leader);

	void LoadAllGroups() {}

	int GetInitialLevel(string shortname) {
		return 0;
	}

	bool GroupTagTaken(string tag, LBGroup exception = null) {
		return false;
	}

	array<ref LBGroup> GetAllGroups() {
		return new array<ref LBGroup>();
	}

	TStringArray GetAllGroupNames() {
		TStringArray names = new TStringArray();
		array<ref LBGroup> groups = GetAllGroups();
		foreach (LBGroup grp : groups) {
			if (grp)
				names.Insert(grp.shortname);
		}
		return names;
	}
	void SaveGroup(LBGroup grp) {}
	void DeleteGroup(LBGroup group) {}
	LBGroup GetPlayersGroup(string steamid) {
		return null;
	}
	LBGroup GetGroupByShortName(string shortname) {
		return null;
	}
	LBGroup GetGroupByName(string name) {
		return null;
	}
	LBGroup GetPlayersOriginalGroup(string steamid) {
		return null;
	}
}
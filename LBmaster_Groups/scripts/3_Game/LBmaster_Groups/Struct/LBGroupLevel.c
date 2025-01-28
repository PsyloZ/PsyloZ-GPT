class LBGroupLevel {

	int level; // current level number (starts with 0. Do not use the same for different levels and do not skip numbers)
	int maxPlayerCount; // Maximum Total Player Count
	int upgradeCost; // Cost to upgrade the group to this level (`upgradeCost` for level 0 will be the creation cost of the group)
	int subgroupCount; // If Subgroups are enabled (see MainConfig): The amount of subgroups this level has
	int subgroupSize; // Size fo each subgroup. `subgroupCount * subgroupSize` must be bigger than the `maxPlayerCount` to allow players to switch groups. ! Offline players will also occupy a subgroup slot so make sure the Group has enough room for switching around !
	int groupMarkerLimitAdded; // Group Marker Limit added to the `groupMarkerLimit` in the MainConfig.json
	int groupPingsLimitAdded = 0; // Added amount of Pings per player since players can set multiple pings
	int groupPlotpolesLimitAdded = 0; // If Plotpole DLC is used: Max Count of Plotpoles adding to the base Limit `defaultPlotpoleCountPerGroup` in PlotpoleConfig.json

	static LBGroupLevel InitLevel(int lvl, int maxPlayers, int cost, int subCount, int subSize, int markerAdded, int plotpoleAdded) {
		LBGroupLevel lev = new LBGroupLevel();
		lev.level = lvl;
		lev.maxPlayerCount = maxPlayers;
		lev.upgradeCost = cost;
		lev.subgroupCount = subCount;
		lev.subgroupSize = subSize;
		lev.groupMarkerLimitAdded = markerAdded;
		lev.groupPlotpolesLimitAdded = plotpoleAdded;
		return lev;
	}

	bool HasNextLevel() {
		return GetNextLevel() != null;
	}

	LBGroupLevel GetNextLevel() {
		return LBGroupLevels.Get.GetNextLevel(this);
	}

	string ToListString(int column) {
		return "Level " + level;
	}

}
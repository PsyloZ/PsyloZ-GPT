class LBGroupLevels : LBConfigLoader<LBGroupLevels_> {

	[SetPriority(LBConfigPriority.HIGHEST)]
	override void InitVars() {
		InitVarsInternal("LBGroup", "Levels.json", LBConfigType.CONFIG, true, "group.levels.change"); // (easy)
	}

}
// This file contains all possible group levels. The levels must start at 0 and must not have any gaps ! So after level 0 is level 1, then 2, then 3. If you remove level 2, then groups cannot be upgraded to level 3 anymore, because level 2 does not exist ! You could abuse this system to add an unreachable level and set that level for your Admins group to have higher limits, that normal groups.
class LBGroupLevels_ : LBConfigBase {

	static const int CURRENT_VERSION = 0;

	ref array<ref LBGroupLevel> allLevels = new array<ref LBGroupLevel>();

	override bool JsonLoadVar(string path, bool forceValid, out bool overwriteTest) {
		return LBJsonLoader<array<ref LBGroupLevel>>.JsonLoadFile(path, allLevels, forceValid);
	}
	override void JsonSaveVar(string path, out bool overwriteTest) {
		LBJsonLoader<array<ref LBGroupLevel>>.JsonSaveFile(path, allLevels);
	}

	LBGroupLevel FindLevelByUID(int level) {
		if (level == -1)
			return null;
		foreach (LBGroupLevel level2 : allLevels) {
			if (level2.level == level)
				return level2;
		}
		return null;
	}

	LBGroupLevel GetHighestLevel() {
		LBGroupLevel highest = null;
		foreach (LBGroupLevel level2 : allLevels) {
			if (!highest || level2.level > highest.level)
				highest = level2;
		}
		return highest;
	}

	LBGroupLevel GetNextLevel(LBGroupLevel level) {
		if (!level)
			return null;
		return FindLevelByUID(level.level + 1);
	}

	LBGroupLevel GetNextLevel(int level) {
		return GetNextLevel(FindLevelByUID(level));
	}

	void RemoveCurrentLevel(int index) {
		int level = allLevels.Get(index).level;
		allLevels.RemoveOrdered(index);
		LBGroupLevel after = FindLevelByUID(level + 1);
		while (after != null) {
			--after.level;
			++level;
			after = FindLevelByUID(level + 1);
		}
		if (FindLevelByUID(0) == null)
			CreateNewLevel("");
		OrderLevels();
	}

	void CreateNewLevel(string input) {
		int level = 0;
		while (FindLevelByUID(level) != null)
			++level;
		allLevels.Insert(LBGroupLevel.InitLevel(level, 10, 0, 2, 5, 0, 0));
		OrderLevels();
	}

	int GetLevelCount() {
		return allLevels.Count();
	}

	string GetLevel(int index) {
		return "Level " + allLevels.Get(index).level;
	}

	void OrderLevels() {
		bool sorted = false;
		while (!sorted) {
			sorted = true;
			for (int i = 1; i < allLevels.Count(); ++i) {
				LBGroupLevel prev = allLevels.Get(i - 1);
				LBGroupLevel current = allLevels.Get(i);
				if (current.level < prev.level) {
					allLevels.Set(i, prev);
					allLevels.Set(i - 1, current);
					sorted = false;
				}
			}
		}
	}

}

class LB_LC_PositionPool {

	string name = "NEW"; // Name of the pool. The same name must be used in the Chest Config. Multiple chest configs can share the same position pool and no chests will spawn at the same position. When one chest config has max spawns set to -1 or takes up all points, configs below it in the list will not spawn any chests anymore, because all spots are filled
	string comment; // Comment to know what pool has which purpose
	ref array<ref LB_LC_ChestSpawnPos> positions = new array<ref LB_LC_ChestSpawnPos>(); // List of all available positions. Random positions are picked when `maxSpawns` is not -1 and smaller than the count of the entries in this list
	[NonSerialized()]
	ref array<LB_LC_ChestSpawnPos> remainingPoses = new array<LB_LC_ChestSpawnPos>();

	string ToListString(int column) {
		return name;
	}
	
}
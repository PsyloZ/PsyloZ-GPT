class LB_LC_PoolConfig : LBConfigLoader<LB_LC_PoolConfig_> {

	[SetPriority(LBConfigPriority.HIGH)]
	override void InitVars() {
		InitVarsInternal("LootChests", "positionPools.json", LBConfigType.CONFIG, true, "lootchest.change.positionpools", "lootchest.change.positionpools"); // (Medium)
	}
	
}
// This config contains all the positions of the chests where they can spawn at
class LB_LC_PoolConfig_ : LBConfigBase {

	static const int CURRENT_VERSION = 1;
	ref array<ref LB_LC_PositionPool> positionPools = new array<ref LB_LC_PositionPool>(); // List of all Loot pools for the chests to spawn at
	
}
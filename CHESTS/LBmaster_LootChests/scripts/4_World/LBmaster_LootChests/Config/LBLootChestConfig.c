class LBLootChestConfig : LBConfigLoader<LBLootChestConfig_> {

	override void InitVars() {
		InitVarsInternal("LootChests", "config.json", LBConfigType.CONFIG, true, "lootchest.change.chests", "lootchest.change.chests"); // (Medium)
	}

}
// This is the main config of the mod holding all the information about which loot chests to spawn
class LBLootChestConfig_ : LBConfigBase {

	static const int CURRENT_VERSION = 1;

	bool enabled = true; // Enable / disable the whole system. Disabling it will no longer spawn any chests
	float minPlayerDistanceForRespawn = 30.0; // Minimum distance in Meters a player must be away from a chest for it to attempt to respawn loot
	ref array<ref LB_LC_Chest> chestConfigs = new array<ref LB_LC_Chest>(); // List of all chests with their spawn points configured

}
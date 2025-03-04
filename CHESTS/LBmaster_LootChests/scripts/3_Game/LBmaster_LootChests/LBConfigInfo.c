modded class LBConfigInfo {
	void LBConfigInfo() {
		RegisterClassComment("LBLootChestConfig", "This is the main config of the mod holding all the information about which loot chests to spawn");
		RegisterClassVariableComment("LBLootChestConfig", "enabled", "Enable / disable the whole system. Disabling it will no longer spawn any chests");
		RegisterClassVariableComment("LBLootChestConfig", "minPlayerDistanceForRespawn", "Minimum distance in Meters a player must be away from a chest for it to attempt to respawn loot");
		RegisterClassVariableComment("LBLootChestConfig", "chestConfigs", "List of all chests with their spawn points configured");
		RegisterClassVariableComment("LB_LC_Chest", "name", "Name of the Chest config. Used for logging");
		RegisterClassVariableComment("LB_LC_Chest", "chestDisplayName", "Displayname of the Chest, that is spawned (should be a short name). This will overwrite the displayname from the config.cpp");
		RegisterClassVariableComment("LB_LC_Chest", "chestDescription", "Longer description also displayed in the inspect menu or when hovering over the chest to give the user more information like which key to use. This overwrites the description from the config.cpp");
		RegisterClassVariableComment("LB_LC_Chest", "comment", "Comment field to describe what this chest is doing and what it is for. Purely for internal use");
		RegisterClassVariableComment("LB_LC_Chest", "enabled", "Enable / disable this specific spawn crates config (e.g. prepare an event and only spawn it when needed)");
		RegisterClassVariableComment("LB_LC_Chest", "maxSpawns", "Maximum count of positions picked to spawn chests at. Use -1 to spawn chests at all positions");
		RegisterClassVariableComment("LB_LC_Chest", "positions", "List of all available positions. Random positions are picked when `maxSpawns` is not -1 and smaller than the count of the entries in this list");
		RegisterClassVariableComment("LB_LC_ChestSpawnPos", "pos", "x,y,z position of the chest (it's recommended to use the ingame admin menu to place the chests)");
		RegisterClassVariableComment("LB_LC_ChestSpawnPos", "dir", "yaw, pitch, roll (orientation) of the chest at this position");
		RegisterClassVariableComment("LB_LC_Chest", "chests", "List of itemnames for chests to spawn (must inherit the LB_LC_Base class). One random one is picked from the list. You need to have at least one entry!");
		RegisterClassVariableComment("LB_LC_Chest", "keys", "List of keys, that can be used to open the chest. Empty list means no key is needed");
		RegisterClassVariableComment("LB_LC_ChestKey", "itemname", "Itemname of the key (can be any item, which inherits the ItemBase class (basically any item, that can be picked up))");
		RegisterClassVariableComment("LB_LC_ChestKey", "time", "Time in seconds it takes to open the chest with this item");
		RegisterClassVariableComment("LB_LC_ChestKey", "damage", "Damage the item should take after opening the chest");
		RegisterClassVariableComment("LB_LC_ChestKey", "successRate", "Chance in % to actually open the chest (failing will also damage the item). 0.0 = 0%, 1.0 = 100%");
		RegisterClassVariableComment("LB_LC_Chest", "openable", "toggles whether the chest must be opened to loot it. (When using keys, this must be enabled!). It's recommended to set this to 1 for logging and performance (items will only spawn after being opened, otherwise items must be spawned when the chest is spawned, potentially spawning items, which are not looted and giving cheaters the vision what is in the chest before opening it)");
		RegisterClassVariableComment("LB_LC_Chest", "playedSoundSets", "List of sounds, which are all played when the chest was opened. This can be a door open sound or also a loud alarm (or both, since all sounds will be played)");
		RegisterClassVariableComment("LB_LC_Chest", "lootPreset", "Preset defined in the ItemPresets.json file in the common folder");
		RegisterClassVariableComment("LB_LC_Chest", "lootHealthMin", "Min HP in percent (0.0 - 1.0) to spawn the items with");
		RegisterClassVariableComment("LB_LC_Chest", "lootHealthMax", "Max HP in percent to spawn the items in the chest with. Set both to -1 to always spawn items pristine");
		RegisterClassVariableComment("LB_LC_Chest", "lootRespawnTimeMin", "Minimum time until the loot respawns in the chest (set to -1 to disable)");
		RegisterClassVariableComment("LB_LC_Chest", "lootRespawnTimeMax", "Maximum time until the loot respawns. A random number is picked between min and max if both are not -1, otherwise respawning is disabled");
		RegisterClassVariableComment("LB_LC_Chest", "respawnLootOnRestart", "Wether loot should respawn when the server restarts. The mod keeps track of chests and when they were last looted. It's recommended to not respawn loot on restart to prevent players from camping chest spots on restart (loot also doesn't respawn on restart, but while the server is running)");
	}
}
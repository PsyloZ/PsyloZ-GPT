class LB_LC_Chest {

	string name = "NEW"; // Name of the Chest config. Used for logging
	string chestDisplayName; // Displayname of the Chest, that is spawned (should be a short name). This will overwrite the displayname from the config.cpp
	string chestDescription; // Longer description also displayed in the inspect menu or when hovering over the chest to give the user more information like which key to use. This overwrites the description from the config.cpp
	string comment; // Comment field to describe what this chest is doing and what it is for. Purely for internal use
	bool enabled = true; // Enable / disable this specific spawn crates config (e.g. prepare an event and only spawn it when needed)
	int maxSpawns = -1; // Maximum count of positions picked to spawn chests at. Use -1 to spawn chests at all positions
	string positionPool; // Used position pool from the `positionPools` list
	ref TStringArray chests = new TStringArray(); // List of itemnames for chests to spawn (must inherit the LB_LC_Base class). One random one is picked from the list. You need to have at least one entry!
	ref array<ref LB_LC_ChestKey> keys = new array<ref LB_LC_ChestKey>(); // List of keys, that can be used to open the chest. Empty list means no key is needed
	bool openable = true; // toggles whether the chest must be opened to loot it. (When using keys, this must be enabled!). It's recommended to set this to 1 for logging and performance (items will only spawn after being opened, otherwise items must be spawned when the chest is spawned, potentially spawning items, which are not looted and giving cheaters the vision what is in the chest before opening it)
	ref TStringArray playedSoundSets = new TStringArray(); // List of sounds, which are all played when the chest was opened. This can be a door open sound or also a loud alarm (or both, since all sounds will be played)
	string lootPreset; // Preset defined in the ItemPresets.json file in the common folder
	float lootHealthMin = 1.0; // Min HP in percent (0.0 - 1.0) to spawn the items with
	float lootHealthMax = 1.0; // Max HP in percent to spawn the items in the chest with. Set both to -1 to always spawn items pristine
	int lootRespawnTimeMin = 3200; // Minimum time until the loot respawns in the chest (set to -1 to disable)
	int lootRespawnTimeMax = 4000; // Maximum time until the loot respawns. A random number is picked between min and max if both are not -1, otherwise respawning is disabled
	bool respawnLootOnRestart = true; // Wether loot should respawn when the server restarts. The mod keeps track of chests and when they were last looted. It's recommended to not respawn loot on restart to prevent players from camping chest spots on restart (loot also doesn't respawn on restart, but while the server is running)
	[NonSerialized()]
	ref LB_LC_PositionPool foundPositionPool;
	
	string ToListString(int column) {
		return name;
	}
	
}
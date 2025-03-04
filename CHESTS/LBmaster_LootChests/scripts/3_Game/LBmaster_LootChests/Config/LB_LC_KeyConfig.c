class LB_LC_KeyConfig : LBConfigLoader<LB_LC_KeyConfig_> {

	override void InitVars() {
		InitVarsInternal("LootChests", "keynames.json", LBConfigType.CONFIG, true, "lootchest.change.keynames"); // (Easy)
	}
	
}
// This config manages the displaynames and descriptions of all keys inheriting the `LB_LC_KeyBase` class. New keys are automatically added to the list when found
// This will make it a l
class LB_LC_KeyConfig_ : LBConfigBase {

	static const int CURRENT_VERSION;
	
	ref array<ref LB_LC_KeyEntry> keys = new array<ref LB_LC_KeyEntry>(); // List of all Keys. This will automatically be expanded with new entries. Old entries are not deleted
	
	[NonSerialized()]
	ref map<string, LB_LC_KeyEntry> cache = new map<string, LB_LC_KeyEntry>();
	
	override void OnReceivedFromRPC(PlayerIdentity sender) {
		FillCache();
	}
	
	void FillCache() {
		cache.Clear();
		foreach (LB_LC_KeyEntry keyEntry : keys) {
			cache.Insert(keyEntry.classname, keyEntry);
		}
	}
	
	LB_LC_KeyEntry GetKeyConfig(string classname) {
		return cache.Get(classname);
	}
	
}
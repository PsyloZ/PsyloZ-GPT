class LB_LC_KeyEntry {

	string classname; // Classname of the key in the config.cpp
	string displayname; // Display Name shown ingame (should be short!)
	string description; // Long description to optionally give players hints where they can use the key
	
	string ToListString(int column) {
		return classname;
	}
	
}
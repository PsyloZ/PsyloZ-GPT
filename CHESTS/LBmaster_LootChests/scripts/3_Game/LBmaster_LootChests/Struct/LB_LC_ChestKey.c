class LB_LC_ChestKey {

	string itemname; // Itemname of the key (can be any item, which inherits the ItemBase class (basically any item, that can be picked up))
	float time; // Time in seconds it takes to open the chest with this item
	float damage; // Damage the item should take after opening the chest
	float successRate = 1.0; // Chance in % to actually open the chest (failing will also damage the item). 0.0 = 0%, 1.0 = 100%

	string ToListString(int column) {
		return itemname;
	}
	
	void Setup(string val) {
		itemname = val;
		time = 10;
		damage = 0.5;
	}
	
}
// idk poorly named, just structs
class BaseBuildingItemEntry: Managed
{	
	string Item;
	int Quantity;
	
	void BaseBuildingItemEntry(string item, int quantity)
	{
		Item = item;
		Quantity = quantity;
	}
}
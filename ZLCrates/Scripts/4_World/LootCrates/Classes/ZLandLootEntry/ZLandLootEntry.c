class ZLandLootEntry: Managed
{
	ref array<string> Types = {};
	float Chance;
	
	void ZLandLootEntry(array<string> types, float chance = 1.0)
	{
		Types.Copy(types);
		Chance = chance;
	}
			
	EntityAI CreateEntry(GameInventory inventory, InventoryLocationType location)
	{		
		switch (location) {
			case InventoryLocationType.CARGO: {
				return inventory.CreateInInventory(Types.GetRandomElement());
			}
			
			case InventoryLocationType.ATTACHMENT: {
				return inventory.CreateAttachment(Types.GetRandomElement());
			}
		}
		
		return null;
	}
	
	EntityAI CreateEntry(vector position, vector orientation)
	{
		EntityAI item = EntityAI.Cast(GetGame().CreateObjectEx(Types.GetRandomElement(), position, ECE_SETUP));
		if (!item) {
			return null;
		}
		
		item.SetOrientation(orientation);
		item.Update();
		return item;
	}
}
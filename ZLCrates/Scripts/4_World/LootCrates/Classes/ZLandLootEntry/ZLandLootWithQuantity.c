class ZLandLootWithQuantity: ZLandLootEntry
{
	float QuantityMin, QuantityMax;
	
	void ZLandLootWithQuantity(array<string> types, float chance = 1.0, float quantity_min = 1.0, float quantity_max = 1.0)
	{
		QuantityMin = quantity_min;
		QuantityMax = quantity_max;
	}
		
	override EntityAI CreateEntry(GameInventory inventory, InventoryLocationType location)
	{
		EntityAI entity = super.CreateEntry(inventory, location);		
				
		Magazine_Base magazine = Magazine_Base.Cast(entity);
		if (magazine) {
			magazine.ServerSetAmmoCount(Math.Lerp(0, magazine.GetAmmoMax(), Math.RandomFloatInclusive(QuantityMin, QuantityMax))); 
			return magazine;
		}
		
		ItemBase item = ItemBase.Cast(entity);
		if (item) {
			item.SetQuantityNormalized(Math.RandomFloatInclusive(QuantityMin, QuantityMax));
			return item;
		}
		
		return entity;
	}
	
	override EntityAI CreateEntry(vector position, vector orientation)
	{
		EntityAI entity = super.CreateEntry(position, orientation);		
				
		Magazine_Base magazine = Magazine_Base.Cast(entity);
		if (magazine) {
			magazine.ServerSetAmmoCount(Math.Lerp(0, magazine.GetAmmoMax(), Math.RandomFloatInclusive(QuantityMin, QuantityMax))); 
			return magazine;
		}
		
		ItemBase item = ItemBase.Cast(entity);
		if (item) {
			item.SetQuantityNormalized(Math.RandomFloatInclusive(QuantityMin, QuantityMax));
			return item;
		}
		
		return entity;
	}
}
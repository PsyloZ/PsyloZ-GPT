class ZLandLootWithAttachments: ZLandLootEntry
{
	ref array<ref ZLandLootEntry> Attachments = {};
	
	void ZLandLootWithAttachments(array<string> types, float chance = 1.0, array<ref ZLandLootEntry> attachments = null)
	{
		if (attachments) {
			Attachments = attachments;
		}
	}
		
	override EntityAI CreateEntry(GameInventory inventory, InventoryLocationType location)
	{
		EntityAI item = super.CreateEntry(inventory, location);
		
		Weapon_Base weapon = Weapon_Base.Cast(item);
		foreach (ZLandLootEntry attachment_entry: Attachments) {
			// Random chance at spawning the attachment
			// we got rid of the others but i think this is okay... for now
			if (Math.RandomFloat01() > attachment_entry.Chance) {
				continue;
			}
			
			string attachment_name = attachment_entry.Types.GetRandomElement();
			if (weapon && GetGame().IsKindOf(attachment_name, "Magazine_Base")) { 
				weapon.SpawnAmmo(attachment_name);
				continue;
			}
			
			if (item) {
				attachment_entry.CreateEntry(item.GetInventory(), InventoryLocationType.ATTACHMENT);
			}
		}
		
		return item;
	}
	
	override EntityAI CreateEntry(vector position, vector orientation)
	{
		EntityAI item = super.CreateEntry(position, orientation);
		
		Weapon_Base weapon = Weapon_Base.Cast(item);
		foreach (ZLandLootEntry attachment_entry: Attachments) {
			// Random chance at spawning the attachment
			// we got rid of the others but i think this is okay... for now
			if (Math.RandomFloat01() > attachment_entry.Chance) {
				continue;
			}
			
			string attachment_name = attachment_entry.Types.GetRandomElement();
			if (weapon && GetGame().IsKindOf(attachment_name, "Magazine_Base")) { 
				weapon.SpawnAmmo(attachment_name);
				continue;
			}
			
			if (item) {
				attachment_entry.CreateEntry(item.GetInventory(), InventoryLocationType.ATTACHMENT);
			}
		}
		
		return item;
	}
}
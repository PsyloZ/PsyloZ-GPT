class ActionPlaceHologramFromHands: ActionPlaceHologram
{
	override BaseBuildingHologram GetHologram(ItemBase item)
	{
		BaseBuilding base_building = BaseBuilding.Cast(item);
		if (!base_building) {
			return null;
		}
		
		return base_building.GetCurrentPlacingHologram();
	}
	
	override BaseBuilding CreateObject(PlaceHologramActionData place_hologram_data)
	{
		vector transform[4];
		Math3D.YawPitchRollMatrix(place_hologram_data.Orientation, transform);
		transform[3] = place_hologram_data.Position;
				
		InventoryLocation src = new InventoryLocation;
		InventoryLocation dst = new InventoryLocation;
		dst.SetGround(place_hologram_data.m_MainItem, transform);
		
		place_hologram_data.m_MainItem.GetInventory().GetCurrentInventoryLocation(src);
		place_hologram_data.m_Player.GetHumanInventory().HandEvent(InventoryMode.SERVER, new HandEventMoveTo(place_hologram_data.m_Player, src, dst));
		return BaseBuilding.Cast(place_hologram_data.m_MainItem);
	}
}
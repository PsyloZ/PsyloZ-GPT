class ActionPlaceCurrentBlueprint: ActionPlaceHologram
{
	override BaseBuildingHologram GetHologram(ItemBase item)
	{
		RA_Blueprint blueprint = RA_Blueprint.Cast(item);
		if (!blueprint) {
			return null;
		}
		
		return blueprint.GetPlacing();
	}
	
	override BaseBuilding CreateObject(PlaceHologramActionData place_hologram_data)
	{
		string upgrade_type = BaseBuilding.GetUpgradeType(place_hologram_data.Type);
#ifdef DIAG_DEVELOPER
		if (BaseBuilding.s_BuildCheatsLevel > 0) {
			for (int i = 0; i < BaseBuilding.s_BuildCheatsLevel; i++) {
				string upgrade_type_temp = BaseBuilding.GetUpgradeType(upgrade_type);
				if (upgrade_type_temp != string.Empty) {
					upgrade_type = upgrade_type_temp;
				}
			}
		}
#endif

		BaseBuildingItemEntry upgrade = BaseBuilding.GetConstructCost(upgrade_type);
		if (!upgrade || upgrade_type == string.Empty) {
			return null;
		}
		
		return BaseBuilding.Cast(g_Game.CreateObjectEx(upgrade_type, place_hologram_data.Position, ECE_FULL | ECE_CREATEPHYSICS | ECE_NOLIFETIME)); //TEST ECE_NOLIFETIME
	}
}
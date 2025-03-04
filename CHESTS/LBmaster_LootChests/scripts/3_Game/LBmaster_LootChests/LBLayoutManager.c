modded class LBLayoutManager {

	override string GetLayoutPathOriginal(string name) {
		if (name == "AdminMenu_LBLootChestsAdminPage") return "LBmaster_LootChests/gui/layouts/adminmenu/chests.layout";
		if (name == "AdminMenu_LBChestPositionsAdminPage") return "LBmaster_LootChests/gui/layouts/adminmenu/positions.layout";
		if (name == "AdminMenu_LBKeyNamesAdminPage") return "LBmaster_LootChests/gui/layouts/adminmenu/keynames.layout";

		return super.GetLayoutPathOriginal(name);
	}

}
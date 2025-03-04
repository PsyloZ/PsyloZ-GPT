[DayZGame.RegisterLBAdminPage("LBKeyNamesAdminPage", "LBmaster_LootChests/logo/logo.paa", "Key Names", "lootchest.change.keynames")]
class LBKeyNamesAdminPage : LBAdmin_Menu_Page {

	TextWidget txt_itemname;
	MultilineEditBoxWidget edit_description;
	XComboBoxWidget combo_key;
	EditBoxWidget edit_displayname;

	override array<string> GetEditedConfigs() {
		return {"LB_LC_KeyConfig"};
	}

	override void OnShow() {
		super.OnShow();
		linked.LoadLinkedVars();
	}

	override void RegisterAllLinkedVars() {
		linked.RegisterLinkedList("GetConfig().keys", combo_key).SetListManager(new LBListManager<LB_LC_KeyEntry>());
		linked.RegisterLinkedVar("GetConfig().keys[combo_key].classname", txt_itemname);
		linked.RegisterLinkedVar("GetConfig().keys[combo_key].displayname", edit_displayname);
		linked.RegisterLinkedVar("GetConfig().keys[combo_key].description", edit_description);
	}
		
	LB_LC_KeyConfig_ GetConfig() {
		return LB_LC_KeyConfig.Get;
	}
}
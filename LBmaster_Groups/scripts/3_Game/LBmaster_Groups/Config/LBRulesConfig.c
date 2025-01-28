class LBRulesConfig : LBConfigLoader<LBRulesConfig_> {

	override void InitVars() {
		InitVarsInternal("LBGroup", "Rules.json");
	}
	
}
class LBRulesConfig_ : LBConfigBase {

	static const int CURRENT_VERSION = 1;
	
	bool enabled = false; // Enable / Disable the Rules Button in the Map Panel
	bool fullSize = true; // Set the Rules panel to full size to fill the whole screen when opened. When disabled, it will only take up the left panel on the map. Useful if you don't want to show a lot of information on this page and don't want it to take up the whole screen
	int priority = 275; // Priority for the button. Higher priorities will place it further to the left. Priorities of other buttons: (Info: 500, Group: 450, Markers: 400, Settings: 350, Achievements: 120, Item Restrictions: 100) Make sure to have a higher or lower priority setup here if you want to position it brefore or behind a button
	string buttonText = "#lb_page_rules"; // Name of the button on the Map Panel
	ref TStringArray lines = new TStringArray(); // Lines for the rules. Read the [How to format lines](/faq/?id=151)
	
}
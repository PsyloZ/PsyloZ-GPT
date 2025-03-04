class LB_LC_KeyBase : ItemBase {
	
	LB_LC_KeyEntry keyConfig;
	bool checkedKeyConfig = false;
	LB_LC_KeyConfig_ configInstance;

	override void SetActionAnimOverrides()
	{
		OverrideActionAnimation(ActionOpenLBChestKey, DayZPlayerConstants.CMD_ACTIONFB_CRAFTING, DayZPlayerConstants.STANCEIDX_ERECT);
	}
	
	LB_LC_KeyEntry GetKeyConfig() {
		if (checkedKeyConfig && keyConfig)
			return keyConfig;
		if (!configInstance) {
			configInstance = LB_LC_KeyConfig.Get;
			checkedKeyConfig = false;
		}
		if (checkedKeyConfig || !configInstance)
			return null;
		keyConfig = configInstance.GetKeyConfig(GetType());
		checkedKeyConfig = true;
		return keyConfig;
	}
	
	override bool NameOverride(out string output) {
		LB_LC_KeyEntry config = GetKeyConfig();
		if (!config)
			return super.NameOverride(output);
		output = config.displayname;
		return true;
	}
	
	override bool DescriptionOverride(out string output) {
		LB_LC_KeyEntry config = GetKeyConfig();
		if (!config)
			return super.DescriptionOverride(output);
		output = config.description;
		return true;
	}
	
}
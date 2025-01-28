class LBGroupTimeoutConfig : LBConfigLoader<LBGroupTimeoutConfig_> {

	[SetPriority(LBConfigPriority.HIGH)]
	override void InitVars() {
		InitVarsInternal("LBGroup", "Timeout.json", LBConfigType.CONFIG, true, "groups.timeout.change", "groups.timeout.change"); // (easy)
	}

}
/*Config that handles the group swap timeouts so player do not swap groups to gain advantages (disabled by default). Current timeouts are saved in the TimeoutPlayers.json
*/
class LBGroupTimeoutConfig_ : LBConfigBase {

	static const int CURRENT_VERSION = 2;

	bool enableTimeout = false; // Set to 1 to enable the timeouts
	int timeoutDifferentGroupDurationSeconds = 86400; // Time in seconds a player needs to wait until he can join a different group than his last group (The timer will start when the player joined the first group and not when he left)
	int timeoutSameGroupDurationSeconds = 3600; // Time in seconds a player needs to wait until he can join the same group he was in before (The timer starts when he joins the first group)

}
class LB_LC_Base : Container_Base {

	ref OpenableBehaviour openable;
	ref LB_LC_SpawnedChestInfo chestInfo;
	bool lb_mustOpen = false;

	void LB_LC_Base() {
		openable = new OpenableBehaviour(false);
		RegisterNetSyncVariableBool("openable.m_IsOpened");
		RegisterNetSyncVariableBool("lb_mustOpen");
		SetTakeable(false);
	}

	// List, which keeps track of all the spawned loot chests. Never spawn a loot chest manually! they will not work! This array is only populated on the server, not on the client!
	static ref array<LB_LC_Base> allSpawnedChests = new array<LB_LC_Base>();
	
	LB_LC_Chest GetChestConfig(); // Get the ChestConfig of this chest (implemented serverside)
	
	LB_LC_ChestSpawnPos GetSpawnPos(); // Get the Spawn Position of this chest (implemented serverside)
	
	// To interact with the chest via script, use the Open() and Close() methods. Be aware, that close only closes the chest, but does not delete any items still remaining inside!!
	// when calling Open, you should first check IsOpen() to not open it twice and spawn loot twice!
	// Open will change the visuals, play the sound and also spawn the loot and start the Respawn Timer of the crate, when configured

	// This method is implemented serverside and should also not be called on the client
	// force: true will ignore any players nearby, otherwise the settings in the config apply. When the chest cannot be deleted, because a player nearby, it will retry after 30 seconds until it succeedes
	// forceSamePos: it is not guaranteed the chest will respawn at the same location. It will pick a new position from the position pool it belongs to. Setting this to true will force it to respawn at the same position
	void Respawn(bool force = false, bool forceSamePos = false);
	
	// Callback when the chest is spawned and setup
	// pos: The position the chest was spawned at
	// always call super.OnSpawned(pos); !! You will break stuff if you don't do that
	void OnSpawned(LB_LC_ChestSpawnPos pos);

#ifndef SERVER
	override void EEInit() {
		super.EEInit();
		g_Game.RPCSingleParam(this, LB_LC_RPCs.CHEST_INFO, new Param1<bool>(true), true);
	}

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx) {
		super.OnRPC(sender, rpc_type, ctx);
		if (rpc_type == LB_LC_RPCs.CHEST_INFO) {
			ctx.Read(chestInfo);
		}
	}
#endif

	bool RequiresKeyToOpen() {
		return !chestInfo || chestInfo.keys.Count() > 0;
	}
	
	override bool NameOverride(out string output) {
		if (chestInfo) {
			output = chestInfo.displayname;
			return true;
		}
		return super.NameOverride(output);
	}

	override bool DescriptionOverride(out string output) {
		if (chestInfo) {
			output = chestInfo.description;
			return true;
		}
		return super.DescriptionOverride(output);
	}

	override bool CanPutInCargo(EntityAI parent) {
		return false;
	}

	override bool CanReceiveAttachment(EntityAI attachment, int slotId) {
		return false;
	}

	override bool CanPutIntoHands(EntityAI parent) {
		return false;
	}

	override bool CanDisplayCargo() {
		return super.CanDisplayCargo() && IsOpen();
	}

	override bool CanReceiveItemIntoCargo(EntityAI item) {
		return false;
	}

	override void SetActions() {
		super.SetActions();
		AddAction(ActionOpenLBChest);
	}

	override bool IsOpen() {
		return !lb_mustOpen || openable.IsOpened();
	}

}
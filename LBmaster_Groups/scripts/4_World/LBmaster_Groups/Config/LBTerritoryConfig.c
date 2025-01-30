#ifdef LBmaster_GroupDLCPlotpole
class LBTerritoryConfig : LBConfigLoader<LBTerritoryConfig_> {

	override void InitVars() {
		InitVarsInternal("LBGroup", "PlotpoleConfig.json", LBConfigType.CONFIG, true, "groups.territory.change"); // (hard)
	}

}
/*This is the Main Config with all Plotpole Settings:

Check the [How do I install the Plotpole DLC ?](/faq/?id=103) on how to install the Plotpole DLC

If you have any issues setting it up, refer to the [My Items in the Territories are despawning](/faq/?id=104) and [How do I properly setup the Plotpole variables](/faq/?id=106) FAQ entries
*/
class LBTerritoryConfig_ : LBConfigBase {

	static const int CURRENT_VERSION = 13;

	bool enablePlotpoleExtension = false; // Must be set to 1. Otherwise everything is disabled !
	bool enabledDebugLifetimePrints = false; // Enable if all objects, which are refreshed by the flag should be printed to the log to find any missing items and troubleshoot
	bool syncPlotpolesToCFCloud = true; // Show Plotpoles on the CF Cloud interactive Map
	bool doObjectLifetimeReset = true; // Reset the Lifetime of objects within the Plotpole Radius. When disabled, the Flag will not reset the lifetime of the objects placed and they might despawn
	int flagLifetimeRefreshTime = 432000; // analog to the `FlagRefreshFrequency` from the globals.xml. The globals.xml value will be ignored. This is the interval in seconds between two lifetime resets. All Objects, which should not despawn must have a lifetime higher than this value
	int flagUptimeDuration = 3456000; // analog to the `FlagRefreshMaxDuration` from the globals.xml. The globals.xml value will be ignored. This is how long the Flag will take from 100% up to completely lowered. When the Flag reaches the lowered state, it will once more refresh the lifetime of the objects near it and then the lifetime of the objects remain until they despawn.

	bool preventUnauthorizedDeploying = true; // Set to 1 to prevent people from deploying objects in enemy territories. This will not prevent people from dropping items like barrels !
	ref TStringArray deployInOthersTerritoryExceptions = new TStringArray(); // List of items, which can still be deployed in enemy territories like C4 or Traps
	bool forceDeployingInTerritory = true; // Set to 1 to force all players to build inside a territory. If set to 0, players can build everywhere, but they are not protected by the Flag
	ref TStringArray forceExceptions = {"Barrel_ColorBase", "TentBase"}; // Exceptions to this rule. Add things like Campfires or similar things to allow people to use them in the wild
	bool preventUnauthorizedBuilding = true; // Set to 1 to disable building basebuilding parts in enemy territories
	bool preventUnauthorizedDismantling = false; // Set to 1 to disable dismantling basebuilding parts in enemy territories
	bool preventUnauthorizedDestroying = true; // Set to 1 to disable destroying of basebuilding parts in enemy territories (DayZ changed the way basebuilding objects are destroyed !)
	bool lowerFlagWhenGroupDeleted = true; // When a group owning the flag is deleted, the flag will be lowered to 0% and no longer refreshes items. Keep in mind: Groups are deleted when the last player in the group left. When disabled, the flag will stay up and refresh all items around potentially leaving abondend bases active instead of letting them decay

	bool instantBuildPlotpole = true; // Instantly build the flagpole when the kit is placed. The Flag does not yield any ressources when destroyed
	bool instantDestroyPlotpole = true; // When any part of the Flagpole is destroyed, the whole flag will be deleted
	bool returnFlagpoleKitOnInstantDestroy = true; // Enable if the Plotpole Kit should be droppen on the ground when the flag is destroyed with `instantDestroyPlotpole` enabled
	bool allowDestroyWithFlagAttached = false; // Enable if the plotpole can be destroyed while the Flag is still attached. When disabled, players can also not cut the flag with a knife to remove the Flag from the Pole
	float maxDistanceToDismantleFlag = 10; // Change the max distance a player can be away from the base of the Flag to destroy it to prevent people from destroying it by only seeing the top of the flag through a house/base roof. Calculated from the player feet to the base of the Flagpole
	bool autoAttachFlag = false; // Attach a random Flag when instant build is enabled and choose a Flag from the list below
	bool autoRaiseFlag = false; // Raise the Flag to 100% when enabled and instant build is enabled
	ref TStringArray autoFlagAttachedItemnames = new TStringArray(); // List of Flags, that can be attached when autoAttachFlag is enabled. A random itemname will be choosen from the list
	bool displayPlotpolesOnMap = true; // Create a Marker in the Group when the Flag is placed down (this is not public and can be removed)
	bool allowOthersPlotpoleDestroy = true; // Set to 1 to allow players not owning the Flag to destroy it (destroying a flag requires the flag to be lowered !)
	float maxDistanceToLowerFlag = 10; // Similar to the `maxDistanceToDismantleFlag`, but for lowering the flag. Calculated from the player feet to the base of the Flagpole
	bool allowOthersPlotpoleLowerFlag = true; // Set to 1 to allow players not owning the Flag to lower it and stop the lifetime reset of the Basebuilding items

	bool allowDismantleInUnclaimedTeritorry = true; // Set to 1 to allow anybody to dismantle unprotected basebuilding items e.g. The Flag is despawned or the Group owning it was deleted
	bool allowDestroyInUnclaimedTeritorry = true; // Set to 1 to allow anybody to destroy unprotected basebuilding items e.g. The Flag is despawned or the Group owning it was deleted

	float plotpoleRadius = 30.0; // Radius of the Plotpole (Shape of the Radius is a Cylinder, not a Sphere !)
	float plotpoleHeightUp = 30.0; // Height up of the Plotpole radius from the center of the plotpole
	float plotpoleHeightDown = 30.0; // Height down from the Plotpole center
	float plotpoleRadius_InsidePvEZone = 10.0; // Overwrites the radius of the flag when inside a PvE Zone (PVEZ mod supported)
	float plotpoleHeightUp_InsidePvEZone = 10.0; // Overwrites the radius of the flag when inside a PvE Zone (PVEZ mod supported)
	float plotpoleHeightDown_InsidePvEZone = 10.0; // Overwrites the radius of the flag when inside a PvE Zone (PVEZ mod supported)
	float plotpoleDistanceMinHostile = 200.0; // Minimum distance between Plotpoles when owned by different Groups. Also checked when trying to claim a flag
	float plotpoleDistanceMinFriendly = 100.0; // Minimum distance between Plotpoles when owned by the same Group. Also checked when trying to claim a flag
	int defaultPlotpoleCountPerGroup = 2; // Plotpole Limit for each Group (can be upgraded via the Level.json)

	[NonSerialized()]
	bool needCEApiValues = false;

	float GetMaxRadius() {
		return Math.Max(plotpoleRadius, plotpoleRadius_InsidePvEZone);
	}

	[NonSerialized()]
	int lastNotification = 0;

	void AddClientNotification(string message) {
		if (g_Game.IsClient() && g_Game.GetTime() - lastNotification > 11000) {
			NotificationSystem.AddNotificationExtended(4.0, "#lb_message_group_system", message, "set:ccgui_enforce image:MapDestroyed");
			lastNotification = g_Game.GetTime();
		}
	}

	void SendPlayerNotification(PlayerBase player, string message) {

		if (!player || !player.GetIdentity() || !g_Game.IsServer())
			return;
		NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 4.0, "#lb_message_group_system", message, "set:ccgui_enforce image:MapDestroyed");
	}

	bool CanExecuteAction(PlayerBase player, vector pos, int type, ItemBase itemInHands) {
		if (!enablePlotpoleExtension)
			return true;
		if (type == 0 && !preventUnauthorizedDeploying)
			return true;
		if (type == 1 && !preventUnauthorizedBuilding)
			return true;
		if (type == 2 && !preventUnauthorizedDismantling)
			return true;
		if (type == 3 && !preventUnauthorizedDestroying)
			return true;
		if (type == 5 && allowOthersPlotpoleDestroy)
			return true;
		if (type == 6 && allowOthersPlotpoleLowerFlag)
			return true;
		LBGroup grp = player.GetLBGroup();
		LBGroupPermission perms = player.GetPermission();
		string tagLower = "";
		if (grp) {
			tagLower = grp.shortname + "";
			tagLower.ToLower();
		}
		int groupTagHash = tagLower.Hash();

		#ifdef RA_BaseBuilding_Scripts
			TerritoryHQ nearestHostile = TerritoryHQ.FindNearestFlag(pos, true, false, groupTagHash);
			TerritoryHQ nearestFriendly = TerritoryHQ.FindNearestFlag(pos, true, true, groupTagHash);
			TerritoryHQ nearest = nearestHostile;
		#else
			TerritoryFlag nearestHostile = TerritoryFlag.FindNearestFlag(pos, true, false, groupTagHash);
			TerritoryFlag nearestFriendly = TerritoryFlag.FindNearestFlag(pos, true, true, groupTagHash);
			TerritoryFlag nearest = nearestHostile;
		#endif
		
		if (nearestFriendly && (!nearest || vector.Distance(pos, nearest.GetPosition()) > vector.Distance(pos, nearestFriendly.GetPosition()))) {
			nearest = nearestFriendly;
		}
		if (type == 4) {
			if (!grp || !perms) {
				AddClientNotification("#lb_message_squad_required_to_setup_plotpole");
				return false;
			} else {

				if (LBAdmins.Get().HasPermission("build.everywhere", player) && LBAdmins.Get().IsActive(player))
					return true;
				if (!perms.canDoBasebuilding) {
					AddClientNotification("#lb_ag_message_no_permission_bb");
					return false;
				}

				bool canIgnoreBuildLimit = false;
				if (LBAdmins.Get().HasPermission("build.limit.ignore", player) && LBAdmins.Get().IsActive(player))
					canIgnoreBuildLimit = true;
				if (!canIgnoreBuildLimit && g_Game.IsServer()) {
					int has = grp.GetOwnedPlotpolesCount();
					int max = grp.plotpoleLimit;
					if (has >= max) {
						SendPlayerNotification(player, "#lb_message_max_plotpole_reached (" + has + "/" + max + ")");
						return false;
					}
				}
				if (nearestFriendly && vector.Distance(nearestFriendly.GetPosition(), pos) <= plotpoleDistanceMinFriendly) {
					AddClientNotification(LBTranslatedString("#lb_ag_message_to_near_friendly", {"%distance%", "" + plotpoleDistanceMinFriendly}).Get());
					return false;
				}
				if (nearestHostile && vector.Distance(nearestHostile.GetPosition(), pos) <= plotpoleDistanceMinHostile) {
					AddClientNotification(LBTranslatedString("#lb_ag_message_to_near_hostile", {"%distance%", "" + plotpoleDistanceMinHostile}).Get());
					return false;
				}
				return true;
			}
		}
		
		#ifdef DIAG
				LBLogger.Verbose("Nearest Flag at: " + pos + " is " + nearest, "Plotpole");
		#endif

		#ifdef RA_BaseBuilding_Scripts
			if (type == 0 && (!nearest || !nearest.IsWithinTerritoryRange(player, pos))) {
		#else
			if (type == 0 && (!nearest || !nearest.IsInRadius(pos))) {
		#endif

			if (forceDeployingInTerritory && !IsItemWhitelisted(itemInHands)) {

				if (LBAdmins.Get().HasPermission("build.everywhere", player) && LBAdmins.Get().IsActive(player))
					return true;
				AddClientNotification("#lb_message_only_deploy_in_own_territorry");
				return false;
			}
			return true;
		}
		if (IsDeployException(itemInHands) && (type == 1 || type == 0 || type == 3))
			return true;

		#ifdef DIAG
				LBLogger.Verbose("Own Group Hash: " + groupTagHash + " Tag: " + tagLower + " Flag Hash: " + nearest.ownerGroupTagHash, "Plotpole");
		#endif

		if (grp && nearest && groupTagHash == nearest.ownerGroupTagHash) {
			if (LBAdmins.Get().HasPermission("groups.build.enemy", player) && LBAdmins.Get().IsActive(player))
				return true;
			return perms.canDoBasebuilding;
			//nearest.ownerGroupTagHash is 0 when no group assigned
		#ifdef RA_BaseBuilding_Scripts
			} else if (!nearest || nearest && nearest.ownerGroupTagHash == 0 && nearest.IsWithinTerritoryRange(player, pos, 5)) {
		#else
			} else if (!nearest || nearest && nearest.ownerGroupTagHash == 0 && nearest.IsInRadius(pos, 5)) {
		#endif


			if (LBAdmins.Get().HasPermission("build.everywhere", player) && LBAdmins.Get().IsActive(player))
				return true;
			if (type == 2) // Dismantle Action
				return allowDismantleInUnclaimedTeritorry;
			if (type == 3) // Destroy Action
				return allowDestroyInUnclaimedTeritorry;
			if (type == 5) // Destroy / Dismantle Teritorry Flag
				return allowDestroyInUnclaimedTeritorry;
			if (type == 6) // Destroy / Dismantle Teritorry Flag
				return allowDestroyInUnclaimedTeritorry;

		}
		return LBAdmins.Get().HasPermission("groups.build.enemy", player) && LBAdmins.Get().IsActive(player);
	}

	bool IsDeployException(ItemBase item) {
		if (!item)
			return false;
		string itemType = item.GetType();
		foreach (string typestr : deployInOthersTerritoryExceptions) {
			if (typestr == itemType)
				return true;
			typename typen = typestr.ToType();
			if (!typen)
				continue;
			if (item.IsInherited(typen))
				return true;
		}
		return false;
	}

	bool IsItemWhitelisted(ItemBase item) {
		if (!item)
			return false;
		string itemType = item.GetType();
		foreach (string typestr : forceExceptions) {
			if (typestr == itemType)
				return true;
			typename typen = typestr.ToType();
			if (!typen)
				continue;
			if (item.IsInherited(typen))
				return true;
		}
		return false;
	}

	bool CanExecuteAction(PlayerBase player, ActionTarget target, int type, ItemBase itemInHands) {
		Object obj = target.GetObject();
		if (!obj)
			obj = target.GetParent();
		vector pos = player.GetPosition();
		if (obj)
			pos = obj.GetPosition();
		return CanExecuteAction(player, pos, type, itemInHands);
	}
}
#endif

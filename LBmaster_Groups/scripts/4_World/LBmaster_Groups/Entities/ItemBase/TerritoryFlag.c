#ifdef LBmaster_GroupDLCPlotpole
modded class TerritoryFlag {

	static ref array<TerritoryFlag> all_Flags = new array<TerritoryFlag>();

	string ownerGroupTag = "";
	int ownerGroupTagHash = 0;
	bool checkedInPVEZArea = false;
	bool inPVEZArea = false;
	bool dismantleWorkaround = false;

	void TerritoryFlag() {
		if (all_Flags)
			all_Flags.Insert(this);
		RegisterNetSyncVariableInt("ownerGroupTagHash");
	}

	void ~TerritoryFlag() {
		if (all_Flags)
			all_Flags.RemoveItem(this);
	}

	override EntityAI FindAttachmentBySlotName(string slot_name) {
		if (dismantleWorkaround && slot_name == "Material_FPole_Flag")
			return null;
		return super.FindAttachmentBySlotName(slot_name);
	}

	override void OnPartDismantledServer(notnull Man player, string part_name, int action_id) {
		super.OnPartDismantledServer(player, part_name, action_id);
		if (LBTerritoryConfig.Get.allowDestroyWithFlagAttached && FindAttachmentBySlotName("Material_FPole_Flag")) {
			g_Game.ObjectDelete(FindAttachmentBySlotName("Material_FPole_Flag"));
			AnimateFlag(0);
		}
	}

	static TerritoryFlag FindNearestFlag(vector pos, bool checkOwner = false, bool onlyOwnedByHash = false, int groupTagHash = 0) {
		float bestDist = -1;
		TerritoryFlag found = null;
		if (all_Flags) {
			foreach (TerritoryFlag flag : all_Flags) {
				if (!flag || flag.IsHologram())
					continue;
				float dist = vector.Distance(flag.GetPosition(), pos);
				if (bestDist == -1 || dist < bestDist) {
					if (!checkOwner || (onlyOwnedByHash == (flag.ownerGroupTagHash == groupTagHash))) {
						found = flag;
						bestDist = dist;
					}
				}
			}
		}
		return found;
	}

	override void OnStoreSave(ParamsWriteContext ctx) {
		super.OnStoreSave(ctx);
		ctx.Write(ownerGroupTag);
	}

	override bool OnStoreLoad(ParamsReadContext ctx, int version) {
		if (!super.OnStoreLoad(ctx, version))
			return false;
		if (!ctx.Read(ownerGroupTag))
			return false;
		SetOwnerGroup(ownerGroupTag);
#ifdef SERVER
		LBLogger.Debug("Loading Flag: " + m_SyncParts01 + "  " + m_SyncParts02 + "  " + m_SyncParts03 + "  " + m_HasBase, "Plotpole");
#endif
		return true;
	}

	void SetOwnerGroup(string tag) {
	}

	void UpdateOwnerExistence() {
	}

	LBGroup GetOwnerGroup() {
		return LBGroupManager.Get().GetGroupByHash(ownerGroupTagHash);
	}

	string GetOwnerGroupTag() {
		LBGroup grp = GetOwnerGroup();
		if (grp)
			return grp.shortname;
		return "No Group";
	}

	override void AfterStoreLoad() {
		super.AfterStoreLoad();
		UpdateOwnerExistence();
	}

	bool IsInPVEZone(bool force = false) {
		if (checkedInPVEZArea && !force)
			return inPVEZArea;
		inPVEZArea = IsInPVEZoneNonCached();
		checkedInPVEZArea = true;
		return inPVEZArea;
	}

	bool IsInPVEZoneNonCached() {
#ifdef PVEZ
		if (g_Game.pvez_Config.GENERAL.Mode == PVEZ_MODE_PVE)
			return true;
		if (g_Game.pvez_Zones.GetZoneIndex(GetPosition()) != -1) {
			return g_Game.pvez_Config.GENERAL.Mode == PVEZ_MODE_PVE_ZONES;
		} else {
			return g_Game.pvez_Config.GENERAL.Mode == PVEZ_MODE_PVP_ZONES;
		}
#endif
		return false;
	}

	void GetPlotpoleSize(out float radius, out float down, out float up) {
		radius = LBTerritoryConfig.Get.plotpoleRadius;
		down = LBTerritoryConfig.Get.plotpoleHeightDown;
		up = LBTerritoryConfig.Get.plotpoleHeightUp;
		bool inZone = false;
#ifdef PVEZ
		if (IsInPVEZone()) {
			inZone = true;
			radius = LBTerritoryConfig.Get.plotpoleRadius_InsidePvEZone;
			down = LBTerritoryConfig.Get.plotpoleHeightDown_InsidePvEZone;
			up = LBTerritoryConfig.Get.plotpoleHeightUp_InsidePvEZone;
		}
#endif
		//LBLogger.Verbose("Territory Flag at " + GetPosition() + " Is In zone ? " + inZone + " and Size is: " + radius + " " + up + " " + down, "Plotpole");
	}

	bool IsInRadius(vector pos, float additionalRadius = 0) {
		float radius, down, up;
		GetPlotpoleSize(radius, down, up);
		//LBLogger.Verbose("Territory Flag at " + GetPosition() + " Size is: " + radius + " " + up + " " + down, "Plotpole");

		radius += additionalRadius;
		vector posPlot = GetPosition();
		float distXZ = vector.Distance(Vector(pos[0], 0, pos[2]), Vector(posPlot[0], 0, posPlot[2]));
		if (distXZ > radius)
			return false;
		float distY = pos[1] - posPlot[1];
		return distY > -down && distY < up;
	}

	override void SetActions() {
		super.SetActions();
		AddAction(ActionClaimFlag);
	}

}
#endif

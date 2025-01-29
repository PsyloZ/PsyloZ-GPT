int BBCount;

class BaseBuilding: ItemBase
{
	static const string ZONE_INTERIOR = "Interior"; // soft side zone
	static const string ZONE_EXTERIOR = "Exterior"; // hard side zone
	
	static const int RPC_PLACING_COMPLETE = -2652952;
	
	static const float BUILD_HEIGHT_LIMIT = 25.0;
	
	protected ref map<string, SnapPoint> m_SnapPoints = new map<string, SnapPoint>();
	protected ref array<SnapPoint> m_LowestSnapPoints = {};	
	
	protected int m_PlaceTime;
	protected bool m_IsBeingUpgraded;
	
	// For self placing items - if it makes it into your hands you'll be able to place it
	protected ref BaseBuildingHologram m_CurrentPlacingHologram;
		
	void BaseBuilding()
	{
		SetFlags(EntityFlags.STATIC, false);

		//@ todo cache this globally on startup, doesnt need to be initialized every item, just copied
		#ifndef SERVER
			float lowest_y = FLT_MAX;
			
			string snapping_path = string.Format("CfgVehicles %1 Snapping", GetType());
			for (int i = 0; i < g_Game.ConfigGetChildrenCount(snapping_path); i++) {
				string snapping_child_name;
				if (!g_Game.ConfigGetChildName(snapping_path, i, snapping_child_name)) {
					continue;
				}
				
				if (!MemoryPointExists(snapping_child_name)) {
					continue;
				}
				
				vector snap_point_position = GetMemoryPointPos(snapping_child_name);
				SnapPoint snap_point = SnapPoint.Cast(g_Game.CreateObjectEx("SnapPoint", snap_point_position, ECE_LOCAL));
				
				bool allow_reverse = g_Game.ConfigGetInt(string.Format("%1 %2 allowReverse", snapping_path, snapping_child_name));
				snap_point.AllowReverse = allow_reverse;
				
				g_Game.ConfigGetTextArray(string.Format("%1 %2 acceptedTypes", snapping_path, snapping_child_name), snap_point.Types);
				g_Game.ConfigGetTextArray(string.Format("%1 %2 acceptedSnapPoints", snapping_path, snapping_child_name), snap_point.SnapNames);
				
				snap_point.SetName(snapping_child_name);
				vector forward = g_Game.ConfigGetVector(string.Format("%1 %2 forward", snapping_path, snapping_child_name)).Normalized();
				vector up = g_Game.ConfigGetVector(string.Format("%1 %2 up", snapping_path, snapping_child_name)).Normalized();
				
				vector snap_mat[4];
				snap_mat[0] = up * forward;
				snap_mat[1] = up;
				snap_mat[2] = forward;
				snap_mat[3] = snap_point_position;
							
				snap_point.SetTransform(snap_mat);
				AddChild(snap_point, -1);
				
				m_SnapPoints[snapping_child_name] = snap_point;
				
				if (snap_point_position[1] < lowest_y) {
					m_LowestSnapPoints.Clear();
					m_LowestSnapPoints.Insert(snap_point);
					lowest_y = snap_point_position[1];
				}
				
				// cursed
				if (snap_point_position[1] == lowest_y) {
					m_LowestSnapPoints.Insert(snap_point);
				}
			}
		#endif
		
		RegisterNetSyncVariableInt("m_PlaceTime");
				
#ifdef DIAG_DEVELOPER
		//g_Game.GetUpdateQueue(CALL_CATEGORY_GAMEPLAY).Insert(DiagUpdate);
#endif
		BBCount++;
	}
	
	void ~BaseBuilding()
	{
		BBCount--;

		foreach (SnapPoint snap_point: m_SnapPoints) {
			if (snap_point && g_Game) {
				if (!g_Game.IsDedicatedServer()) {
					g_Game.ObjectDeleteOnClient(snap_point);
				} else {
					g_Game.ObjectDelete(snap_point);
				}
			}
		}

		delete m_SnapPoints;
		delete m_LowestSnapPoints;
		delete m_CurrentPlacingHologram;
	}

	override void EEInit()
	{
		super.EEInit();
		
		UpdateNavmesh();
	}
		
/*#ifdef DIAG_DEVELOPER	
	void DiagUpdate(float dt)
	{
		if (g_Game.IsDedicatedServer()) {
			return;
		}
		
		vector pos, dir;
		int comp;
		set<Object> results = new set<Object>();
		DayZPhysics.RaycastRV(g_Game.GetCurrentCameraPosition(), g_Game.GetCurrentCameraPosition() + g_Game.GetCurrentCameraDirection() * 50, pos, dir, comp, results, null, g_Game.GetPlayer());
		if (results.Find(this) == -1) {
			return;
		}
		
		DayZPlayerUtils.DrawStartFrame();
		vector text_pos = GetPosition() + Vector(0, GetBoundingBoxSize()[1] / 2, 0);
		//DayZPlayerUtils.DrawDebugText(string.Format("Stability: %1", GetQuantity()), text_pos, 2);
		
		// draw arrows
		//set<BaseBuilding> stabilities = new set<BaseBuilding>();
		//if (!IsHologram()) {
			//DayZPlayerUtils.DrawDebugText(string.Format("Node: %1", RecursiveUpdateStability(1, stabilities)), text_pos + Vector(0, 0.2, 0), 2);
			//DayZPlayerUtils.DrawDebugText(string.Format("Node: %1", RecursiveUpdateStability(-1, stabilities)), text_pos + Vector(0, -0.2, 0), 2);
		//}
		
		if (vector.Distance(pos, g_Game.GetCurrentCameraPosition()) > 3) {
			return;
		}
		
		foreach (string name, SnapPoint snap_point: m_SnapPoints) {
			if (!snap_point) {
				continue;
			}
			
			vector world_matrix[4];
			snap_point.GetTransform(world_matrix);
			Shape.CreateMatrix(world_matrix);
			
			auto attachments = snap_point.GetAttachments();
			int snap_color = Colors.COLOR_DAYZ_SMOKY_BLUE;
			
			if (!attachments) {
				continue;
			}
			
			switch (attachments.Count()) {	
				case 1: {
					snap_color = COLOR_WHITE;
					break;
				}
				
				case 2: {
					snap_color = COLOR_YELLOW;
					break;
				}
				
				case 3: {
					snap_color = COLOR_BLUE;
					break;
				}
				
				case 4: {
					snap_color = COLOR_GREEN;
					break;
				}
			}
			
			string attachment_list = string.Empty;
			for (int i = 0; i < attachments.Count(); i++) {
				attachment_list += attachments[i].GetSource().GetDisplayName();
				if (i < attachments.Count() - 1) {
					attachment_list += ",";
				}
			}
			
			string text = string.Format("Name: %1\nSource: %2\nAttachments: [%3]", name, snap_point.GetSource(), attachment_list);
			DayZPlayerUtils.DrawDebugText(text, world_matrix[3], 1.3);		
						
			Shape.CreateSphere(snap_color, ShapeFlags.ONCE, world_matrix[3], snap_point.GetCollisionRadius());
		}
	}
#endif*/
			
	override void OnPlacementComplete(Man player, vector position = "0 0 0", vector orientation = "0 0 0")
	{
		if (!g_Game.IsDedicatedServer()) {
			SEffectManager.PlaySound("Shelter_Leather_Build_Finish_SoundSet", position);
			SEffectManager.PlaySound(GetPlaceSound(), position);
			ParticleManager.GetInstance().PlayInWorld(ParticleList.PLACEMENT_DUST, position);
		} else {
			m_PlaceTime = DateTime.Now();
			SetSynchDirty();
						
			// Update pathgraph for node objects
			UpdateNavmesh();
		}
	}
		
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
		
		switch (rpc_type) {
			// Client syncing for effects
			case RPC_PLACING_COMPLETE: {
				if (g_Game.IsDedicatedServer()) {
					break;
				}
				
				Man placing_player;
				if (!ctx.Read(placing_player)) {
					break;
				}
				
				vector position;
				if (!ctx.Read(position)) {
					break;
				}
				
				vector orientation;
				if (!ctx.Read(orientation)) {
					break;
				}
				
				OnPlacementComplete(placing_player, position, orientation);
				break;
			}
		}
	}
		
	/*bool RecursiveUpdateStability(int direction, inout set<BaseBuilding> updated_hash)
	{
		// toooodooo
		return true;
		
		BaseBuilding highest = UpdateStability(direction, updated_hash);
		if (!highest) {
			return false;
		}
		
		if (highest.IsNode()) {
			return true;
		}
		
		return highest.RecursiveUpdateStability(direction, updated_hash);
	}
	
	BaseBuilding UpdateStability(int direction, inout set<BaseBuilding> updated_hash)
	{
		return null;
		
		updated_hash.Insert(this);
		
		if (IsNode()) {
			if (g_Game.IsServer()) {
				SetQuantityMax();	
			}
			
			return this;
		}
		
		float highest_quantity = 0.0;
		BaseBuilding highest;
		foreach (string name, SnapPoint snap_point: m_SnapPoints) {
			if (!snap_point) {
				continue;
			}
			
			array<SnapPoint> attachments = snap_point.GetAttachments();
			foreach (SnapPoint attachment: attachments) {
				BaseBuilding source = attachment.GetSource();
				if (!source || source == this || updated_hash.Find(source) != -1) {
					continue;
				}
				
				// Magic
				if (direction > 0) {
					if (source.GetQuantity() < highest_quantity) {
						highest_quantity = source.GetQuantity();
						highest = source;
					}
				} else {
					if (source.GetQuantity() > highest_quantity) {
						highest_quantity = source.GetQuantity();
						highest = source;
					}
				}
			}
			
			if (g_Game.IsClient() && highest) {
				float stab = highest_quantity - GetInstabilityCofactor();
#ifdef DIAG_DEVELOPER
				Debug.DrawArrow(GetBoundingBoxCenter(), highest.GetBoundingBoxCenter(), 0.5, HSVtoARGB(highest_quantity, 100 - highest_quantity, 100, 255), ShapeFlags.ONCE);
				
				g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(Debug.DrawSphere, updated_hash.Count() * 1000, false, highest.GetPosition(), 0.3, 0x1fff7f7f, ShapeFlags.TRANSP|ShapeFlags.NOOUTLINE);
#endif
			}
		}
			
		if (g_Game.IsServer()) {			
			SetQuantity(highest_quantity - GetInstabilityCofactor());
			
			if (GetQuantity() <= 0) {
				SetHealth("GlobalHealth", "Health", 0);
			}
		}
		
		return highest;
		
	}
	
	float GetInstabilityCofactor()
	{
		return ConfigGetFloat("instabilityCofactor");
	}*/
			
	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);
		
		ctx.Write(m_PlaceTime);
	}
		
	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{
		if (!super.OnStoreLoad(ctx, version)) {
			return false;
		}

		if (!ctx.Read(m_PlaceTime)) {
			m_PlaceTime = DateTime.Now();
		}

		return true;
	}
	
	override void AfterStoreLoad()
	{
		super.AfterStoreLoad();
		
		SetSynchDirty();
		Update(); // desperado
	}

	#ifdef GameLabs
	override void EEKilled(Object killer)
	{
		super.EEKilled(killer);
		
		ItemBase item = ItemBase.Cast(killer);
		if (!item) {
			return;
		}

		PlayerBase player = PlayerBase.Cast(item.GetHierarchyRootPlayer());

		if (!player) {
			return;
		}

		LogToCF(player, "", "", string.Format("Dismantled %1 , pos: %2, utc: %3", GetType(), GetWorldPosition(), CF_Date.Now(true).DateToString()));
	}
	#endif
	
	override void AttemptDestructionBehaviour(int oldLevel, int newLevel, string zone) 
	{
		super.AttemptDestructionBehaviour(oldLevel, newLevel, zone);
		
		#ifdef SERVER
		// randomly create gibs on destroy
		if (Math.RandomIntInclusive(0, 1)) {
			ItemBase gib = ItemBase.Cast(g_Game.CreateObjectEx(GetConstructCost().Item, GetPosition() + "0 2 0", ECE_FULL));
			if (gib) {
				gib.SetDirection(vector.RandomDir());
				gib.SetQuantity(Math.RandomIntInclusive(1, GetConstructCost().Quantity));
				gib.CreateDynamicPhysics(PhxInteractionLayers.DYNAMICITEM_NOCHAR);
				gib.SetDynamicPhysicsLifeTime(5.0);
				dBodyApplyForce(gib, vector.Up * 500.0);
			}
		}

		g_Game.ObjectDelete(this);
		#endif
		
		// FIX-ME no worky :(
		if (g_Game.IsClient() && !IsHologram()) {
			SEffectManager.PlaySound(GetDestructSound(), GetPosition());
			ParticleManager.GetInstance().PlayInWorld(ParticleList.BASEBUILDINGDESTRUCT, GetPosition());
		}
	}
	
	MaterialLevel GetMaterialLevel()
	{
		return ConfigGetInt("materialLevel");
	}
	
	PlacementMode GetAllowedPlacementModes()
	{
		return ConfigGetInt("placementMode");
	}

	BaseBuildingItemEntry GetCalculatedRepairCost()
	{
		BaseBuildingItemEntry repair_cost = GetRepairCost();	
		int repair_quantity = (Math.Round(repair_cost.Quantity*GetSyncedHealth01()));
		
		return new BaseBuildingItemEntry(repair_cost.Item, repair_quantity);
	}

	BaseBuildingItemEntry GetRepairCost()
	{
		return GetRepairCost(GetType());
	}
	
	BaseBuildingItemEntry GetConstructCost()
	{
		return GetConstructCost(GetType());
	}
	
	string GetUpgradeType()
	{
		return ConfigGetString("upgradeType");
	}
	
	BaseBuildingItemEntry GetUpgradeCost()
	{
		return GetConstructCost(GetUpgradeType());
	}
	
	void SetIsBeingUpgraded(bool upgrade)
	{
		m_IsBeingUpgraded = upgrade;
	}
	
	bool IsBeingUpgraded()
	{
		return m_IsBeingUpgraded;
	}
	
	bool PlacementConformsToSurface()
	{
		return false;
	}
	
	// Can you have multiple objects snap to this point at once?
	bool IsOccupancyExclusive()
	{
		return false;
	}
	
	static bool IsSelfPlacing(string type)
	{
		return g_Game.ConfigGetInt(string.Format("CfgVehicles %1 selfPlacing", type));
	}
		
	static string GetUpgradeType(string type)
	{
		return g_Game.ConfigGetTextOut(string.Format("CfgVehicles %1 upgradeType", type));
	}

	static BaseBuildingItemEntry GetRepairCost(string type)
	{
		string item = g_Game.ConfigGetTextOut(string.Format("CfgVehicles %1 UpgradeSystem %2 Repair item", type, GetMaterialLevel(type).GetFormattedName()));
		int quantity = g_Game.ConfigGetInt(string.Format("CfgVehicles %1 UpgradeSystem %2 Repair quantity", type, GetMaterialLevel(type).GetFormattedName()));
		if (item == string.Empty || quantity == 0) {
			return null;
		}
		
		return new BaseBuildingItemEntry(item, quantity);
	}
	
	static BaseBuildingItemEntry GetConstructCost(string type)
	{
		string item = g_Game.ConfigGetTextOut(string.Format("CfgVehicles %1 UpgradeSystem %2 Construct item", type, GetMaterialLevel(type).GetFormattedName()));
		int quantity = g_Game.ConfigGetInt(string.Format("CfgVehicles %1 UpgradeSystem %2 Construct quantity", type, GetMaterialLevel(type).GetFormattedName()));
		if (item == string.Empty || quantity == 0) {
			return null;
		}
		
		return new BaseBuildingItemEntry(item, quantity);
	}
	
	static MaterialLevel GetMaterialLevel(string type)
	{
		return g_Game.ConfigGetInt(string.Format("CfgVehicles %1 materialLevel", type));
	}
	
	string GetDestructSound()
	{
		switch (GetMaterialLevel()) {
			case MaterialLevel.FRAME:
			case MaterialLevel.WOOD: return "Crash_WoodPlank_SoundSet";
			case MaterialLevel.METAL: return "Crash_MetalPlank_SoundSet";
		}
		
		// default
		return "Crash_WoodPlank_SoundSet";
	}
	
	string GetPlaceSound()
	{
		switch (GetMaterialLevel()) {
			case MaterialLevel.FRAME:
			case MaterialLevel.WOOD: return "placeHescoBox_SoundSet";
			case MaterialLevel.METAL: return "putDown_MetalPlank_SoundSet";
		}
		
		// default
		return "placeHescoBox_SoundSet";
	}
			
	//# UTC Timestamp of placement
	DateTime GetPlaceTime()
	{
		return m_PlaceTime;
	}
	
	// set to 0.0 for no small mouse wheel rotation (only free place)
	float GetSmallRotationStep()
	{
		return 0.0;
	}
	
	// Set to 0.0 for no large "R" rotation
	float GetLargeRotationStep()
	{
		return 0.0;
	}
	
	vector GetFreePlacementOffset()
	{
		return Vector(0, -0.2, 0);
	}

	bool CanPermanentlyDismantle()
	{
		return false;
	}
			
	//@ Note: PlacementMode is NOT a bitmask here. Each mode is handled individually	
	bool EvaluatePlacementCondition(PlacementMode placement_mode, vector mat[4])
	{
		if (!MemoryPointExists("boundingbox_min") || !MemoryPointExists("boundingbox_max")) {
			Error("No bounding box");
			return false;
		}
				
		vector min_max[2] = {GetMemoryPointPos("boundingbox_min"), GetMemoryPointPos("boundingbox_max")};
		vector extents = {
			Math.AbsFloat(min_max[1][0] - min_max[0][0]),
			Math.AbsFloat(min_max[1][1] - min_max[0][1]),
			Math.AbsFloat(min_max[1][2] - min_max[0][2])
		};
				
		vector center = {
			min_max[1][0] - ((min_max[1][0] - min_max[0][0]) / 2),
			min_max[1][1] - ((min_max[1][1] - min_max[0][1]) / 2),
			min_max[1][2] - ((min_max[1][2] - min_max[0][2]) / 2)
		};
		
		// Check if we are close enough to the ground, or inside
		if (placement_mode == PlacementMode.SNAP) { 
			extents = extents * 0.95;
		}
			
		array<Object> collision_exclusions = {this};		
		array<Object> collided_objects = {};
		
		vector position = center.Multiply4(mat);
		vector orientation = Math3D.MatrixToAngles(mat);	
				
		bool is_colliding = g_Game.IsBoxCollidingGeometry(position, orientation, extents, ObjIntersect.View, ObjIntersect.View, collision_exclusions, collided_objects);
/*
#ifdef DIAG_DEVELOPER
#ifndef SERVER
		vector debug_matrix[4];
		orientation.RotationMatrixFromAngles(debug_matrix);
		debug_matrix[3] = position;
		Debug.DrawSphere(position, 0.25, COLOR_BLUE, ShapeFlags.ONCE);
		//Annoying floating bounding box
		int color = COLOR_GREEN;
		if (is_colliding) {
			color = COLOR_RED;
		}
		
		Shape shape = Debug.DrawBoxEx(-extents * 0.5, extents * 0.5, color, ShapeFlags.ONCE);
		shape.SetMatrix(debug_matrix);

#endif
#endif
*/
		
		if (is_colliding) {
			foreach (Object obj: collided_objects) {
				// I forget why the plant exception was here, please comment next time
				// update 1: they're just annoying, thats why
				if (obj.IsInherited(Plant)) {
					continue;
				}

				if (obj.IsInherited(RockBase)) {
					continue;
				}

				if (obj.GetShapeName() == "dz\\structures\\industrial\\farms\\farm_strawstack.p3d") {
					continue;
				}

				if (obj.GetShapeName() == "dz\\structures\\industrial\\misc\\misc_haybale.p3d") {
					continue;
				}

				if (obj.GetShapeName() == "dz\\structures\\industrial\\misc\\misc_haybale_decayed.p3d") {
					continue;
				}

				if (obj.GetShapeName() == "dz\\structures\\walls\\wall_wood2_5.p3d") {
					continue;
				}

				if (obj.GetShapeName() == "dz\\structures_bliss\\industrial\\power\\power_wire_50_main.p3d") {
					continue;
				}

				if (obj.GetShapeName() == "dz\\structures_bliss\\industrial\\farms\\farm_manurepile.p3d") {
					continue;
				}

				if (obj.GetShapeName() == "dz\\structures\\industrial\\harbour\\boathouse_pierl.p3d") {
					continue;
				}

				if (obj.GetShapeName() == "dz\\structures\\roads\\sidewalks\\sidewalk3_border_nolc.p3d") {
					continue;
				}

				if (obj.GetShapeName() == "dz\\structures\\industrial\\harbour\\pier_concrete2_end.p3d") {
					continue;
				}

				ItemBase item_base = ItemBase.Cast(obj);
				if (item_base && item_base.IsIgnoredByConstruction()) {
					continue;
				}

				return false;
			}
		}
		
		return true;
	}
	
	array<BaseBuilding> GetNearbyBuildings(float size = 2)
	{
		vector max = GetPosition() + Vector(size, size, size);
		vector min = GetPosition() - Vector(size, size, size);
		
		array<EntityAI> entities = {};
		DayZPlayerUtils.SceneGetEntitiesInBox(min, max, entities);
		array<BaseBuilding> results = {};
		foreach (EntityAI entity: entities) {
			BaseBuilding result = BaseBuilding.Cast(entity);
			if (result && result != this && !result.IsHologram()) {
				results.Insert(result);
			}
		}
		
		return results;
	}
				
	// The stability attachment points will always be at the bottom
	array<SnapPoint> GetLowestSnapPoints()
	{
		return m_LowestSnapPoints;
	}
		
	SnapPoint GetSnapPoint(string snap_point)
	{
		return m_SnapPoints[snap_point];
	}
	
	map<string, SnapPoint> GetSnapPoints()
	{
		return m_SnapPoints;
	}
	
	array<SnapPoint> GetSnapPointsArray()
	{
		return m_SnapPoints.GetValueArray();
	}
	
	BaseBuildingHologram GetCurrentPlacingHologram()
	{
		return m_CurrentPlacingHologram;
	}
				
	// index 0: min
	// index 1: max
	bool GetBoundingBox(out vector min_max[2])
	{
		if (!MemoryPointExists("boundingbox_min") || !MemoryPointExists("boundingbox_max")) {
			return false;
		}
		
		min_max[0] = GetMemoryPointPos("boundingbox_min");
		min_max[1] = GetMemoryPointPos("boundingbox_max");
		return true;
	}
	
	vector GetBoundingBoxSize()
	{
		vector min_max[2];
		if (!GetBoundingBox(min_max)) {
			return vector.Zero;
		}
		
		vector box_size;
		box_size[0] = Math.AbsFloat(min_max[1][0] - min_max[0][0]);
		box_size[1] = Math.AbsFloat(min_max[1][1] - min_max[0][1]);
		box_size[2] = Math.AbsFloat(min_max[1][2] - min_max[0][2]);
		return box_size;
	}
	
	//@ Returns value in world coordinates
	vector GetBoundingBoxCenter()
	{
		vector min_max[2];
		if (!GetBoundingBox(min_max)) {
			return vector.Zero;
		}
		
		vector center;
		center[0] = (min_max[1][0] - min_max[0][0]) / 2;
		center[1] = (min_max[1][1] - min_max[0][1]) / 2;
		center[2] = (min_max[1][2] - min_max[0][2]) / 2;
		center = Vector(min_max[1][0] - center[0], min_max[1][1] - center[1], min_max[1][2] - center[2]); //offset to box center
		return ModelToWorld(center);
	}
	
	override float GetCostToUpkeep()
	{
		return 0.5;
	}
	
	override bool IsIgnoredByConstruction()
	{
		return false;
	}
	
	override bool CanObstruct()
	{
		return true;
	}
	
	override int GetHideIconMask()
	{
		return EInventoryIconVisibility.HIDE_VICINITY;
	}
	
	override bool CanPutInCargo(EntityAI parent)
	{
		return false;
	}
	
	override bool CanRemoveFromCargo(EntityAI parent)
	{
		return false;
	}

	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}
	
	override bool IgnoreOutOfReachCondition()
	{
		return true;
	}
	
	override bool DisableVicinityIcon()
	{
		return true;
	}
	
	override int GetMeleeTargetType()
	{
		return EMeleeTargetType.ALIGNABLE;
	}
	
	override bool IsInventoryVisible()
	{
		return false;
	}
	
	override bool CanDropEntity(notnull EntityAI item)
	{
		return false;
	}
	
	override bool IsBuilding()
	{
		return true;
	}
		
	//@ Quick surrounding helper function
	static ConstructFailType CheckBuildCondition(notnull PlayerBase player, notnull BaseBuilding base_building, BaseBuildingItemEntry required_materials = null)
	{
		// Territory check
		vector position = base_building.GetPosition();
		if (!TerritoryHQ.HasPermissionsAtPosition(player, position) && !base_building.CanPlaceInEnemyTerritory()) {
			return ConstructFailType.TERRITORY;
		}
		
		// NBZ check
		if (!NoBuildZone.HasPermissionsAtPosition(position) && !base_building.CanPlaceInEnemyTerritory()) {
			return ConstructFailType.NOBUILDZONE;
		}
		
#ifdef DIAG_DEVELOPER
#else
#ifndef REARMED_DEATHMATCH
		// Materials check, DIAG and DM don't need this
		if (required_materials && !player.HasMaterials(required_materials)) {
			return ConstructFailType.MATERIALS;
		}
#endif
#endif
		
		if (position[1] - g_Game.SurfaceY(position[0], position[2]) > BUILD_HEIGHT_LIMIT) {
			return ConstructFailType.HEIGHT;
		}

		RA_CodeLock code_lock = RA_CodeLock.Cast(base_building.FindAttachmentBySlotName("CodeLock"));
		if (code_lock && code_lock.IsLocked() && !code_lock.IsAuthorized(player.GetIdentity())) {
			return ConstructFailType.LOCKED;
		}
		
		return ConstructFailType.NONE;
	}
			
	static array<BaseBuilding> GetBuildingsInBox(vector position, float size, notnull array<BaseBuilding> ignore)
	{
		vector max = position + Vector(size, size, size);
		vector min = position - Vector(size, size, size);
		
		array<EntityAI> entities = {};
		DayZPlayerUtils.SceneGetEntitiesInBox(min, max, entities);
		array<BaseBuilding> results = {};
		foreach (EntityAI entity: entities) {
			BaseBuilding result = BaseBuilding.Cast(entity);
			if (result && ignore.Find(result) == -1 && !result.IsHologram()) {
				results.Insert(result);
			}
		}
		
		return results;
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);

		if (CamoNet.Cast(item)) { 
			SetAnimationPhase("hide",0); 
			return;
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item, slot_name);

		if (CamoNet.Cast(item)) { 
			SetAnimationPhase("hide",1); 
			return;
		}
	}
		
#ifdef DIAG_DEVELOPER
	static int s_BuildCheatsLevel;
	static int s_BuildDecayRate;
#endif

	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionDetachFromBase);
	}

	override float GetTimeToDecay()
	{
		switch (GetMaterialLevel()) {
			case MaterialLevel.FRAME: return 2.0 * 60.0 * 60.0; //2 hours
			case MaterialLevel.WOOD: return 12.0 * 60.0 * 60.0; //12 hours
			case MaterialLevel.METAL: return 18.0 * 60.0 * 60.0; //18 hours
			case MaterialLevel.CONCRETE: return 24.0 * 60.0 * 60.0; //24 hours
		}

		return 24.0 * 60.0 * 60.0; //24 hours
	}

	void UpdateNavmesh()
	{
		SetAffectPathgraph(true, false);
		g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(g_Game.UpdatePathgraphRegionByObject, 100, false, this);
	}
}

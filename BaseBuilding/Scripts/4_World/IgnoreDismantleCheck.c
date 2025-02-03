modded class ActionDismantleBase: ActionContinuousBase
{
	#ifndef SERVER
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		BaseBuilding base_building = BaseBuilding.Cast(target.GetObject());
		if (!base_building) {
			return false;
		}

		if (!TerritoryHQ.HasPermissionsAtPosition(player, base_building.GetPosition())) {
			return false;
		}

		if (BaseBuilding.CheckBuildCondition(player, base_building) != ConstructFailType.NONE) {
			return false;
		}
		
		m_Text = string.Format("Remove %1", base_building.GetDisplayName());
		return true;
	}
	#endif
}

modded class ScriptedExplosion: ScriptedEntity
{
    void DoExplosion(EntityAI source)
	{
		if (!GetGame().IsServer()) {
			return;
		}
		
		// pretty simple we need to just check for things in the immediate radius
		// each object should be damaged exactly the same
		array<ref SphereCastResult> results = ShapeCast.Sphere(GetPosition(), GetExplosionRadius(), source, GetExplosionCheckIterations(), GetPenetrationDepth(), ObjIntersectFire);
		
		// pen level, component
		map<EntityAI, int> unique_objects_and_pen_level = new map<EntityAI, int>();
		foreach (SphereCastResult result: results) {
			BaseBuilding entity = BaseBuilding.Cast(result.Target);
			if (!entity) {
				continue;
			}
			
			if (!unique_objects_and_pen_level.Contains(entity)) {
				unique_objects_and_pen_level[entity] = GetPenetrationDepth();
			}

			unique_objects_and_pen_level[entity] = Math.Min(unique_objects_and_pen_level[entity], result.PenetrationLevel);
		}

		foreach (EntityAI unique_object, int unique_pen: unique_objects_and_pen_level) {
			float health_change = GetExplosiveDamage() * Math.Pow(GetPenetrationFalloff(), unique_pen);
			//float health_change = GetExplosiveDamage(); // FIX-ME, penetration values from ShapeCast.Sphere are wrong
			if (!OnDamageCalculated(unique_object, health_change, unique_pen)) {
				continue;
			}
			
			// really should use a switch for this but cba
			BaseBuilding item_base = BaseBuilding.Cast(unique_object);
            BaseBuilding_SingleDoorBase isDoor = BaseBuilding_SingleDoorBase.Cast(unique_object);
			BaseBuilding_CompoundWallBase isCWall = BaseBuilding_CompoundWallBase.Cast(unique_object);
			BaseBuilding_CompoundGateBase isCGate = BaseBuilding_CompoundGateBase.Cast(unique_object);
			BaseBuilding_GarageDoorBase isGDoor = BaseBuilding_GarageDoorBase.Cast(unique_object);
			BaseBuilding_LadderHatchBase isLHatch = BaseBuilding_LadderHatchBase.Cast(unique_object);
			BaseBuilding_DoubleDoorBase isDDoor = BaseBuilding_DoubleDoorBase.Cast(unique_object);
			BaseBuilding_DoorFrameBase isDF = BaseBuilding_DoorFrameBase.Cast(unique_object);
			BaseBuilding_DoubleDoorFrameBase isDDF = BaseBuilding_DoubleDoorFrameBase.Cast(unique_object);


			if (item_base) {
                if (isDoor || isCWall || isCGate || isGDoor || isLHatch || isDDoor || isDF || isDDF){
				    item_base.DecreaseHealth("GlobalHealth", "Health", health_change);
				    item_base.SetHealthSynchDirty();
                }
			}
		}

#ifdef REARMED_SERVER
#ifndef REARMED_DEATHMATCH
		array<Man> players = {};
		GetGame().GetPlayers(players);
		foreach (Man man: players) {
			if (vector.DistanceSq(man.GetPosition(), GetPosition()) > CombatLogSettings.RADIUS_SQ) {
				continue;
			}
			
			PlayerBase player = PlayerBase.Cast(man);
			if (!player) {
				continue;
			}
			
			player.SetCombatTimer(CombatLogSettings.TIME_RAID);
		}
#endif
#endif

		// this is vanillas crappy way to make it do the explosion particle
		DamageSystem.ExplosionDamage(source, null, GetExplosiveType(), GetPosition(), DT_EXPLOSION);
		ScriptRPC().Send(this, ERPCs.RPC_EXPLODE_EVENT, true);
		
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(Delete, 100);
	}
}

modded class BaseBuilding: ItemBase
{
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
			extents = extents * 0.9;
		}
			
		array<Object> collision_exclusions = {this};		
		array<Object> collided_objects = {};
		
		vector position = center.Multiply4(mat);
		vector orientation = Math3D.MatrixToAngles(mat);	
				
		bool is_colliding = GetGame().IsBoxCollidingGeometry(position, orientation, extents, ObjIntersect.View, ObjIntersect.View, collision_exclusions, collided_objects);

#ifdef MTP_DEBUG_CLIENT
#ifndef SERVER
		vector debug_matrix[4];
		orientation.RotationMatrixFromAngles(debug_matrix);
		debug_matrix[3] = position;
		
		Debug.DrawSphere(position, 0.25, COLOR_BLUE, ShapeFlags.ONCE);

		int color = COLOR_GREEN;
		if (is_colliding) {
			color = COLOR_RED;
		}
		
		Shape shape = Debug.DrawBoxEx(-extents * 0.5, extents * 0.5, color, ShapeFlags.ONCE);
		shape.SetMatrix(debug_matrix);
#endif
#endif
		
		return true;
	}

	array<BaseBuilding> GetNearbyBuildings(float size = 2)
	{
		vector max = GetPosition() + Vector(size, size, size);
		vector min = GetPosition() - Vector(size, size, size);
		
		array<EntityAI> entities = {};
		DayZPlayerUtils.SceneGetEntitiesInBox(min, max, entities);
		array<BaseBuilding> results = {};
		
		return results;
	}

	static array<BaseBuilding> GetBuildingsInBox(vector position, float size, notnull array<BaseBuilding> ignore)
	{
		vector max = position + Vector(size, size, size);
		vector min = position - Vector(size, size, size);
		
		array<EntityAI> entities = {};
		DayZPlayerUtils.SceneGetEntitiesInBox(min, max, entities);
		array<BaseBuilding> results = {};
		
		return results;
	}


	bool CanPermanentlyDismantle()
	{
		return true;
	}
}

modded class BaseBuilding_FoundationBase: BaseBuilding
{
	static const float MAX_Y_HEIGHT = 20.0;
	static const float MIN_Y_HEIGHT = 0.2;
	
	override float GetSmallRotationStep()
	{
		return 1.0;
	}
}

modded class BaseBuilding_RoofBase: BaseBuilding
{	
	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);

		if (CamoNet.Cast(item)) { 
			SetAnimationPhase("hide",1); 
			return;
		}
	}
	
	override float GetSmallRotationStep()
	{
		return 1.0;
	}
}

modded class BaseBuilding_FloorBase: BaseBuilding
{	
	override float GetSmallRotationStep()
	{
		return 1.0;
	}
}

modded class BaseBuilding_TriangleFloorBase: BaseBuilding
{	
	override float GetSmallRotationStep()
	{
		return 1.0;
	}
}

modded class BaseBuilding_WallBase: BaseBuilding
{	
	override float GetSmallRotationStep()
	{
		return 1.0;
	}
}

modded class BaseBuilding_HalfWallBase: BaseBuilding
{	
	override float GetSmallRotationStep()
	{
		return 1.0;
	}
}

modded class BaseBuilding_WindowFrameBase: BaseBuilding
{	
	override float GetSmallRotationStep()
	{
		return 1.0;
	}
}

modded class BaseBuilding_DoorFrameBase: BaseBuilding
{	
	override float GetSmallRotationStep()
	{
		return 1.0;
	}
}

modded class BaseBuilding_DoubleDoorFrameBase: BaseBuilding
{	
	override float GetSmallRotationStep()
	{
		return 1.0;
	}
}

modded class BaseBuilding_LadderHatchBase: BaseBuilding_FloorBase
{
	override void EEDelete(EntityAI parent)
	{
		if (!g_Game.IsServer()) {
			return;
		}

		super.EEDelete(parent);
		
		BaseBuilding_HatchLadderBase door = GetDoor();
		if (door && !IsBeingUpgraded())
		{
			BaseBuilding_Ladder_Memory m_Ladder = BaseBuilding_Ladder_Memory.Cast(door.GetLadderMemory());
			if (door.IsOpen() && m_Ladder) {
				PlayerBase player = PlayerBase.Cast(m_Ladder.GetPlayer())
				if (m_Ladder && player && player.GetRAIsOnLadder()) {
					return;
				}
			}
			door.IsOpen();
		}
	}
}
class ScriptedExplosion: ScriptedEntity
{
    void DoExplosion(EntityAI source)
	{
		if (!g_Game.IsServer()) {
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
			
			BaseBuilding item_base = BaseBuilding.Cast(unique_object);
			if (item_base) {
				item_base.DecreaseHealth("GlobalHealth", "Health", health_change);
				item_base.SetHealthSynchDirty();
			}
		}

#ifdef REARMED_SERVER
#ifndef REARMED_DEATHMATCH
		array<Man> players = {};
		g_Game.GetPlayers(players);
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
		
		g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(Delete, 100);
	}

	// this is for player damage in the Explode script
	string GetExplosiveType()
	{	
		return "Plastic_Explosive_Ammo";
	}

	// each object will be damaged once
	float GetExplosiveDamage()
	{
		return 0.0;
	}

	float GetExplosionRadius()
	{
		return 1.0;
	}

	array<int> GetExplosionParticles()
	{
		return { ParticleList.PLASTIC_EXPLOSION };
	}

	int GetExplosionCheckIterations()
	{
		return 30;
	}

	// lol
	// return 0 for no penetration
	int GetPenetrationDepth()
	{
		return 0;
	}

	// damage *= (GetPenetrationFalloff()^penetration_level)
	float GetPenetrationFalloff()
	{
		return 0.65;
	}

	// called right before damage is applied. 
	// @return true if you want to apply the damage
	bool OnDamageCalculated(Object target, float damage, int penetration_level)
	{
		return true;
	}
}
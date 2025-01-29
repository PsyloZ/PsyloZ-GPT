class C4Explosion: ScriptedExplosion
{
	override string GetExplosiveType()
	{	
		return "C4_Explosive_Ammo";
	}
	
	override float GetExplosiveDamage()
	{
		return 1275.0;
	}
	
	override float GetExplosionRadius()
	{
		return 0.1;
	}
	
	override bool OnDamageCalculated(Object target, float damage, int penetration_level)
	{
		if (target.IsInherited(PlaceableExplosivesBase) || target.IsInherited(House)) {
			return false;
		}
		
		return super.OnDamageCalculated(target, damage, penetration_level);
	}
}
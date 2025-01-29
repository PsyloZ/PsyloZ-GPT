class Explosive_Bolt: ScriptedExplosion
{
	override string GetExplosiveType()
	{
		return "M67Grenade_Ammo";
	}
	
	override array<int> GetExplosionParticles()
	{
		return { ParticleList.M67 };
	}

	override float GetExplosiveDamage()
	{
		return 25.0;
	}

	override float GetExplosionRadius()
	{
		return 0.1;
	}
}
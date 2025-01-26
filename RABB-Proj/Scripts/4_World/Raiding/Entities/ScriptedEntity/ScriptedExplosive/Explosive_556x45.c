class Explosive_556x45: ScriptedExplosion
{
	override string GetExplosiveType()
	{
		return "Shot_556x45_Explosion";
	}
	
	override array<int> GetExplosionParticles()
	{
		return { ParticleList.M67 };
	}

	override float GetExplosiveDamage()
	{
		return 53.0;
	}

	override float GetExplosionRadius()
	{
		return 0.12;
	}

	override int GetPenetrationDepth()
	{
		return 1;
	}

	override int GetExplosionCheckIterations()
	{
		return 8;
	}
}
#ifdef REARMED_SERVER
class Explosive_AH6Rocket: ScriptedExplosion
{
	override string GetExplosiveType()
	{
		return "C4_Explosive_Ammo";
	}

	override float GetExplosiveDamage()
	{
		return 750.0;
	}

	override float GetExplosionRadius()
	{
		return 0.1;
	}
}
#endif
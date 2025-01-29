class RA_Improvised_C4: PlaceableExplosivesBase
{
	override float GetArmDelay()
	{
		return 58.0;
	}
	
	override typename GetExplosiveType()
	{
		return ImprovisedC4Explosion;
	}
}
class RA_C4: PlaceableExplosivesBase
{
	override float GetArmDelay()
	{
		return 58.0;
	}
	
	override typename GetExplosiveType()
	{
		return C4Explosion;
	}
}
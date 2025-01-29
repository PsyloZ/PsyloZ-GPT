class BaseBuilding_RampBase: BaseBuilding
{
	static const float MAX_Y_HEIGHT = 1.9;
	static const float MIN_Y_HEIGHT = 0.2;
	
	override float GetSmallRotationStep()
	{
		return 10.0;
	}
	
	override float GetLargeRotationStep()
	{
		return 90.0;
	}
	
	override bool EvaluatePlacementCondition(PlacementMode placement_mode, vector mat[4])
	{
		// Check if we are close enough to the ground, or inside
		vector position = GetPosition();
		float y_position = g_Game.SurfaceY(position[0], position[2]);
		if ((position[1] - y_position) > MAX_Y_HEIGHT || (position[1] - y_position) < MIN_Y_HEIGHT) {
			return false;
		}
				
		return super.EvaluatePlacementCondition(placement_mode, mat);
	}
	
	override vector GetFreePlacementOffset()
	{
		return Vector(0, 0.2, 0);
	}
}
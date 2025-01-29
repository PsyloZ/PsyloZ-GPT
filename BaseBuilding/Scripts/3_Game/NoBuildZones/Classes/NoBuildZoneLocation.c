class NoBuildZoneData
{
	vector Position;
	float Radius;
	
	void NoBuildZoneData(vector position, float radius, string message)
	{
		Position = position;
		Position[1] = g_Game.SurfaceY(Position[0], Position[2]);
		
		Radius = radius;
	}
}
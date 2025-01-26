class SphereCastResult
{
	vector Position, Direction;
	float Distance;
	Object Target;
	int HitComponent, PenetrationLevel;

	void Debug()
	{
		PrintFormat("target: %1, pos: %2, dir: %3, dist: %4, comp: %5", Target, Position, Direction, Distance, HitComponent);
	}
}

class ShapeCast
{
	static void Cube(vector center, vector forward_direction, float radius)
	{
		forward_direction.Normalize();

		float dist = Math.Sqrt(2 * radius * radius);

	}

	// Ive attempted a data structure that organizes our SphereCastResult's by their hit object,
	// but if we hit the world object then the raycast will return null which means we would lose a ton of data
	// i wish the world inherited from object (i think it does but i dont care to find it)
	
	// sends raycasts in all directions on a sphere
	// iterations is the amount of dots to draw on the sphere projection. higher == more accurate and slower
	// penetration count is the amount of objects to penetrate through
	static array<ref SphereCastResult> Sphere(vector center, float radius, Object ignore = null, int iterations = 24, int penetration_count = 3, int layer = ObjIntersectView)
	{
		array<ref SphereCastResult> results = {};

		// ur an idiot lol
		if (iterations <= 0) {
			return results;
		}

#ifdef DIAG
		Debug.DestroyAllShapes();
#endif

		float increment = Math.PI * (3.0 - Math.Sqrt(5.0));
		float offset = 2.0 * radius / ((float)iterations - 1.0);

		for (int i = 0; i < iterations; i++) {
			Object current_ignore = ignore;
			int contacts_remaining = penetration_count + 1;
			// generating points on a sphere at radius
			float z = -radius + i * offset;
			float r = Math.Sqrt(radius * radius - z * z);
			float angle = i * increment;
			float x = r * Math.Cos(angle);
			float y = r * Math.Sin(angle);
			vector e_pos = center + Vector(x, z, y);
			
			RaycastRVParams params = new RaycastRVParams(center, e_pos, ignore);
			params.type = ObjIntersectFire;
			params.flags = CollisionFlags.ALLOBJECTS;
			array<ref RaycastRVResult> raycast_results = {};
			
			DayZPhysics.RaycastRVProxy(params, raycast_results, {});
			for (int j = 0; j < raycast_results.Count(); j++) {
				if (j > penetration_count) {
					continue;
				}
				
				
				SphereCastResult result = new SphereCastResult();
				result.Position = raycast_results[j].pos;
				result.Direction = raycast_results[j].dir;
				result.HitComponent = raycast_results[j].component;
				result.Target = raycast_results[j].obj; // can be null if interacted with world
				result.Distance = vector.Distance(center, raycast_results[j].pos);
				result.PenetrationLevel = j;
				results.Insert(result);

#ifdef DIAG_DEVELOPER
				int sphere_color = COLOR_GREEN;
				if (j == 1) {
					sphere_color = COLOR_YELLOW;
				}
				Debug.DrawSphere(raycast_results[j].pos, 0.05, sphere_color);
				Debug.DrawArrow(center, raycast_results[j].pos, 0.05, COLOR_WHITE);
#endif
			}
			
#ifdef DIAG_DEVELOPER
			// we didnt penetrate anything :(
			Debug.DrawSphere(e_pos, 0.05, COLOR_RED);
#endif
		}

		return results;
	}
}
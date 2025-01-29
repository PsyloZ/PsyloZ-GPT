class NoBuildZone: ScriptedEntity //change to Trigger if wanting to visualize in diag
{
	static ref array<NoBuildZone> All = {};
	
	protected float m_Radius;
	
	void NoBuildZone()
	{
		if (!All) {
			All = {};
		}
		
		All.Insert(this);
		
		RegisterNetSyncVariableFloat("m_Radius");
	}
	
	void ~NoBuildZone()
	{
		if (All) {
			All.RemoveItem(this);
		}
	}

	/*void SetSize(float size)
	{
		SetCollisionCylinder(size, 100); //when uncommenting dont forget to uncomment no_build_zone.SetSize(no_build_zone_data.Radius); in other file
	}*/

	void SetRadius(float radius)
	{
		if (!g_Game.IsServer()) {
			return;
		}
		
		m_Radius = radius;
		SetSynchDirty();
	}
	
	float GetRadius()
	{
		return m_Radius;
	}

	static bool HasPermissionsAtPosition(vector position)
	{
		foreach (NoBuildZone no_build_zone: All) {
			if (vector.Distance(no_build_zone.GetPosition(), position) < no_build_zone.GetRadius()) {
				return false;
			}
		}
		
		return true;
	}
}
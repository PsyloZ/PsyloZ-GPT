class BaseBuilding_LadderHatchBase: BaseBuilding_FloorBase
{
	//change to ladderhatchladder
	BaseBuilding_HatchLadderBase GetDoor()
	{
		array<Object> objects = new array<Object>;
		g_Game.GetObjectsAtPosition3D(GetPosition(), 0.05, objects, NULL);
		foreach (Object object: objects) {
			BaseBuilding_HatchLadderBase door = BaseBuilding_HatchLadderBase.Cast(object);
			if (door) {
				return door;
			}
		}
		
		return null;
	}
	
	override void EEDelete(EntityAI parent)
	{
		if (!g_Game.IsServer()) {
			return;
		}

		super.EEDelete(parent);
		
		BaseBuilding_HatchLadderBase door = GetDoor();
		if (door && !IsBeingUpgraded())
		{
			BaseBuilding_Ladder_Memory m_Ladder = BaseBuilding_Ladder_Memory.Cast(door.GetLadderMemory());
			if (door.IsOpen() && m_Ladder) {
				PlayerBase player = PlayerBase.Cast(m_Ladder.GetPlayer());
				if (m_Ladder && player && player.GetRAIsOnLadder()) {
					return;
				}
			}
			door.Delete();
		}
	}
}
class BaseBuilding_TriangleLadderHatchBase: BaseBuilding_LadderHatchBase
{}
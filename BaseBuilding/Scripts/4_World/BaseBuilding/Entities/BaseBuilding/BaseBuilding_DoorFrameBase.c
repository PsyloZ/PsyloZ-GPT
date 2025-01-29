class BaseBuilding_DoorFrameBase: BaseBuilding_WallBase
{	
	BaseBuilding_SingleDoorBase GetDoor()
	{
		array<Object> objects = new array<Object>;
		g_Game.GetObjectsAtPosition3D(GetPosition(), 0.05, objects, NULL);
		foreach (Object object: objects) {
			BaseBuilding_SingleDoorBase door = BaseBuilding_SingleDoorBase.Cast(object);
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
		
		BaseBuilding_SingleDoorBase door = GetDoor();
		if (door && !IsBeingUpgraded()) {
			door.Delete();
		}

		super.EEDelete(parent);
	}
	
	override float GetSmallRotationStep()
	{
		return 0.0;
	}
	
	override float GetLargeRotationStep()
	{
		return 180.0;
	}
}
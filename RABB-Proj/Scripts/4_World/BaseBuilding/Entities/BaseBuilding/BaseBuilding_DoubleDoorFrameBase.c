class BaseBuilding_DoubleDoorFrameBase: BaseBuilding_WallBase
{
	BaseBuilding_OpenableBase GetDoor()
	{
		array<Object> objects = new array<Object>;
		g_Game.GetObjectsAtPosition3D(GetPosition(), 0.05, objects, NULL);
		foreach (Object object: objects) {
			BaseBuilding_OpenableBase door = BaseBuilding_OpenableBase.Cast(object);
			if (door) {
				return door;
			}
		}
		
		return null;
	}
	
	override void EEDelete(EntityAI parent)
	{		
		BaseBuilding_OpenableBase door = GetDoor();
		if (door && !IsBeingUpgraded() && g_Game.IsServer()) {
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
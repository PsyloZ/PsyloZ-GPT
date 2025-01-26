class BaseBuilding_WindowFrameBase: BaseBuilding_WallBase
{
	BaseBuilding GetWindow()
	{
		array<Object> objects = new array<Object>;
		g_Game.GetObjectsAtPosition3D(GetPosition(), 0.05, objects, NULL);
		foreach (Object object: objects) {
			BaseBuilding_WindowBase window = BaseBuilding_WindowBase.Cast(object);
			if (window) {
				return window;
			}
			BaseBuilding_ShutterBase shutters = BaseBuilding_ShutterBase.Cast(object);
			if (shutters) {
				return shutters;
			}
		}
		
		return null;
	}
	
	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);
		
		BaseBuilding window = GetWindow();
		if (window && !IsBeingUpgraded() && g_Game.IsServer()) {
			window.Delete();
		}
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
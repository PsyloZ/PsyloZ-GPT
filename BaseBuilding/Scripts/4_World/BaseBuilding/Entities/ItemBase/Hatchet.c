modded class Hatchet
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionUpgradeBase);
		AddAction(ActionRotateBase);
		AddAction(ActionRepairBase);
		
		AddAction(ActionDismantleBase);
	}
}
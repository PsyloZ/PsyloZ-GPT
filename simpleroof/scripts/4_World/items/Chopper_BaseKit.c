class Chopper_BaseKit extends ItemBase
{
	override bool IsBasebuildingKit()
	{
		return true;
	}
	
	override bool IsDeployable()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}
}

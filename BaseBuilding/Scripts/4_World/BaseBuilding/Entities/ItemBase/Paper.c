modded class Paper
{
    override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTurnIntoBlueprint);
	}
}

modded class PunchedCard
{
    override void SetActions()
	{
		super.SetActions();
		RemoveAction(ActionTurnIntoBlueprint);
	}
}
modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);
		
		actions.Insert(ActionChangeBlueprint);
		actions.Insert(ActionUpgradeBase);
		actions.Insert(ActionRotateBase);
		actions.Insert(ActionRepairBase);
		actions.Insert(ActionDismantleBase);
		
		actions.Insert(ActionDismantleIntoBox);
		
		actions.Insert(ActionToggleOpen);
		actions.Insert(ActionKnockBaseDoor);
		actions.Insert(ActionDetachFromBase);
		actions.Insert(ActionToggleOpenCodeLock);
		
		actions.Insert(ActionPlaceCurrentBlueprint);
		actions.Insert(ActionPlaceHologramFromHands);

		actions.Insert(ActionTurnIntoBlueprint);
	}
}
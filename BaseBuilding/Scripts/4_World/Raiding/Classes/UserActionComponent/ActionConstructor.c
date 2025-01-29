modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);
		
		actions.Insert(ActionToggleArmExplosive);	
		actions.Insert(ActionArmAndPlaceC4);
	}
}
modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);

		actions.Insert(ActionTerritoryAuthorize);
		actions.Insert(ActionAdminTerritoryAuthorize);
		actions.Insert(ActionTerritoryClearAuthorization);
		actions.Insert(ActionTerritoryDeauthorize);
	}
}
modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);
		
		actions.Insert(ActionCodeLockAuthenticate);
		actions.Insert(ActionCodeLockLock);
		actions.Insert(ActionCodeLockReset);
		actions.Insert(ActionCodeLockSetCode);
		actions.Insert(ActionCodeLockUnlock);
    }
}
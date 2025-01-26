class UpgradeBaseLambda: ReplaceItemWithNewLambdaBase
{
	protected Man m_Player;
	
	void UpgradeBaseLambda(EntityAI old_item, string new_item_type, Man player)
	{
		m_Player = player;
	}
	
	override void CopyOldPropertiesToNew(notnull EntityAI old_item, EntityAI new_item)
	{
		super.CopyOldPropertiesToNew(old_item, new_item);
		BaseBuilding new_base = BaseBuilding.Cast(new_item);
		BaseBuilding old_base = BaseBuilding.Cast(old_item);
		
		old_base.SetIsBeingUpgraded(true);
		if (old_base.GetParent()) {
			old_base.GetParent().AddChild(new_base, -1);
		}
				
		new_base.SetOrientation(old_base.GetOrientation());
		new_base.SetPosition(old_base.GetPosition());
		new_base.SetQuantity(old_base.GetQuantity());

		RA_CodeLock code_lock = RA_CodeLock.Cast(old_base.FindCodeLock());
		if(code_lock) {
			CodeLockState m_CodeLockState;
			m_CodeLockState = code_lock.GetState();
		}

		PlayerBase player = PlayerBase.Cast(m_Player);
		MiscGameplayFunctions.TransferInventory(old_base, new_base, player);
		
		new_item.OnPlacementComplete(player, new_item.GetPosition(), new_item.GetOrientation());
		if(code_lock) {
			code_lock.SetState(m_CodeLockState);
		}
		new_base.SetSynchDirty();
		new_base.UpdateNavmesh();
	}
	
	// Could also be done in network object create
	override void OnSuccess(EntityAI new_item)
	{
		super.OnSuccess(new_item);
		
		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(m_Player);
		rpc.Write(new_item.GetPosition());
		rpc.Write(new_item.GetOrientation());
		rpc.Send(new_item, BaseBuilding.RPC_PLACING_COMPLETE, true);
	}
}
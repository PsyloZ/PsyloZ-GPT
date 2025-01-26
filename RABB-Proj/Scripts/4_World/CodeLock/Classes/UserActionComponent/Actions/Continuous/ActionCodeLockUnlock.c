class ActionCodeLockUnlock: ActionContinuousBase
{
	void ActionCodeLockUnlock()
	{
		m_CallbackClass = ActionCodeLockResetCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask 	= DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_Text = "Unlock";
	}
		
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTCursor();
		m_ConditionItem = new CCINone();
	}
	
	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
	
	override bool HasTarget()
	{
		return true;
	}
	
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!super.ActionCondition(player, target, item)) {
			return false;
		}
		
		RA_CodeLock code_lock = RA_CodeLock.Cast(target.GetObject());
		if (!code_lock || !code_lock.GetHierarchyParent()) {
			return false;
		}
				
		return code_lock.IsAuthorized(player.GetIdentity()) && code_lock.GetState() == CodeLockState.LOCKED;
	}
	
	override void OnFinishProgressServer(ActionData action_data)
	{
		super.OnFinishProgressServer(action_data);
		
		RA_CodeLock code_lock = RA_CodeLock.Cast(action_data.m_Target.GetObject());
		if (!code_lock) {
			return;
		}
		
		code_lock.SetState(CodeLockState.UNLOCKED);
	}
}
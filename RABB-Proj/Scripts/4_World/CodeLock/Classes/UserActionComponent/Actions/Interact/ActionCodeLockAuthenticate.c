class ActionCodeLockAuthenticate: ActionInteractBase
{
	void ActionCodeLockAuthenticate()
	{
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_Text = "Enter Code";
		m_Sound = "BeepSound";
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTCursor();
		m_ConditionItem = new CCINone();
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
		
		return !code_lock.IsAuthorized(player.GetIdentity()) && code_lock.GetState() == CodeLockState.LOCKED;
	}
	
	override void OnExecuteClient(ActionData action_data)
	{
		super.OnExecuteClient(action_data);
		
		RA_CodeLock code_lock = RA_CodeLock.Cast(action_data.m_Target.GetObject());
		if (!code_lock) {
			return;
		}
		
		code_lock.OpenMenu(ScriptCaller.Create(OnCodeComplete));
	}
	
	protected void OnCodeComplete(RA_CodeLock code_lock, string code)
	{
		if (!code_lock) {
			return;
		}
		
		code_lock.TryAuthorize(code, ScriptCaller.Create(OnAuthorizationAttempt));
	}
	
	protected void OnAuthorizationAttempt(RA_CodeLock code_lock, bool success)
	{
		if (!code_lock) {
			return;
		}
		
		if (!success) {
			CodeLockViewMenu code_lock_menu = code_lock.GetMenu();
			if (code_lock_menu) {
				code_lock_menu.OnAuthenticationFailed();
			}
			
			return;
		}
		
		// close if succesful
		code_lock.CloseMenu();
	}
}
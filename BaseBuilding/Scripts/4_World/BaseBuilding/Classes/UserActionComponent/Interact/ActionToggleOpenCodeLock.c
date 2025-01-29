class ActionToggleOpenCodeLock: ActionInteractBase
{
	void ActionToggleOpenCodeLock()
	{
		m_CommandUID 	= DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask 	= DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_Text 			= "#open";
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem 	= new CCINone();
		m_ConditionTarget 	= new CCTObject(UAMaxDistances.DEFAULT);
	}
	
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		RA_CodeLock code_lock = RA_CodeLock.Cast(target.GetObject());
		ItemBase parent_item = ItemBase.Cast(code_lock.GetHierarchyParent());
		
		#ifndef SERVER
		if (!code_lock || !parent_item) {
			return false;
		}

		if (code_lock.GetState() == CodeLockState.LOCKED && !code_lock.IsAuthorized(player.GetIdentity())) {
			return false;
		}
		
		m_Text = Ternary<string>.If(parent_item.IsOpen(), "#close", "#open");
		#endif

		BaseBuilding_OpenableBase door = BaseBuilding_OpenableBase.Cast(code_lock.GetHierarchyParent());
		if (door) {
			m_Sound = Ternary<string>.If(door.IsOpen(), door.GetCloseSounds().GetRandomElement(), door.GetOpenSounds().GetRandomElement());
		}
		return true;
	}
	
	override void OnStartServer(ActionData action_data)
	{
		RA_CodeLock code_lock = RA_CodeLock.Cast(action_data.m_Target.GetObject());
		ItemBase parent_item = ItemBase.Cast(code_lock.GetHierarchyParent());
		if (!code_lock || !parent_item) {
			return;
		}

		PlayerBase player = PlayerBase.Cast(action_data.m_Player);
		if (!player) {
			return;
		}

		if (code_lock.GetState() == CodeLockState.LOCKED && !code_lock.IsAuthorized(player.GetIdentity())) {
			return;
		}
		
		if (!parent_item.IsOpen()) {
			parent_item.Open();
		} else {
			parent_item.Close();
		}
		
		parent_item.PlaySound("BeepSound", 0.3, false);
	}
}

class ActionTerritoryClearAuthorization: ActionInteractBase
{	
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!super.ActionCondition(player, target, item)) {
			return false;
		}
		
		TerritoryHQ hq = TerritoryHQ.Cast(target.GetObject());
		if (!hq) {
			return false;
		}

		RA_CodeLock code_lock = RA_CodeLock.Cast(hq.FindAttachmentBySlotName("CodeLock"));
		if (code_lock && code_lock.IsLocked() && !code_lock.IsAuthorized(player.GetIdentity())) {
			return false;
		}
		
		return hq.IsAuthorized(player);
	}
	
	override void OnEndServer(ActionData action_data)
	{
		super.OnEndServer(action_data);
		
		TerritoryHQ hq = TerritoryHQ.Cast(action_data.m_Target.GetObject());
		if (!hq) {
			return;
		}
		
		hq.ClearAuthorizations();
	}	
	
	override string GetText()
	{
		return "Clear Authorization";
	}
}
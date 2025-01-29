
class ActionTerritoryDeauthorize: ActionInteractBase
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
		
		return (hq.IsAuthorized(player));
	}
	
	override void OnEndServer(ActionData action_data)
	{
		super.OnEndServer(action_data);
		
		TerritoryHQ hq = TerritoryHQ.Cast(action_data.m_Target.GetObject());
		if (!hq) {
			return;
		}
	
		hq.DeauthorizePlayer(action_data.m_Player);
	}
	
	override string GetText()
	{
		return "Deauthorize";
	}
}
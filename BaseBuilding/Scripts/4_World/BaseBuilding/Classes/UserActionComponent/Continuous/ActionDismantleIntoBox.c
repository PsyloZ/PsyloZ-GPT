class ActionDismantleIntoBoxCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DEFAULT_DECONSTRUCT / 6);
	}
};

class ActionDismantleIntoBox: ActionContinuousBase
{
	void ActionDismantleIntoBox()
	{
		m_CallbackClass = ActionDismantleIntoBoxCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined(UAMaxDistances.BASEBUILDING);
	}

	override string GetText()
	{
		return "Dismantle into box";
	}

#ifndef SERVER
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
        ItemBase targetobj = ItemBase.Cast(target.GetObject());
        if (!targetobj || targetobj.GetKit() == string.Empty) {
            return false;
        }

		if (targetobj.FindCodeLock()) {
			return false;
		}

        return true;
	}
#endif
		
	override void OnFinishProgressServer(ActionData action_data) 
	{
		ItemBase item = ItemBase.Cast(action_data.m_Target.GetObject());
		
		if (!item || item.GetKit() == string.Empty) {
			return;
		}

		if (item.FindCodeLock()) {
			return;
		}

		vector pos;
        pos = item.GetPosition();
		if (item.IsInherited(TerritoryHQ)) {
			item.DropAllItemsInCargo();
		}

		ItemBase kit = ItemBase.Cast(g_Game.CreateObjectEx(item.GetKit(), action_data.m_Player.GetPosition(), ECE_FULL));
		if(kit) { //safety measure to ensure we get something
			g_Game.ObjectDelete(item);
		}
		else {
			Print("Kowalski "+item.GetKit()+" at "+action_data.m_Player.GetPosition()+" failed to be placed!!");
		}

		//TurnItemIntoItemLambdaNoPlayer lambda = new TurnItemIntoItemLambdaNoPlayer(item, item.GetKit());
		//lambda.Execute();
	}

    override string GetAdminLogMessage(ActionData action_data)
	{
		return " dismantled " + action_data.m_Target.GetObject().GetDisplayName();
	}
}

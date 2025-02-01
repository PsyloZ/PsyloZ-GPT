class ActionFoldLadderCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( UATimeSpent.DEFAULT_DECONSTRUCT / 4 );
	}
}

class ActionFoldLadder: ActionContinuousBase
{
	void ActionFoldLadder()
	{
		m_CallbackClass = ActionFoldLadderCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}
	
	override void CreateConditionComponents()  
	{	
		
		m_ConditionTarget = new CCTNonRuined(UAMaxDistances.DEFAULT);
		m_ConditionItem = new CCINotPresent;
	}
		
	override string GetText()
	{
		return "#fold";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		Object targetObject = target.GetObject();
		
		if (targetObject.IsKindOf("Chopper_Step_Ladder_2"))
		{
			return true;
		}
		return false;
	}
	
	override void OnFinishProgressServer(ActionData action_data)
	{
		Object targetObject = action_data.m_Target.GetObject();
		if (targetObject.IsInherited(Chopper_Step_Ladder_2))
		{
			Object m_Object;
			if (GetGame().IsServer())
			{
				m_Object = GetGame().CreateObject("Chopper_Step_Ladder_2Kit", targetObject.GetPosition(), false);
				m_Object.SetPosition(targetObject.GetPosition());
				GetGame().ObjectDelete(action_data.m_Target.GetObject());
			}
		}
	}
}

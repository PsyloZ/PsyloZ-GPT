class ActionTurnIntoBlueprintCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(3);
	}
}

class ActionTurnIntoBlueprint: ActionContinuousBase
{
	void ActionTurnIntoBlueprint()
	{
		m_CallbackClass = ActionTurnIntoBlueprintCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_LOW;
		m_Text = "#STR_RA_CRAFT_BLUEPRINT";
	}
	
	override bool HasTarget()
    {
        return false;
    }

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{
		Paper paper = Paper.Cast(action_data.m_MainItem);

		MiscGameplayFunctions.TurnItemIntoItemEx(action_data.m_Player, new TurnItemIntoItemLambda(action_data.m_MainItem, "RA_Blueprint", action_data.m_Player));
	}

	override void OnFinishProgressClient( ActionData action_data )
	{
		SEffectManager.PlaySound("pickUpPaper_SoundSet", action_data.m_MainItem.GetPosition());
	}
}
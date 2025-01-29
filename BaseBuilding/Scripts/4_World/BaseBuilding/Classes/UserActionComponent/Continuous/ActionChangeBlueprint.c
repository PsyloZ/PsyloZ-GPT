class ActionChangeBlueprintCB : ActionContinuousBaseCB
{	
	protected bool m_WasOpened;
	protected int m_InitMovementState;
	protected RA_Blueprint m_Blueprint;
	
	void ~ActionChangeBlueprintCB()
	{
		if (m_Blueprint) {
			m_Blueprint.Close();
		}
	}
	
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(-1);
	}
	
	override void SetActionData(ActionData action_data)
	{
		m_ActionData = action_data;
		m_InitMovementState = m_ActionData.m_Player.m_MovementState.m_iStanceIdx;
	}
	
	override void OnAnimationEvent(int pEventID)
	{
		if (!m_ActionData || !m_ActionData.m_Player || !m_ActionData.m_MainItem) {
			return;
		}
		
		switch (pEventID) {
			case UA_ANIM_EVENT: {
				if (m_ActionData.m_Player.m_MovementState.m_iStanceIdx == m_InitMovementState) {
					m_Blueprint = RA_Blueprint.Cast(m_ActionData.m_MainItem);
					if (!m_Blueprint.IsOpen() && !m_WasOpened) {
						m_Blueprint.Open();
						m_WasOpened = true;
					} else {
						m_Blueprint.Close();
					}
				}
				
				break;
			}
		}
	}
}

class ActionChangeBlueprint: ActionContinuousBase
{
	void ActionChangeBlueprint()
	{
		m_CallbackClass = ActionChangeBlueprintCB;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_VIEWMAP;
		m_Text = "#STR_RA_CHANGE_BLUEPRINT";	
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTNone;
		m_ConditionItem = new CCINonRuined;
	}
	
	override bool HasProneException()
	{
		return true;
	}

	override bool HasProgress()
	{
		return false;
	}

	override bool HasTarget()
	{
		return false;
	}
		
	override void OnEndInput(ActionData action_data)
	{
		super.OnEndInput(action_data);
		RA_Blueprint blueprint = RA_Blueprint.Cast(action_data.m_MainItem);
		blueprint.CloseMenu();
	}
	
	override void OnStart(ActionData action_data)
	{
		super.OnStart(action_data);
		if (!g_Game.IsDedicatedServer()) {
			RA_Blueprint blueprint = RA_Blueprint.Cast(action_data.m_MainItem);
			blueprint.OpenMenu();
		}
	}
		
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{	
		return true;
	}
}
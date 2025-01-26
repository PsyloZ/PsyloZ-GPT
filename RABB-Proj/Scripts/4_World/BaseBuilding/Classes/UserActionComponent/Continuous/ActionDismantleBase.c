class ActionDismantleBaseCB: ActionContinuousBaseCB
{	
	override void CreateActionComponent()
	{
#ifdef DIAG_DEVELOPER
		m_ActionData.m_ActionComponent = new CAContinuousTime(1.0);
#else
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.BASEBUILDING_REPAIR_SLOW);
#endif
	}
}

class ActionDismantleBase: ActionContinuousBase
{	
	void ActionDismantleBase()
	{
		m_CallbackClass = ActionDismantleBaseCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DISASSEMBLE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
		m_Text = "#STR_RA_REMOVE";
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTObject(UAMaxDistances.BASEBUILDING);
	}
		
	override bool HasTarget()
	{
		return true;
	}
	
	#ifndef SERVER
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		BaseBuilding base_building = BaseBuilding.Cast(target.GetObject());
		if (!base_building) {
			return false;
		}

		if (!TerritoryHQ.HasPermissionsAtPosition(player, base_building.GetPosition())) {
			return false;
		}
		
		if (DateTime.Now() - base_building.GetPlaceTime() > RearmedConstants.ROTATION_COOLDOWN && !base_building.CanPermanentlyDismantle()) {
			return false;
		}

		m_Text = string.Format("#STR_RA_REMOVE %1", base_building.GetDisplayName());
		return true;
	}
	#endif
	
	override void OnFinishProgressServer(ActionData action_data)
	{
		BaseBuilding base_building = BaseBuilding.Cast(action_data.m_Target.GetObject());
		if (!base_building) {
			return;
		}

		PlayerBase player = PlayerBase.Cast(action_data.m_Player);
		if (!player) {
			return;
		}

		if (!TerritoryHQ.HasPermissionsAtPosition(player, base_building.GetPosition())) {
			return;
		}

		if (DateTime.Now() - base_building.GetPlaceTime() > RearmedConstants.ROTATION_COOLDOWN && !base_building.CanPermanentlyDismantle()) {
			return;
		}

		base_building.SetHealth01("GlobalHealth", "Health", 0);
	}
}
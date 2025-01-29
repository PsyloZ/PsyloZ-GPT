class ActionRepairBase: ActionContinuousBase
{
	void ActionRepairBase()
	{
		m_CallbackClass = ActionUpgradeBaseCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ASSEMBLE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
		m_Text = "Repair";
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
		
		if (BaseBuilding.CheckBuildCondition(player, base_building, base_building.GetCalculatedRepairCost()) != ConstructFailType.NONE) {
			return false;
		}

		if (base_building.GetSyncedHealth01() == 1) {
			return false;
		}
		
		m_Text = string.Format("Repair %1", base_building.GetDisplayName());
		#ifdef REARMED_SERVER
		return !player.IsInCombat();
		#endif
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

		if (BaseBuilding.CheckBuildCondition(player, base_building, base_building.GetCalculatedRepairCost()) != ConstructFailType.NONE) {
			return;
		}

		if (base_building.GetSyncedHealth01() == 1) {
			return;
		}

		#ifdef REARMED_SERVER
		if (player.IsInCombat()) {
			return;
		}
		#endif

		if (player.RemoveMaterials(base_building.GetCalculatedRepairCost())) {
			base_building.SetHealth("GlobalHealth", "Health", base_building.GetMaxHealth("GlobalHealth","Health"));
			base_building.SetHealthSynchDirty();
		}
	}
}
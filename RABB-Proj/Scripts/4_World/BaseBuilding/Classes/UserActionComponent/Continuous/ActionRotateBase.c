class ActionRotateBaseCB: ActionContinuousBaseCB
{	
	override void CreateActionComponent()
	{
#ifdef DIAG_DEVELOPER
		m_ActionData.m_ActionComponent = new CAContinuousTime(1.0);
#else
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.BASEBUILDING_REPAIR_FAST);
#endif
	}
}

class ActionRotateBase: ActionContinuousBase
{	
	void ActionRotateBase()
	{
		m_CallbackClass = ActionRotateBaseCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ASSEMBLE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
		m_Text = "#STR_RA_ROTATE";
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

		//allows if codelocked items are owned by the player, false if not
		if (base_building.IsCodeLocked(player.GetIdentity())) {
			return false;
		}
		
		if (BaseBuilding.CheckBuildCondition(player, base_building) != ConstructFailType.NONE) {
			return false;
		}
		
		m_Text = string.Format("#STR_RA_ROTATE %1", base_building.GetDisplayName());
		return true;
	}
	#endif
	
	override void OnFinishProgressClient(ActionData action_data)
	{
		BaseBuilding base_building = BaseBuilding.Cast(action_data.m_Target.GetObject());
		
		// purely cosmetic, dont plan on calling on server
		base_building.OnPlacementComplete(action_data.m_Player, base_building.GetPosition(), base_building.GetOrientation());
	}
	
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

		if (base_building.IsCodeLocked(player.GetIdentity())) {
			return;
		}
		
		if (BaseBuilding.CheckBuildCondition(player, base_building) != ConstructFailType.NONE) {
			return;
		}
		
		vector transform[4], ypr_matrix[4];
		base_building.GetTransform(transform);
		
		// rotate building
		Math3D.YawPitchRollMatrix(Vector(base_building.GetLargeRotationStep(), 0, 0), ypr_matrix);
		Math3D.MatrixMultiply3(ypr_matrix, transform, transform);
		
		base_building.SetTransform(transform);
	}
}
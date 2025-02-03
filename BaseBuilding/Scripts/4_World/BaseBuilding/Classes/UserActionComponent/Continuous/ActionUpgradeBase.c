class UpgradeBaseActionData: ActionData
{
	string ReplaceType;
}

class UpgradeBaseActionReciveData: ActionReciveData
{
	string ReplaceType;
}

class ActionUpgradeBaseCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		#ifdef DIAG_DEVELOPER
		m_ActionData.m_ActionComponent = new CAContinuousTime(0);
		#endif
		
		ItemBase tool = ItemBase.Cast(m_ActionData.m_MainItem);
		if (tool && tool.IsInherited(RA_ClawHammer)){
			m_ActionData.m_ActionComponent = new CAContinuousTime(1);
		}

		else if (tool && tool.IsInherited(Hatchet)){
			m_ActionData.m_ActionComponent = new CAContinuousTime(6);
		}

		else if (tool && tool.IsInherited(Hammer)){
			m_ActionData.m_ActionComponent = new CAContinuousTime(3);
		}
		
		else {
			m_ActionData.m_ActionComponent = new CAContinuousTime(6);
		}
	}
}

class ActionUpgradeBase: ActionContinuousBase
{
	void ActionUpgradeBase()
	{
		m_CallbackClass = ActionUpgradeBaseCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ASSEMBLE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
		m_Text = "Upgrade Base";
	}
	
	override ActionData CreateActionData()
	{
		return new UpgradeBaseActionData();
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

	override bool SetupAction(PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = null)
	{
		if (!super.SetupAction(player, target, item, action_data, extra_data)) {
			return false;
		}

		BaseBuilding base_building = BaseBuilding.Cast(action_data.m_Target.GetObject());
		if (!base_building) {
			return false;
		}
		
		BaseBuildingItemEntry upgrade = base_building.GetUpgradeCost();
		if (!upgrade) {
			return false;
		}
		
		if (player.GetIsAdminModeON())
        {
            return true;
        }

		RA_CodeLock code_lock = RA_CodeLock.Cast(base_building.FindAttachmentBySlotName("CodeLock"));
		if (code_lock && code_lock.IsLocked() && !code_lock.IsAuthorized(action_data.m_Player.GetIdentity())) {
			return false;
		}
		
		switch (BaseBuilding.CheckBuildCondition(action_data.m_Player, base_building, upgrade)) {
			case ConstructFailType.TERRITORY: 			
			case ConstructFailType.NOBUILDZONE: 
			case ConstructFailType.MATERIALS:
			case ConstructFailType.HEIGHT:
			case ConstructFailType.LBREFUSED:
			case ConstructFailType.LOCKED: {
				return false;
			}
		}
		
		return true;
	}
	
	override bool ActionConditionContinue(ActionData action_data)
	{
		BaseBuilding base_building = BaseBuilding.Cast(action_data.m_Target.GetObject());
		if (!base_building) {
			return false;
		}
		
		BaseBuildingItemEntry upgrade = base_building.GetUpgradeCost();
		if (!upgrade) {
			return false;
		}

		if (action_data.m_Player.GetIsAdminModeON())
        {
            return true;
        }
		
		RA_CodeLock code_lock = RA_CodeLock.Cast(base_building.FindAttachmentBySlotName("CodeLock"));
		if (code_lock && code_lock.IsLocked() && !code_lock.IsAuthorized(action_data.m_Player.GetIdentity())) {
			return false;
		}
		
		switch (BaseBuilding.CheckBuildCondition(action_data.m_Player, base_building, upgrade)) {
			case ConstructFailType.TERRITORY: 			
			case ConstructFailType.NOBUILDZONE: 
			case ConstructFailType.MATERIALS:
			case ConstructFailType.HEIGHT:
			case ConstructFailType.LBREFUSED:
			case ConstructFailType.LOCKED: {
				return false;
			}
		}
		
		return true;
	}
	
	#ifndef SERVER
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		BaseBuilding base_building = BaseBuilding.Cast(target.GetObject());
		if (!base_building) {
			return false;
		}

		#ifdef AVPPAdminTools
		if (player.GetIsAdminModeON())
        {
			MaterialLevel upgrade_material_level_Admin = g_Game.ConfigGetInt(string.Format("CfgVehicles %1 materialLevel", base_building.GetUpgradeType()));
			if (!upgrade_material_level_Admin || upgrade_material_level_Admin == 0) {
				return false;
			}
			m_Text = string.Format("[ADMIN] Upgrade %1", upgrade_material_level_Admin.GetFormattedName());
            return true;
        }
		#endif

		BaseBuildingItemEntry upgrade = base_building.GetUpgradeCost();
		switch (BaseBuilding.CheckBuildCondition(player, base_building, upgrade)) {
			case ConstructFailType.TERRITORY: {
				m_Text = "#STR_RA_CANNOTUPGRADE_ENEMYTERRITORIES";
				break;
			}
			
			case ConstructFailType.NOBUILDZONE: {
				m_Text = "#STR_RA_CANNOTUPGRADE_NOBUILDZONE";
				break;
			}
			
			case ConstructFailType.MATERIALS: {
				m_Text = "#STR_RA_CANNOTUPGRADE_NOMATERIALS";
				break;
			}
		
			case ConstructFailType.HEIGHT: {
				m_Text = "#STR_RA_CANNOTUPGRADE_HEIGHTLIMIT";
				break;
			}

			case ConstructFailType.LBREFUSED: {
				m_Text = "REFUSED FROM LBMASTER";
				break;
			}
			case ConstructFailType.LOCKED: {
				m_Text = "#STR_RA_CANNOTUPGRADE_LOCKED";
				break;
			}
			
			default: {
				MaterialLevel upgrade_material_level = g_Game.ConfigGetInt(string.Format("CfgVehicles %1 materialLevel", base_building.GetUpgradeType()));
				if (!upgrade_material_level || upgrade_material_level == 0) {
					return false;
				}
				m_Text = string.Format("#STR_RA_UPGRADETO %1", upgrade_material_level.GetFormattedName());
				break;
			}
		}
		
		return true;
	}
	#endif
	
	override void OnFinishProgressServer(ActionData action_data)
	{
		BaseBuilding base_building = BaseBuilding.Cast(action_data.m_Target.GetObject());
		if (!base_building) {
			return;
		}
		
		BaseBuildingItemEntry upgrade = base_building.GetUpgradeCost();
		if (!upgrade) {
			return;
		}

		PlayerBase player = PlayerBase.Cast(action_data.m_Player);
		if (!player) {
			return;
		}

		if (action_data.m_Player.GetIsAdminModeON())
        {
            UpgradeBaseLambda(base_building, base_building.GetUpgradeType(), player).Execute();
            return;
        }


		if (BaseBuilding.CheckBuildCondition(player, base_building, upgrade) != ConstructFailType.NONE) {
			return;
		}
		
		if (player.RemoveMaterials(upgrade)) {
			UpgradeBaseLambda(base_building, base_building.GetUpgradeType(), player).Execute();
		}
	}
}
#ifdef LBmaster_GroupDLCPlotpole
class ActionClaimFlag : ActionSingleUseBase {

	void ActionClaimFlag() {
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
	}

	override void CreateConditionComponents() {
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTCursor;
	}

	override string GetText() {
		return "#lb_action_claim_flag";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
		TerritoryFlag totem = TerritoryFlag.Cast(target.GetObject());
		if (!totem || !LBTerritoryConfig.Get.enablePlotpoleExtension)
			return false;
		return totem.ownerGroupTagHash == 0 && player.GetLBGroup() != null;
	}

	override bool SetupAction(PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL) {
		return super.SetupAction(player, target, item, action_data, extra_data);
	}
	override bool RemoveForceTargetAfterUse() {
		return false;
	}

	override typename GetInputType() {
		return InteractActionInput;
	}

}
#endif
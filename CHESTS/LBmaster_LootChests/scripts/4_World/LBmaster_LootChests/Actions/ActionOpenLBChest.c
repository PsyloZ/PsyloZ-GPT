class ActionOpenLBChest : ActionInteractBase {

	void ActionOpenLBChest() {
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_Text = "#open";
	}

	override void CreateConditionComponents() {
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNonRuined;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
		if (target) {
			LB_LC_Base targetItem = LB_LC_Base.Cast(target.GetObject());
			return targetItem && !targetItem.IsOpen() && !targetItem.RequiresKeyToOpen();
		}
		return false;
	}
}
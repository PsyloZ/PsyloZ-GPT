class ActionOpenLBChestKeyCB : ActionContinuousBaseCB {
	override void CreateActionComponent() {
		ActionOpenLBChestKey parent = ActionOpenLBChestKey.Cast(m_ActionData.m_Action);
		m_ActionData.m_ActionComponent = new CAContinuousTime(parent.openTime);
	}
}

class ActionOpenLBChestKey: ActionContinuousBase {
	float openTime = 1.0;

	void ActionOpenLBChestKey() {
		m_CallbackClass = ActionOpenLBChestKeyCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
        m_FullBody = true;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;

		m_Text = "#open";
	}

	override void CreateConditionComponents() {
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
		if (target && !item.IsRuined()) {
			LB_LC_Base targetItem = LB_LC_Base.Cast(target.GetObject());
			if (targetItem && !targetItem.IsOpen() && targetItem.RequiresKeyToOpen() && targetItem.chestInfo) {
				string keyItemname = item.GetType();
				foreach (LB_LC_ChestKey keyConfig : targetItem.chestInfo.keys) {
					if (keyConfig.itemname == keyItemname) {
						openTime = keyConfig.time;
						return true;
					}
				}
			}
		}
		return false;
	}
}
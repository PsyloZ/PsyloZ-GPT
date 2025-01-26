class ActionToggleArmExplosive: ActionInteractBase
{
	void ActionToggleArmExplosive()
	{
		m_Text = "Arm Explosive";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!super.ActionCondition(player, target, item)) {
			return false;
		}

		PlaceableExplosivesBase explosive = PlaceableExplosivesBase.Cast(target.GetObject());
		if (!explosive) {
			return false;
		}

		return !explosive.IsArmed();
	}

	override void OnExecuteServer(ActionData action_data)
	{
		super.OnExecuteServer(action_data);

		PlaceableExplosivesBase explosive = PlaceableExplosivesBase.Cast(action_data.m_Target.GetObject());
		if (!explosive) {
			return;
		}

		explosive.SetArmState(!explosive.IsArmed());
	}
}
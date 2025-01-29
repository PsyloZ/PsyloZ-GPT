class ActionArmAndPlaceC4: ActionPlaceObject
{
	void ActionArmAndPlaceC4()
	{
		m_Text = "Place and Arm";
	}

	override string GetText()
	{
		return "Place and Arm";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{	
		PlaceableExplosivesBase C4 = PlaceableExplosivesBase.Cast(item);
		if (!C4 || C4.IsArmed()) {
			return false;
		}

		return true;
	}

    override void OnEndServer(ActionData action_data)
	{
		super.OnEndServer(action_data);

		PlaceableExplosivesBase C4 = PlaceableExplosivesBase.Cast(action_data.m_MainItem);
		if (!C4) {
			return;
		}
        C4.SetArmState(true);
	}
}
modded class ItemActionsWidget
{
	protected override void SetItemHealth(int health, string itemWidget, string healthWidget, bool enabled)
	{
		ProgressBarWidget progressbar = ProgressBarWidget.Cast(m_Root.FindAnyWidget("ia_progress"));
		
		ItemBase target_item = ItemBase.Cast(m_EntityInHands);
		if (!enabled || !target_item || target_item.GetSyncedHealth01() == -1) {
			progressbar.Show(false);
			return;
		}
		
		progressbar.Show(true);
		float synched_health = target_item.GetSyncedHealth01() * 100;
		progressbar.SetCurrent(synched_health);
		progressbar.SetColor(HSVtoARGB(synched_health, 100 - synched_health, 100, 255));
	}

    protected override void SetActionWidget(ActionBase action, string descText, string actionWidget, string descWidget)
	{
		Widget widget = m_Root.FindAnyWidget(actionWidget);

		ShowXboxHidePCIcons(actionWidget, false);
		
		ImageWidget image_widget = ImageWidget.Cast(m_Root.FindAnyWidget(actionWidget + "_btn_icon"));
		if (action && image_widget) {
			if (action.IsIconDisabled()) {
				image_widget.LoadImageFile(0, "set:dayz_gui image:icon_x");				
			} else {
				image_widget.LoadImageFile(0, "set:dayz_gui image:left_mouse");	
			}
			
			image_widget.SetImage(0);
		}
		
		if (action && (!action.HasTarget() || m_Player.GetCommand_Vehicle())) {
			TextWidget actionName;
			Class.CastTo(actionName, widget.FindAnyWidget(descWidget));

			if (action.GetInput().GetInputType() == ActionInputType.AIT_CONTINUOUS) {
				descText = descText + " " + "#action_target_cursor_hold";
				actionName.SetText(descText);
			} else {
				actionName.SetText(descText);
			}

			widget.Show(true);
		} else {
			widget.Show(false);
		}
	}
}
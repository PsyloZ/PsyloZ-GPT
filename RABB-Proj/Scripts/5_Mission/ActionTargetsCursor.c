modded class ActionTargetsCursor
{			
	protected override void SetItemHealth(int health, string itemWidget, string healthWidget, bool enabled)
	{
		// am i following bohemias standard with my bad modding? NO
		// do i give a fuck?... if i did would i have done it?
		//ProgressBarWidget pbar_widget = ProgressBarWidget.Cast(m_Root.FindAnyWidget("item_health_pb"));		
		//Widget pbar_wrapper = m_Root.FindAnyWidget("item_health_frame");
		
		//pbar_widget.SetColor(HSVtoARGB(synched_health, 100 - synched_health, 100, 255));
	}

	protected override void SetItemQuantity(int type, float current, int min, int max, string itemWidget, string quantityPBWidget, string quantityTextWidget, bool enabled)
	{
		TextWidget text_quantity = TextWidget.Cast(m_Root.FindAnyWidget("item_quantity_text"));
		
		EntityAI target_object = EntityAI.Cast(m_DisplayInteractTarget);
		if (m_Target) {
			target_object = EntityAI.Cast(m_Target.GetObject());
		}
		
		if (m_QuantityEnabled && target_object) {
			string quantity = QuantityConversions.GetItemQuantityText(target_object);
			if (quantity != string.Empty) {
				text_quantity.Show(true);
				text_quantity.SetText(quantity);
			} else {
				text_quantity.Show(false);
			}
		}
	}
	
	protected override void SetActionWidget(ActionBase action, string descText, string actionWidget, string descWidget)
	{
		Widget widget = m_Root.FindAnyWidget(actionWidget);
		
		ProgressBarWidget pbar = ProgressBarWidget.Cast(m_Root.FindAnyWidget("progress"));
		Object target_object = m_DisplayInteractTarget;
		if (m_Target) {
			target_object = m_Target.GetObject();
		}
				
		ItemBase target_item = ItemBase.Cast(target_object);
		if (target_item && target_item.GetSyncedHealth01() > -1) {
			pbar.Show(true);
			float synched_health = target_item.GetSyncedHealth01() * 100;
			pbar.SetCurrent(synched_health);
			pbar.SetColor(HSVtoARGB(synched_health, 100 - synched_health, 100, 255));
		} else {
			pbar.Show(false);
		}
		
		if (!action || !action.HasTarget() || m_AM.GetActionState() > 1)
		{
			widget.Show(false);			
		}
		else
		{
			ImageWidget image_widget = ImageWidget.Cast(m_Root.FindAnyWidget(actionWidget + "_btn_icon"));
			if (action && image_widget) {
				if (action.IsIconDisabled()) {
					image_widget.LoadImageFile(0, "set:dayz_gui image:icon_x");
				} else {
					image_widget.LoadImageFile(0, "set:dayz_gui image:left_mouse");	
				}
				
				image_widget.SetImage(0);
			}


			TextWidget actionName;
			Class.CastTo(actionName, widget.FindAnyWidget(descWidget));

			if (action.GetInput().GetInputType() == ActionInputType.AIT_CONTINUOUS)
			{
				descText = descText + " " + "#action_target_cursor_hold";
				actionName.SetText(descText);
			}
			else
			{
				actionName.SetText(descText);
			}
				
			widget.Show(true);
			
			int x, y;
			actionName.GetTextSize(x, y);
			if (x > m_MaxWidthChild);
				m_MaxWidthChild = x;
		}
	}
	
	protected override void SetInteractActionIcon(string actionWidget, string actionIconFrameWidget, string actionIconWidget, string actionIconTextWidget)
	{
		Widget widget;
		ImageWidget iconWidget;
		TextWidget textWidget;
		
		widget = m_Root.FindAnyWidget(actionWidget);
		Class.CastTo(iconWidget, widget.FindAnyWidget(actionIconWidget));
		Class.CastTo(textWidget, widget.FindAnyWidget(actionIconTextWidget));
		
		g_Game.GetBacklit().HintShow(m_UseActionWrapper.InputP());
		
		// uses text in floating widget
		if (m_Interact && m_Interact.IsIconDisabled()) {
			iconWidget.Show(true);
			iconWidget.LoadImageFile(0, "set:dayz_gui image:icon_x");
			textWidget.Show(false);
		} else {
			iconWidget.Show(false);
			iconWidget.LoadImageFile(0, "set:dayz_gui image:key_icon");
			textWidget.SetText(InputUtils.GetButtonNameFromInput("UAAction", EInputDeviceType.MOUSE_AND_KEYBOARD));
			textWidget.Show(true);
		}
		
		iconWidget.SetImage(0);
	}
		
	protected override void CheckRefresherFlagVisibility(Object object)
	{
		Widget w = m_Root.FindAnyWidget("item_flag_icon");
		if (!w) {
			return;
		}
		
		w.Show(false);
		
		while (object.GetParent()) {
			object = Object.Cast(object.GetParent());
		}
		
		ItemBase itembase = ItemBase.Cast(object);
		if (!itembase || itembase.GetCostToUpkeep() <= 0) {
			return;
		}
		
		TerritoryHQ hq = itembase.GetCurrentHQ();
		w.SetColor(Ternary<int>.If(hq && hq.IsAuthorized(g_Game.GetPlayer()), COLOR_WHITE, 0xFFFF4A4A));	
		w.Show(true);
	}
}
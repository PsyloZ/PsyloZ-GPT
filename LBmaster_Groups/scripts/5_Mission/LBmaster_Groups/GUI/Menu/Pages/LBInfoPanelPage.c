class LBInfoPanelPage : LBGroupPage {

	ScrollWidget scrollPanel;
	int currentHeight = 5;
	int defaultTextSize = 25;
	int defaultLineSpacing = 2;

	override bool InitPage(LBGroupUI parentUI) {
		return super.InitPage(parentUI, 6, 0, LBRulesConfig.Get.buttonText, LBRulesConfig.Get.fullSize, LBRulesConfig.Get.priority);
	}

	override void InitMainWidget() {
		scrollPanel = ScrollWidget.Cast(rootWidget.FindAnyWidget("scrollPanel"));
		Widget content = scrollPanel.FindAnyWidget("content");
		LBWidgetUtils.CreateLines(scrollPanel, content, LBRulesConfig.Get.lines);
	}

	override bool OnChange(Widget w) {
		LBWidgetUtils.UpdateClipChildren(scrollPanel);
		return super.OnChange(w);
	}
	
	override bool CanDisplayButton() {
		return LBRulesConfig.Get.enabled;
	}

}
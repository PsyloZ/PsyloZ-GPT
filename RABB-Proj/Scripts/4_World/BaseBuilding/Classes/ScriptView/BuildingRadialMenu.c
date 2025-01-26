class BuildingRadialMenu: RadialMenuView
{	
	protected RA_Blueprint m_Blueprint;
	
	void BuildingRadialMenu(RA_Blueprint blueprint)
	{
		m_Blueprint = blueprint;
	}
	
	override void RegisterItems(array<ref RadialMenuItemView> items)
	{
		super.RegisterItems(items);
		
		foreach (string base_building_item: RA_Blueprint.BASE_BUILDING_ITEMS) {			
			string display_name = g_Game.ConfigGetTextOut("CfgVehicles " + BaseBuilding.GetUpgradeType(base_building_item) + " displayName");
			string icon = g_Game.ConfigGetTextOut("CfgVehicles " + base_building_item + " displayIcon");
			Param aids = new Param1<string>(base_building_item);
			items.Insert(new RadialMenuItemView(this, display_name, icon, aids));
		}
	}
	
	override void OnItemClicked(RadialMenuItemView item_view)
	{
		Param1<string> casted_data = Param1<string>.Cast(item_view.GetData());
		if (!casted_data) {
			return;
		}
		
		if (!m_Blueprint) {
			Error("No blueprint found!");
			return;	
		}
		#ifndef SERVER
		m_Blueprint.StartPlacing(new BaseBuildingHologram(casted_data.param1));
		#endif
	}
}
class RadialMenuView: ScriptViewMenu
{		
	protected int m_OpenTime;
	
	Widget RadialDelimiterContainer;
	Widget RadialItemCardContainer;
	Widget RadialSelector;
	ImageWidget SelectorImage;
	ImageWidget SelectorPointer;
	//ImageWidget CurrentSelectorImage;
	
	// probably temporary, use ScriptViewTemplate for release
	protected RadialMenuViewController m_TemplateController;
	
	// hovered elements
	protected RadialMenuItemView m_HoveredRadialMenuItemView;
		
	void RadialMenuView()
	{
		m_TemplateController = RadialMenuViewController.Cast(GetController());
				
		array<ref RadialMenuItemView> radial_menu_items = {};
		RegisterItems(radial_menu_items);
		
		float w, h;
		RadialItemCardContainer.GetScreenSize(w, h);
				
		for (int i = 0; i < radial_menu_items.Count(); i++) {
			Widget delimiter = g_Game.GetWorkspace().CreateWidgets("RA_BaseBuilding\\GUI\\layouts\\radial_menu\\day_z_radial_delimiter.layout", RadialDelimiterContainer);
			
			float rotation = (360 / radial_menu_items.Count()) * i;
			delimiter.SetRotation(0, 0, rotation);
						
			// just storing here, these items are actually not even parented on an object
			m_TemplateController.MenuItems.Insert(radial_menu_items[i]);
			
			rotation -= 90; // our unit circle is offset by 90	
			rotation += 180 / radial_menu_items.Count(); // then offset it by the size of each divider
			rotation *= Math.DEG2RAD; // deg -> radians
			
			float item_x = Math.Cos(rotation) * h * 0.325;
			float item_y = Math.Sin(rotation) * h * 0.325;
			
			radial_menu_items[i].GetLayoutRoot().SetPos(item_x, item_y);
		}
		
		float size = 1 / m_TemplateController.MenuItems.Count();
		//CurrentSelectorImage.SetMaskProgress(size * 2);
						
		// for animations
		m_OpenTime = g_Game.GetTime();
	}
	
	override void Update(float dt)
	{
		super.Update(dt);
				
		if (GetUApi().GetInputByID(UAUIBack).LocalPress()) {
			Close();
			return;
		}
						
		int time_since_open = g_Game.GetTime() - m_OpenTime;
		int count = m_TemplateController.MenuItems.Count();
		if (count == 0) {
			return;
		}
		
		float wedge_size = 360 / count;
		
		float b = 1.0;
		if (time_since_open < 250) {
			b = (time_since_open / 250);
		}
		
		int x, y;
		GetMousePos(x, y);
		
		int screen_x, screen_y;
		GetScreenSize(screen_x, screen_y);
		y -= screen_y / 2;
		x -= screen_x / 2;
		
		float angle = Math.Atan2(y, x);
		
		angle *= Math.RAD2DEG;
		angle += 90;
		
		if (angle < 0) {
			angle += 360;
		}
		
		RadialSelector.SetRotation(0, 0, angle);
		
		// assign current wedgie
		int current_wedge = Math.Floor(angle / wedge_size);
		m_HoveredRadialMenuItemView = m_TemplateController.MenuItems[current_wedge];
		if (!m_HoveredRadialMenuItemView) {
			return;
		}
		
		// update center name
		m_TemplateController.MenuCategoryName = m_HoveredRadialMenuItemView.GetName();
		m_TemplateController.NotifyPropertyChanged("MenuCategoryName");
		
		// handle the yellow outline of the current Selection
		//CurrentSelectorImage.SetRotation(0, 0, current_wedge * (360 / m_TemplateController.MenuItems.Count()) - 180);
		
		// algo that gets if cursor is in the middle
		// 100 is the radius to check
		float xx = x / 100;	
		float yy = y / 100;
		float zz = Math.Sqrt(yy * yy + xx * xx);		
		zz -= 1;
		
		zz = Math.Min(zz, 0.6); // just so theres some fade
		
		SelectorImage.SetMaskProgress(zz * b);
	}
		
	// override this on your inherited items
	void RegisterItems(array<ref RadialMenuItemView> items) 
	{
	}
	
	void OnItemClicked(RadialMenuItemView item_view) 
	{
		if (m_HoveredRadialMenuItemView) {
			m_HoveredRadialMenuItemView.Execute();
		}
	}
	
	void OnItemHover(RadialMenuItemView item_view)
	{
		m_HoveredRadialMenuItemView = item_view;
	}
	
	void OnItemExit(RadialMenuItemView item_view)
	{
		m_HoveredRadialMenuItemView = null;
	}
	
	int GetItemCount()
	{
		return m_TemplateController.MenuItems.Count();
	}
	
	override void Close()
	{
		if (m_HoveredRadialMenuItemView) {
			m_HoveredRadialMenuItemView.Execute();
		}
		
		super.Close();
	}
	
	override array<string> GetInputExcludes()
	{
		return { "aiming", "movement" };
	}
	
	override array<int> GetInputRestrictions()
	{
		return { UATempRaiseWeapon };
	}
	
	override typename GetControllerType()
	{
		return RadialMenuViewController;
	}
	
	override string GetLayoutFile()
	{
		return "RA_BaseBuilding\\GUI\\layouts\\radial_menu\\day_z_radial.layout";
	}
}
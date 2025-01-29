class RadialMenuItemView: ScriptView
{
	RichTextWidget GestureNameText;
	ImageWidget RadialIcon;
	
	protected string m_Name, m_Icon;
	protected RadialMenuView m_Parent;
	protected ref Param m_Data;
		
	void RadialMenuItemView(RadialMenuView parent, string name, string icon = "set:dayz_gui image:Close", Param data = null)
	{
		m_Parent = parent;
		m_Name = name;
		m_Icon = icon;
		m_Data = data;
		
		GestureNameText.SetText(m_Name);
		RadialIcon.LoadImageFile(0, m_Icon);
		RadialIcon.SetImage(0);
	}
	
	void Execute()
	{
		m_Parent.OnItemClicked(this);
	}
	
	string GetName()
	{
		return m_Name;
	}
	
	string GetIcon()
	{
		return m_Icon;
	}
	
	Param GetData()
	{
		return m_Data;
	}
		
	override string GetLayoutFile()
	{
		return "RA_BaseBuilding\\GUI\\layouts\\radial_menu\\day_z_radial_item_card.layout";
	}
}
class RadialMenuViewController: ViewController
{
	string MenuCategoryName;
	
	ref ObservableCollection<ref RadialMenuItemView> MenuItems = new ObservableCollection<ref RadialMenuItemView>(this);
}
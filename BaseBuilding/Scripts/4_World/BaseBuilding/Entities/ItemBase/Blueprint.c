class RA_Blueprint: ItemBase
{
	protected bool m_Open;
	
	//@ Client only
	protected ref BuildingRadialMenu m_BuildingRadialMenu;
	protected ref BaseBuildingHologram m_BaseBuildingHologram;
	
	static const ref array<string> BASE_BUILDING_ITEMS = {
		"BaseBuilding_HologramFoundation",
		"BaseBuilding_HologramTriangleFoundation",
		"BaseBuilding_HologramFloor",
		"BaseBuilding_HologramTriangleFloor",
		"BaseBuilding_HologramWall",
		"BaseBuilding_HologramHalfWall",
		"BaseBuilding_HologramDoorFrame",
		"BaseBuilding_HologramDoubleDoorFrame",
		"BaseBuilding_HologramWindowFrame",
		"BaseBuilding_HologramSingleDoor",
		"BaseBuilding_HologramDoubleDoor",
		"BaseBuilding_HologramGarageDoor",
		"BaseBuilding_HologramWindow",
		"BaseBuilding_HologramEmbrasure",
		"BaseBuilding_HologramShutters",
		"BaseBuilding_HologramStairs",
		"BaseBuilding_HologramStairsStraight",
		"BaseBuilding_HologramCompoundGate",
		"BaseBuilding_HologramCompoundWall",
		"BaseBuilding_HologramStepLadder",
		"BaseBuilding_HologramRamp",
		"BaseBuilding_HologramRoof",
		//"BaseBuilding_HologramTriangleRoof", nightmare
		"BaseBuilding_HologramRoofWall_Left",
		"BaseBuilding_HologramRoofWall_Right",		
		"BaseBuilding_HologramLadderHatch", 
		"BaseBuilding_HologramTriangleLadderHatch"
		"BaseBuilding_HologramHatchLadder"
	};
	
	void RA_Blueprint()
	{
#ifdef DIAG_DEVELOPER
#ifndef NO_GUI
		//g_Game.GetUpdateQueue(CALL_CATEGORY_GUI).Insert(OnDebugFrame);
#endif
#endif
	}

	void ~RA_Blueprint()
	{
		delete m_BuildingRadialMenu;
		delete m_BaseBuildingHologram;
	}
	
/*#ifdef DIAG_DEVELOPER
	void OnDebugFrame(float dt)
	{
		if (g_Game.GetPlayer().GetHumanInventory().GetEntityInHands() != this) {
			return;
		}
		
		vector pos, dir;
		int comp;		
		set<Object> results();
		DayZPhysics.RaycastRV(g_Game.GetCurrentCameraPosition(), g_Game.GetCurrentCameraPosition() + g_Game.GetCurrentCameraDirection() * 5, pos, dir, comp, results, null, g_Game.GetPlayer());
		if (results.Count() == 0) {
			return;
		}
		
		BaseBuilding result = BaseBuilding.Cast(results[0]);
		if (!result) {
			return;
		}
		
		Debug.DrawSphere(result.GetPosition(), 0.25, COLOR_RED, ShapeFlags.ONCE | ShapeFlags.TRANSP);
		
		array<BaseBuilding> structure = DepthFirstSearch.Execute(result);
		BaseBuilding curr = result;
		foreach (BaseBuilding structure_item: structure) {
			if (!structure_item || !curr) {
				continue;
			}
			
			Debug.DrawSphere(structure_item.GetPosition(), 0.25, COLOR_WHITE, ShapeFlags.ONCE | ShapeFlags.TRANSP);
			Debug.DrawArrow(curr.GetPosition(), structure_item.GetPosition(), 0.5, COLOR_WHITE, ShapeFlags.ONCE);
			curr = structure_item;
		}
	}
#endif*/
		
	//@ Client only!
	void StartPlacing(BaseBuildingHologram base_building_hologram)
	{
		m_BaseBuildingHologram = base_building_hologram;
	}
	
	void CancelPlacing()
	{
		delete m_BaseBuildingHologram;
	}
	
	BaseBuildingHologram GetPlacing()
	{
		return m_BaseBuildingHologram;
	}
	
	bool IsPlacing()
	{
		return m_BaseBuildingHologram != null;
	}
	
	override void Open()
	{
		m_Open = true;
		
		ShowSelection("map_opened");
		HideSelection("map_closed");
	}
	
	override void Close()
	{
		m_Open = false;
		
		HideSelection("map_opened");
		ShowSelection("map_closed");
	}
	
	override bool IsOpen()
	{
		return m_Open;
	}
	
	void OpenMenu()
	{
		#ifndef SERVER
		m_BuildingRadialMenu = new BuildingRadialMenu(this);
		#endif
	}
	
	void CloseMenu()
	{
		#ifndef SERVER
		if (!m_BuildingRadialMenu) {
			return;
		}
		
		m_BuildingRadialMenu.Close();
		#endif
	}
		
	override void OnRaiseChanged(bool state)
	{
		super.OnRaiseChanged(state);
		
		CancelPlacing();
	}
	
	override void EEItemLocationChanged(notnull InventoryLocation oldLoc, notnull InventoryLocation newLoc)
	{
		super.EEItemLocationChanged(oldLoc, newLoc);
		
		// Cancel placing
		if (!g_Game.IsDedicatedServer()) {
			CancelPlacing();
		}
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionChangeBlueprint);
		AddAction(ActionPlaceCurrentBlueprint);
	}
}
[DayZGame.RegisterLBAdminPage("LBChestPositionsAdminPage", "LBmaster_LootChests/logo/logo.paa", "Chest Positions", "lootchest.change.positionpools")]
class LBChestPositionsAdminPage : LBAdmin_Menu_Page {

	TextWidget txt_info;
	MultilineEditBoxWidget edit_comment;
	XComboBoxWidget combo_list, combo_previewItem;
	MapWidget mapwidget;
	EditBoxWidget edit_name;
	TextListboxWidget list_positions;
	ButtonWidget btn_add, btn_del, btn_add_pos, btn_del_pos, btn_add_all;
	
	static ref array<Object> spawnedPlaceholders = new array<Object>();
	static string selectedChest = "LB_LC_Placeholder";
	static ref TStringArray availableChests = new TStringArray();
	static bool closedWithPlacement = false;
	static int lastSelectedPool = 0;
	static string placeMultipleItemname = "";
	bool skipMapMove = false;

	override array<string> GetEditedConfigs() {
		return {"LB_LC_PoolConfig"};
	}

	override void OnShow() {
		super.OnShow();
		if (lastSelectedPool != -1)
			combo_list.SetCurrentItem(lastSelectedPool);
		linked.LoadLinkedVars();
		DeleteChestItems();
		closedWithPlacement = false;
	}
	
	override void OnHide() {
		super.OnHide();
		lastSelectedPool = combo_list.GetCurrentItem();
		if (!closedWithPlacement)
			DeleteChestItems();
		else
			SpawnPlaceholders();
	}

	override void RegisterAllLinkedVars() {
		linked.RegisterLinkedList("GetConfig().positionPools", combo_list, btn_add, btn_del).SetListManager(new LBListManager<LB_LC_PositionPool>()).SetChangeTrigger("UpdateMap()");
		linked.RegisterLinkedVar("GetConfig().positionPools[combo_list].name", edit_name, true);
		linked.RegisterLinkedVar("GetConfig().positionPools[combo_list].comment", edit_comment);
		linked.RegisterLinkedList("GetConfig().positionPools[combo_list].positions", list_positions, null, btn_del_pos).SetListManager(new LBListManager<LB_LC_ChestSpawnPos>());
		combo_previewItem.ClearAll();
		availableChests.Clear();
		combo_previewItem.AddItem("LB_LC_Placeholder");
		availableChests.Insert("LB_LC_Placeholder");
		TStringSet available = LBInherit.Get().GetEntry("LB_LC_Base").GetChildren(false, true, false, 2);
		int index = 0;
		combo_previewItem.SetCurrentItem(0);
		foreach (string chest : available) {
			++index;
			combo_previewItem.AddItem(chest);
			availableChests.Insert(chest);
			if (chest == selectedChest)
				combo_previewItem.SetCurrentItem(index);
		}
		UpdateMap();
	}
	
	LB_LC_PositionPool GetSelectedPool() {
		int index = combo_list.GetCurrentItem();
		if (index < 0 || index >= GetConfig().positionPools.Count())
			return null;
		return GetConfig().positionPools.Get(index);
	}
	
	LB_LC_ChestSpawnPos GetSelectedSpawnPos() {
		LB_LC_PositionPool pool = GetSelectedPool();
		if (!pool)
			return null;
		int index = list_positions.GetSelectedRow();
		if (index < 0 || index >= pool.positions.Count())
			return null;
		return pool.positions.Get(index);
	}

	LB_LC_PoolConfig_ GetConfig() {
		return LB_LC_PoolConfig.Get;
	}
	
	override bool OnClick(Widget w, int x, int y, int button) {
		if (super.OnClick(w, x, y, button))
			return true;
		if (w == btn_add_pos) {
			placeMultipleItemname = "";
			HideMyMenu();
			return true;
		} else if (w == combo_previewItem) {
			selectedChest = availableChests.Get(combo_previewItem.GetCurrentItem());
			return true;
		} else if (w == mapwidget) {
			vector worldPos = mapwidget.ScreenToMap(Vector(x, y, 0));
			LB_LC_PositionPool pool = GetSelectedPool();
			int bestIndex = -1;
			float bestDist = 0;
			int index = 0;
			foreach (LB_LC_ChestSpawnPos pos : pool.positions) {
				float dist = vector.DistanceSq(pos.pos, worldPos);
				if (dist < 10000 && (bestIndex == -1 || dist < bestDist)) {
					bestIndex = index;
					bestDist = dist;
				}
				++index;
			}
			if (bestIndex >= 0) {
				skipMapMove = true;
				list_positions.SelectRow(bestIndex);
			}
		} else if (w == btn_add_all) {
			LBMenuManager.Get().OpenMenu("LBItemSelectorDialog", new LBMenuDataItemSelector(ScriptCaller.Create(OnPlaceMultipleStart), false, "House"), false, LBMenuManager.Get().GetOpenLBMenu());
			return true;
		}
		return false;
	}
	
	void HideMyMenu() {
		closedWithPlacement = true;
		g_Game.GetUIManager().HideScriptedMenu(g_Game.GetUIManager().GetMenu());
		StartPlacement();
	}
	
	void OnPlaceMultipleStart(string itemname) {
		placeMultipleItemname = itemname;
		LootChestRPCHandlerClient.positionList = null;
		g_Game.RPCSingleParam(null, LB_LC_RPCs.REQUEST_POSITIONS, new Param1<string>(placeMultipleItemname), true);
		g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(HideMyMenu, 100, false);
	}
	
	void DeleteChestItems() {
		foreach (Object obj : spawnedPlaceholders) {
			if (obj)
				obj.Delete();
		}
		spawnedPlaceholders.Clear();
	}
	
	void SpawnPlaceholder(LB_LC_ChestSpawnPos pos) {
		Object obj = g_Game.CreateObject(selectedChest, pos.pos, true);
		if (!obj)
			return;
		vector positionOffset = "0 0 0", dirOff = "0 0 0";
		if (g_Game.ConfigIsExisting("CfgVehicles " + selectedChest + " lbSpawnOffsetPos"))
			positionOffset = g_Game.ConfigGetVector("CfgVehicles " + selectedChest + " lbSpawnOffsetPos");
		if (g_Game.ConfigIsExisting("CfgVehicles " + selectedChest + " lbSpawnOffsetDir"))
			dirOff = g_Game.ConfigGetVector("CfgVehicles " + selectedChest + " lbSpawnOffsetDir");
		obj.SetOrientation(pos.dir + dirOff);
		
		vector mat[3];
		Math3D.YawPitchRollMatrix(pos.dir + dirOff, mat);
		vector posOff = positionOffset.Multiply3(mat);
		obj.SetPosition(pos.pos + posOff);
		spawnedPlaceholders.Insert(obj);
	}
	
	void SpawnPlaceholders() {
		DeleteChestItems();
		LB_LC_PositionPool pool = GetSelectedPool();
		if (!pool)
			return;
		foreach (LB_LC_ChestSpawnPos pos : pool.positions) {
			SpawnPlaceholder(pos);
		}
	}
	
	void UpdateMap() {
		mapwidget.ClearUserMarks();
		LB_LC_PositionPool pool = GetSelectedPool();
		if (!pool) {
			txt_info.SetText("No position pool selected");
			return;
		}
		int selectedIndex = list_positions.GetSelectedRow();
		int index = 0;
		txt_info.SetText("Positions: " + pool.positions.Count());
		foreach (LB_LC_ChestSpawnPos pos : pool.positions) {
			int color = ARGB(255, 255, 255, 255);
			if (index == selectedIndex)
				color = ARGB(255, 0, 255, 0);
			++index;
			mapwidget.AddUserMark(pos.pos, "", color, "DZ\\gear\\navigation\\data\\map_tree_ca.paa");
		}
	}
	
	void OnAddPosition(string itemname, vector pos, vector orient) {
		LBLogger.Info("Adding position for " + itemname + " at " + pos + " (" + orient + ")", "LootChests");
		Object multipleObject = null;
		if (placeMultipleItemname != "") {
			vector start = pos + "0 10 0";
			vector end = pos - "0 10 0";
			set<Object> hitObjects = new set<Object>();
			vector contactPos, contactDir;
			int component;
			DayZPhysics.RaycastRV(start, end, contactPos, contactDir, component, hitObjects, null, g_Game.GetPlayer(), false, false, ObjIntersectGeom, 0.0, CollisionFlags.ALLOBJECTS);
			foreach (Object hit : hitObjects) {
				if (hit && hit.GetType() == placeMultipleItemname) {
					multipleObject = hit;
					break;
				}
			}
			if (!multipleObject) {
				NotificationSystem.AddNotificationExtended(5.0, "Loot Chests", "Item must be placed on " + placeMultipleItemname + "!", LBIconConfig.Get.warning);
				StartPlacement();
				return;
			}
		}
		LB_LC_PositionPool pool = GetSelectedPool();
		if (!pool)
			return;
		if (!multipleObject) {
			NotificationSystem.AddNotificationExtended(4.0, "Loot Chests", "Added 1 new Position", LBIconConfig.Get.info);
			LB_LC_ChestSpawnPos newPos = LB_LC_ChestSpawnPos.Init(pos, orient);
			pool.positions.Insert(newPos);
			SpawnPlaceholder(newPos);
		} else {
			if (!LootChestRPCHandlerClient.positionList) {
				NotificationSystem.AddNotificationExtended(4.0, "Loot Chests", "Waiting for server to send all object positions... Please try again in a few seconds", LBIconConfig.Get.info);
				StartPlacement();
				return;
			}
			vector posDiff = g_Game.ObjectWorldToModel(multipleObject, pos);
			vector orientDiff = orient - multipleObject.GetOrientation();
			foreach (Param2<vector, vector> objectInfo : LootChestRPCHandlerClient.positionList) {
				vector mat[3];
				Math3D.YawPitchRollMatrix(objectInfo.param2, mat);
				vector posOff = posDiff.Multiply3(mat);
				vector orientOff = orientDiff + objectInfo.param2;
				vector finalPos = posOff + objectInfo.param1;
				newPos = LB_LC_ChestSpawnPos.Init(finalPos, orientOff);
				pool.positions.Insert(newPos);
				SpawnPlaceholder(newPos);
			}
			NotificationSystem.AddNotificationExtended(4.0, "Loot Chests", "Added " + LootChestRPCHandlerClient.positionList.Count() + " new Position", LBIconConfig.Get.info);
		}
		StartPlacement();
	}
	
	void StartPlacement() {
		vector posOff = "0 0 0", dirOff = "0 0 0";
		if (g_Game.ConfigIsExisting("CfgVehicles " + selectedChest + " lbSpawnOffsetPos"))
			posOff = g_Game.ConfigGetVector("CfgVehicles " + selectedChest + " lbSpawnOffsetPos");
		if (g_Game.ConfigIsExisting("CfgVehicles " + selectedChest + " lbSpawnOffsetDir"))
			dirOff = g_Game.ConfigGetVector("CfgVehicles " + selectedChest + " lbSpawnOffsetDir");
		PlayerBase.StartAdminPlacementLB(selectedChest, "", 0, true, ScriptCaller.Create(OnAddPosition), posOff, dirOff);
	}
	
	override bool OnItemSelected(Widget w, int x, int y, int row, int column,	int oldRow, int oldColumn) {
		if (super.OnItemSelected(w, x, y, row, column, oldRow, oldColumn))
			return true;
		if (w == list_positions) {
			UpdateMap();
			if (skipMapMove) {
				skipMapMove = false;
				return true;
			}
			LB_LC_ChestSpawnPos pos = GetSelectedSpawnPos();
			if (pos)
				ZoomToPos(pos.pos);
			return true;
		}
		return false;
	}
	
	void ZoomToPos(vector pos) {
		mapwidget.SetScale(0.05);
		mapwidget.SetMapPos(pos);
	}
}
class BaseBuildingHologram: Managed
{
#ifndef SERVER
	static const string COLOR_NEUTRAL = "rearmedserver\\basebuilding\\materials\\basebuilding_neutral.rvmat";
	static const string COLOR_DEPLOYABLE = "rearmedserver\\basebuilding\\materials\\basebuilding_deployable.rvmat";
	static const string COLOR_UNDEPLOYABLE = "rearmedserver\\basebuilding\\materials\\basebuilding_undeployable.rvmat";
	
	static const float MAX_SNAP_DISTANCE = 2.8;
	static const float CAMERA_ANGLE_REQUIRED_VIEW_CONE = 0.2; // dot product of camera direction and point - cam pos
	static const float CAMERA_DISTANCE_MAX = 6.0;
	
	protected string m_BaseBuildingType;
	
	protected BaseBuilding m_PreviewItem;
	protected PlayerBase m_Player;	
		
	protected float m_SmallRotationAmount, m_LargeRotationAmount;
	protected PlacementMode m_CurrentPlacingMode;
	
	void BaseBuildingHologram(string base_building_type)
	{
		m_BaseBuildingType = base_building_type;
		if (!g_Game.IsKindOf(m_BaseBuildingType, "BaseBuilding")) {
			Error("base_building_type must inherit from BaseBuilding");
			delete this;
			return;
		}
						
		//@ Initialize after we run our first raycast
		m_PreviewItem = BaseBuilding.Cast(g_Game.CreateObjectEx(m_BaseBuildingType, vector.Zero, ECE_LOCAL));
		if (!m_PreviewItem) {
			Error("Cannot create BaseBuilding preview");
			delete this;
			return;
		}
		
		m_PreviewItem.SetIsHologram(true);
		
		m_Player = PlayerBase.Cast(g_Game.GetPlayer());			
		g_Game.GetUpdateQueue(CALL_CATEGORY_GAMEPLAY).Insert(Update);
	}

	void ~BaseBuildingHologram()
	{
		if (m_PreviewItem) {
			m_PreviewItem.Delete();
		}
	}

	protected void Update(float dt)
	{		
		// Assign local testing placement mode
		if (!m_PreviewItem) {
			return;
		}
		
#ifndef DIAG_DEVELOPER
		if (!g_Game.IsAppActive()) {
			return;
		}
#endif
		
		PlacementMode placement_mode = m_PreviewItem.GetAllowedPlacementModes();
		
		vector ray_start = g_Game.GetCurrentCameraPosition();
		vector ray_end = ray_start + g_Game.GetCurrentCameraDirection() * 3.5;
		vector ray_result;
		Object ray_contact;
		
		RaycastRVParams ray_params = new RaycastRVParams(ray_start, ray_end, m_Player);
		ray_params.flags = CollisionFlags.ALLOBJECTS;

		array<ref RaycastRVResult> results = {};
		if (DayZPhysics.RaycastRVProxy(ray_params, results, { m_PreviewItem, g_Game.GetPlayer() })) {
			foreach (RaycastRVResult result: results) {
				ray_result = result.pos;
				ray_contact = result.obj;
			}
		} else {
			ray_result = ray_end;
		}
		
		//@ TINY ROTATION
		if (GetUApi().GetInputByID(UANextAction).LocalValue()) {
			m_SmallRotationAmount += m_PreviewItem.GetSmallRotationStep();
		}
		
		if (GetUApi().GetInputByID(UAPrevAction).LocalValue()) {
			m_SmallRotationAmount -= m_PreviewItem.GetSmallRotationStep();
		}
		
		//@ large rotation isnt used until the end!!
		if (GetUApi().GetInputByID(UAReloadMagazine).LocalPress()) {
			m_LargeRotationAmount += m_PreviewItem.GetLargeRotationStep();
		}
				
#ifdef DIAG_DEVELOPER
#ifdef SNAPPING_DIAG_VERBOSE
		DbgUI.BeginCleanupScope();
		DbgUI.Begin("Hologram Information", 50, 50);
#endif
#endif

		// Reset at the beginning of each frame
		vector target_transform[4];
		
		// Handle amount rotated during interaction
		Math3D.YawPitchRollMatrix(Vector(m_SmallRotationAmount, 0, 0), target_transform);	
		if (m_PreviewItem.PlacementConformsToSurface()) {
			ray_result[1] = g_Game.SurfaceY(ray_result[0], ray_result[2]);
			
			vector surface_orientation = g_Game.GetSurfaceOrientation(ray_result[0], ray_result[2]);
			vector surface_matrix[3];
			surface_orientation.RotationMatrixFromAngles(surface_matrix);
			Math3D.MatrixMultiply3(surface_matrix, target_transform, target_transform);
		}

		#ifdef REARMED_SERVER
		if (g_Game.GetRearmedProfileSettings() && g_Game.GetRearmedProfileSettings().BaseBuildingFollowsCamera) {
			vector camera_mat[3];
			Math3D.DirectionAndUpMatrix(Vector(g_Game.GetCurrentCameraDirection()[0], 0, g_Game.GetCurrentCameraDirection()[2]).Normalized(), vector.Up, camera_mat);
			Math3D.MatrixMultiply3(camera_mat, target_transform, target_transform);
		}
		#endif
		
		target_transform[3] = ray_result + m_PreviewItem.GetFreePlacementOffset();
		
#ifdef DIAG_DEVELOPER
#ifdef SNAPPING_DIAG_VERBOSE
		DbgUI.Text(string.Format("Starting Matrix: %1", target_transform));
#endif
#endif


		m_CurrentPlacingMode = PlacementMode.NONE;
	
		if ((placement_mode & PlacementMode.FREE) == PlacementMode.FREE) {
			if (m_PreviewItem.EvaluatePlacementCondition(PlacementMode.FREE, target_transform)) {
				m_CurrentPlacingMode = PlacementMode.FREE;
			} 
		}
		
		if ((placement_mode & PlacementMode.SNAP) == PlacementMode.SNAP) {
			array<SnapPoint> anchor_snap_points = SnapPoint.GetInBox(ray_result, MAX_SNAP_DISTANCE);
			auto snap_points_and_distances = new PriorityQueue<ref Param4<vector, vector, vector, vector>, float>();
			array<SnapPoint> preview_snap_points = m_PreviewItem.GetSnapPointsArray();
			
			// Create the queue of snapping points, ranked by distance
			foreach (SnapPoint snap_point_1: preview_snap_points) {
				if (!snap_point_1) {
					continue;		
				}
				
				vector snap_point_1_world_position = snap_point_1.GetPosition().Multiply4(target_transform);
/*
#ifdef DIAG_DEVELOPER
#ifdef SNAPPING_DIAG_VERBOSE
				DbgUI.Text(string.Format("%1", snap_point_1.GetName()));
#endif
#endif
*/
				foreach (SnapPoint snap_point_2: anchor_snap_points) {					
					if (!snap_point_2) {
						continue;
					}
					
					vector t1 = g_Game.GetCurrentCameraDirection();
					vector t2 = vector.Direction(g_Game.GetCurrentCameraPosition(), snap_point_2.GetWorldPosition()).Normalized();
					float cam_dist = vector.Distance(g_Game.GetCurrentCameraPosition(), snap_point_2.GetWorldPosition());
/*
#ifdef DIAG_DEVELOPER
					DayZPlayerUtils.DrawDebugText(string.Format("%3\ndot:%1 dst:%2", Math.Sqrt(vector.Dot(t1, t2)), cam_dist, snap_point_2.GetName()), snap_point_2.GetWorldPosition(), 1.0);
#endif
*/
					
					// are you looking at it?
					if (Math.Sqrt(vector.Dot(t1, t2)) < CAMERA_ANGLE_REQUIRED_VIEW_CONE) {
						continue;
					}
					
					// are you too far?
					if (cam_dist > CAMERA_DISTANCE_MAX) {
						continue;
					}

					//snap_point_1 is the hologram
					//snap_point_2 is the receiver

					//if hologram base has the same acceptedSnapPoints as the receiver
					
					if (!snap_point_2.IsValidSnap(snap_point_1)) {
						continue;
					}

					//if hologram base has the same acceptedTypes as the receiver
					
					if (!snap_point_2.IsValidType(snap_point_1.GetSource().GetType())) {
#ifdef DIAG_DEVELOPER
#ifdef SNAPPING_DIAG_VERBOSE
						DbgUI.Text(string.Format("    anc:%1:%2 denied %3:%4", snap_point_2.GetSource().GetType(), snap_point_2.GetName(), snap_point_1.GetSource().GetType(), snap_point_1.GetName()));
#endif
#endif
						continue;
					}
					
					if (snap_point_1.GetSource().IsOccupancyExclusive() && snap_point_2.IsOccupied()) {
#ifdef DIAG_DEVELOPER
#ifdef SNAPPING_DIAG_VERBOSE
						DbgUI.Text(string.Format("    anc:%1 denied %2 (exclusive snap only)", snap_point_2.GetSource().GetType(), snap_point_1.GetSource().GetType()));
#endif
#endif
						continue;
					}
					
					
					vector snap_target_transformation[4];
					snap_point_1.SnapTo(snap_point_2, snap_target_transformation, false);
					
					//Print(snap_point_2.GetDirection());
					// -1 is because the vectors will face away from each other
					float directional_dot = vector.Dot(snap_point_1.GetDirection().Multiply3(target_transform), snap_point_2.GetDirection()) * -1; 
					//DbgUI.Text(directional_dot.ToString());
					float distance = vector.Distance(target_transform[3], snap_target_transformation[3]) + directional_dot;
					
					if (distance < MAX_SNAP_DISTANCE) {
						DbgUI.Text(string.Format("    %1, dst:%2 dot:%3", snap_point_2.GetName(), distance, directional_dot));
						snap_points_and_distances.Enqueue(new Param4<vector, vector, vector, vector>(snap_target_transformation[0], snap_target_transformation[1], snap_target_transformation[2], snap_target_transformation[3]), distance);
					}
					
					// Try the reverse aswell, anchor point only!
					if (snap_point_2.AllowReverse) {						
						Math3D.MatrixIdentity4(snap_target_transformation);
						snap_point_1.SnapTo(snap_point_2, snap_target_transformation, true);
						directional_dot = vector.Dot(snap_point_1.GetDirection().Multiply3(target_transform), snap_point_2.GetDirection()) * -1;
						distance = vector.Distance(target_transform[3], snap_target_transformation[3]) + directional_dot;
						if (distance < MAX_SNAP_DISTANCE) {
#ifdef DIAG_DEVELOPER
#ifdef SNAPPING_DIAG_VERBOSE
							DbgUI.Text(string.Format("    %1, dst:%2 dot:%3", snap_point_2.GetName(), distance, directional_dot));
#endif
#endif
							snap_points_and_distances.Enqueue(new Param4<vector, vector, vector, vector>(snap_target_transformation[0], snap_target_transformation[1], snap_target_transformation[2], snap_target_transformation[3]), distance);
						}
					}
				}
			}

			// empty that queue and acquire the beans
			while (snap_points_and_distances.Count() > 0 && m_CurrentPlacingMode != PlacementMode.SNAP) {
				Param4<vector, vector, vector, vector> closest_points = snap_points_and_distances.Dequeue();
				vector snap_target_transformation_check[4] = {
					closest_points.param1,
					closest_points.param2,
					closest_points.param3,
					closest_points.param4
				};
				
				if (m_PreviewItem.EvaluatePlacementCondition(PlacementMode.SNAP, snap_target_transformation_check)) {
					copyarray(target_transform, snap_target_transformation_check);
					m_CurrentPlacingMode = PlacementMode.SNAP;
				} else {
#ifdef DIAG_DEVELOPER
#ifdef SNAPPING_DIAG_VERBOSE
					
#endif
#endif
					m_CurrentPlacingMode = PlacementMode.NONE;
				}
			}
		}	
				
		vector large_rotation_matrix[3];
		Math3D.YawPitchRollMatrix(Vector(m_LargeRotationAmount, 0, 0), large_rotation_matrix);
		Math3D.MatrixMultiply3(large_rotation_matrix, target_transform, target_transform);
				
		//@ Lerp motion if setting is enabled
		#ifdef REARMED_SERVER
		if (g_Game.GetRearmedProfileSettings().BaseBuildingAnimationSpeed > 0.0) {
			vector current_transform[3];
			m_PreviewItem.GetTransform(current_transform);
			
			float q0[4], q1[4], q2[4];
			Math3D.MatrixToQuat(target_transform, q0);
			Math3D.MatrixToQuat(current_transform, q1);
			Math3D.QuatLerp(q2, q1, q0, dt * g_Game.GetRearmedProfileSettings().BaseBuildingAnimationSpeed);
			
			vector frame_transform[4];
			Math3D.QuatToMatrix(q2, frame_transform);
			frame_transform[3] = target_transform[3];
			m_PreviewItem.SetTransform(frame_transform);
		} else {
			m_PreviewItem.SetTransform(target_transform);
		}
		#else
		m_PreviewItem.SetTransform(target_transform);
		#endif

		// Force the placement to be disabled if we can't build here (global checks)
		PlayerBase player = PlayerBase.Cast(g_Game.GetPlayer());
		ConstructFailType construct_fail_type = BaseBuilding.CheckBuildCondition(player, m_PreviewItem, m_PreviewItem.GetUpgradeCost());
		if (construct_fail_type != ConstructFailType.NONE) {
			m_CurrentPlacingMode = PlacementMode.NONE;
		}
		
		// set color of the object
		m_PreviewItem.SetObjectMaterial(0, Ternary<string>.If(CanPlaceCurrently(), COLOR_DEPLOYABLE, COLOR_UNDEPLOYABLE));	
		
#ifdef DIAG_DEVELOPER
#ifdef SNAPPING_DIAG_VERBOSE
		DbgUI.End();
		DbgUI.EndCleanupScope();
#endif
#endif
	}

	bool CanPlaceCurrently()
	{
		return m_CurrentPlacingMode != PlacementMode.NONE;
	} 
	
	PlacementMode GetCurrentPlacingMode()
	{
		return m_CurrentPlacingMode;
	}
			
	string GetBuildType()
	{
		return m_PreviewItem.GetType();
	}
	
	vector GetBuildPosition()
	{
		return m_PreviewItem.GetPosition();
	}
	
	vector GetBuildOrientation()
	{
		return m_PreviewItem.GetOrientation();
	}
				
	BaseBuilding GetPreviewItem()
	{
		return m_PreviewItem;
	}
#endif
}
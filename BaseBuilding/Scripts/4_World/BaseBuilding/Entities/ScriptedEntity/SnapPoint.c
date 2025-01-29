class SnapPoint: ScriptedEntity
{
	static const float RESOLUTION = 0.02;
	
	bool AllowReverse;
	ref array<string> Types = {};
	ref array<string> SnapNames = {};

	void SnapPoint()
	{
		SetCollisionSphere(0.125);
#ifdef DIAG_DEVELOPER
#ifndef SERVER
		SetEventMask(EntityEvent.POSTFRAME);
#endif
#endif
	}

	void ~SnapPoint()
	{
		delete Types;
		delete SnapNames;
	}
	
	//WHAT THE FUCK?????
	/*override void EOnPostFrame(IEntity other, int extra)
	{
		vector mat[4];
		GetTransform(mat);
		int color = Colors.CYAN;
		if (IsOccupied()) {
			color = Colors.RED;
		}
		
		//Shape.CreateSphere(color, ShapeFlags.NOOUTLINE, GetPosition(), 0.1);
		//Shape.CreateArrow(GetPosition(), GetPosition() + GetDirection() * 0.5, 0.1, COLOR_GREEN, ShapeFlags.NOCULL);
	}*/
	
	bool IsOccupied()
	{
		array<SnapPoint> results = {};
		vector size = Vector(RESOLUTION * 3, RESOLUTION * 3, RESOLUTION * 3);
		array<EntityAI> entities = {};
		DayZPlayerUtils.SceneGetEntitiesInBox(GetWorldPosition() - size, GetWorldPosition() + size, entities);
		foreach (EntityAI entity: entities) {			
			SnapPoint snap_point = SnapPoint.Cast(entity);	
			if (!snap_point || snap_point == this) {
				continue;
			}
			
			if (snap_point.GetSource() == GetSource() || !snap_point.GetSource() || !GetSource()) {
				continue;
			}
			
			if (!snap_point.IsValidSnap(this) || !IsValidSnap(snap_point)) {
				continue;
			}
			
			if (!snap_point.IsValidType(GetSource().GetType()) || !IsValidType(snap_point.GetSource().GetType())) {
				continue;
			}
			
			return true;
		}
		
		return false;
	}
	
	//@ this function is carrying HARD
	array<SnapPoint> GetAttachments()
	{
		array<SnapPoint> results = {};
		vector size = Vector(RESOLUTION * 3, RESOLUTION * 3, RESOLUTION * 3);
		array<EntityAI> entities = {};
		DayZPlayerUtils.SceneGetEntitiesInBox(GetWorldPosition() - size, GetWorldPosition() + size, entities);
		foreach (EntityAI entity: entities) {
			SnapPoint snap_point = SnapPoint.Cast(entity);
			if (!snap_point || snap_point == this) {
				continue;
			}
			
			if (results.Find(snap_point) != -1) {
				continue;
			}
			
			if (!snap_point.GetSource() || snap_point.GetSource() == GetSource()) {
				continue;
			}
			
			results.Insert(snap_point);
		}
		
		return results;
	}
	
	BaseBuilding FindAttachmentByType(typename type)
	{
		array<SnapPoint> snap_points = GetAttachments();
		foreach (SnapPoint snap_point: snap_points) {
			if (snap_point.GetSource() && snap_point.GetSource().IsInherited(type)) {
				return snap_point.GetSource();
			}
		}
		
		return null;
	}
	
	float Dot(notnull SnapPoint snap_point)
	{
		vector snap_point_world_transform[4];
		snap_point.GetTransform(snap_point_world_transform);
		
		vector world_transform[4];
		GetTransform(world_transform);
		
		float dot_value = vector.Distance(snap_point_world_transform[3], world_transform[3]) / 2.0;
		for (int i = 0; i < 3; i++) {
			dot_value += 1 - vector.Dot(snap_point_world_transform[i], world_transform[i]);
		}		
		
		return dot_value;
	}

	vector GetWorldForward()
	{
		vector mat[4];
		GetSource().GetTransform(mat);
		return mat[2];
	}
	
	vector GetWorldUp()
	{
		vector mat[4];
		GetSource().GetTransform(mat);
		return mat[1];
	}
		
	bool IsValidSnap(notnull SnapPoint snap_point)
	{
		foreach (string check_name: SnapNames) {
			//check_name is just the snap points
			//BaseBuilding_FrameFoundation Snapping West
			if (g_Game.IsKindOf(string.Format("%1 Snapping %2", snap_point.GetSource().GetType(), snap_point.GetName()), check_name)) {
				return true;
			}
		}
		//defaults to true if no acceptedSnapPoints in config
		return SnapNames.Count() == 0;
	}
	
	bool IsValidType(string type)
	{
		//type == hologram base
		foreach (string check_type: Types) {
			//checking all acceptedTypes for hologram's base
			if (g_Game.IsKindOf(type, check_type)) {
				return true;
			}
		}
		return false; //forces you to define acceptedTypes in every snap point
		//defaults to true if no acceptedTypes in config
		return Types.Count() == 0;
	}
		
	void SnapTo(notnull SnapPoint anchor_point, out vector mat[4], bool reverse)
	{		
		vector anchor_world_transform[4];
		anchor_point.GetTransform(anchor_world_transform);
		Shape.CreateMatrix(anchor_world_transform);	
		vector ident[4] = {
			"1 0 0",
			"0 1 0",
			"0 0 1",
			vector.Zero
		};
		
		// Flipping the matrix first
		vector matrix_reverser[4];
		Math3D.YawPitchRollMatrix(Vector(0, 180 + reverse * 180, 180 + reverse * 180), matrix_reverser);
		
		vector coupling_matrix[4];
		Math3D.MatrixMultiply4(anchor_world_transform, matrix_reverser, coupling_matrix);
		
		vector source_inverse[4];	
		
		vector matrix[4];
		GetLocalTransform(matrix);
		
		Math3D.MatrixInvMultiply4(matrix, ident, source_inverse);
		Math3D.MatrixMultiply4(coupling_matrix, source_inverse, mat);
	}
	
	BaseBuilding GetSource()
	{
		return BaseBuilding.Cast(GetParent());
	}
	
	static array<SnapPoint> GetInBox(vector position, float size)
	{
		vector max = position + Vector(size, size, size);
		vector min = position - Vector(size, size, size);
		
		array<EntityAI> entities = {};
		DayZPlayerUtils.SceneGetEntitiesInBox(min, max, entities);
		array<SnapPoint> results = {};
		foreach (EntityAI entity: entities) {
			SnapPoint result = SnapPoint.Cast(entity);
			if (result && result.GetSource() && !result.GetSource().IsHologram()) {
				results.Insert(result);
			}
		}
		
		return results;
	}
}
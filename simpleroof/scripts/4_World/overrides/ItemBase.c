/* modded class ItemBase
{
	bool canSnapSE = false;
	bool canSnapFloorSE = false;
	
	// UTILITIES
	bool canSnapSE()
	{
		return canSnapSE;
	}
	bool canSnapFloorSE()
	{
		return canSnapFloorSE;
	}
	
	void setCanSnapSE(bool a)
	{
		canSnapSE = a;
	}
	void setCanSnapFloorSE(bool a)
	{
		canSnapFloorSE = a;
	}
	
	vector getSnappingPointWallSE()
	{
		vector pos = "0 0 0";
		switch(snappingWallPointIndexSE)
		{
			case 0:
			pos = GetMemoryPointPos( "Snapping1" );
			return ModelToWorld( pos );
			break;
			
			case 1:
			pos = GetMemoryPointPos( "Snapping2" );
			return ModelToWorld( pos );
			break;
			
			case 2:
			pos = GetMemoryPointPos( "Snapping3" );
			return ModelToWorld( pos );
			break;
			
			case 3:
			pos = GetMemoryPointPos( "Snapping4" );
			return ModelToWorld( pos );
			break;
			
			case 4:
			pos = GetMemoryPointPos( "Snapping5" );
			return ModelToWorld( pos );
			break;
			
			case 5:
			pos = GetMemoryPointPos( "Snapping6" );
			return ModelToWorld( pos );
			break;
			
			case 6:
			pos = GetMemoryPointPos( "Snapping7" );
			return ModelToWorld( pos );
			break;
		}
		pos = GetMemoryPointPos( "Snapping1" );
		return ModelToWorld( pos );
	}
	
	vector getSnappingPointFloorSE()
	{
		vector pos = "0 0 0";
		switch(snappingFloorPointIndexSE)
		{
			case 0:
			pos = GetMemoryPointPos( "SnappingFloor1" );
			return ModelToWorld( pos );
			break;
			
			case 1:
			pos = GetMemoryPointPos( "SnappingFloor2" );
			return ModelToWorld( pos );
			break;
			
			case 2:
			pos = GetMemoryPointPos( "SnappingRoof1" );
			return ModelToWorld( pos );
			break;
			
			case 3:
			pos = GetMemoryPointPos( "SnappingRoof2" );
			return ModelToWorld( pos );
			break;
		}
		pos = GetMemoryPointPos( "SnappingFloor1" );
		return ModelToWorld( pos );
	}
	
	vector getSnappingRotationSE()
	{
		return GetOrientation();
	}
}
 */
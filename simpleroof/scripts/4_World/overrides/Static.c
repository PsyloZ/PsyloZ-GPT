/* // Snapping
static int snappingWallPointIndexSE = 0;
static int snappingFloorPointIndexSE = 0;
static bool snappingEnabledSE = true;
static bool snappingEnabledSE_Looking = true;

static bool snappinghologramSE = true;
static bool changeHoloIndexSE = true;

static const int MAX_SNAP_POINTS_WALL = 6;
static const int MAX_SNAP_POINTS_FLOOR = 3;

static void cycleSnappingNextWall()
{
	snappingWallPointIndexSE = snappingWallPointIndexSE + 1;
	if(snappingWallPointIndexSE > MAX_SNAP_POINTS_WALL)
	{
		snappingWallPointIndexSE = 0;
	}
}

static void cycleSnappingNextFloor()
{
	snappingFloorPointIndexSE = snappingFloorPointIndexSE + 1;
	if(snappingFloorPointIndexSE > MAX_SNAP_POINTS_FLOOR)
	{
		snappingFloorPointIndexSE = 0;
	}
}

static void toggleSnappingSE()
{
	snappingEnabledSE = !snappingEnabledSE;
}

static void toggleSnappingLookingSE()
{
	snappingEnabledSE_Looking = !snappingEnabledSE_Looking;
}

//Big help from Henny and the modding discord <3
Object getObjectAtCrosshairSE(float distance = 1000.0, float radius = 0, Object with = NULL)
{
	vector rayStart = GetGame().GetCurrentCameraPosition();
	vector rayEnd = rayStart + GetGame().GetCurrentCameraDirection() * distance;

	auto objs = GetObjectsAt2SE( rayStart, rayEnd, GetGame().GetPlayer(), radius, with );

	if( objs.Count() > 0 )
	{
		return objs[ 0 ];
	}

	return NULL;
}

static set< Object > GetObjectsAt2SE( vector from, vector to, Object ignore = NULL, float radius = 0, Object with = NULL )
{
    vector contact_pos;
    vector contact_dir;
    int contact_component;

    set< Object > view = new set< Object >;

    DayZPhysics.RaycastRV( from, to, contact_pos, contact_dir, contact_component, view, with, ignore, false, false, ObjIntersectView, radius );

    if ( view ) 
    {
        return view;
    }
    return NULL;
}

ItemBase CHOPPER_SNAPPING_OBJECT;
	
void SelectObjectSE()
{		
	CHOPPER_SNAPPING_OBJECT = ItemBase.Cast(SnappingWithOtherWallSE());	
}

Object SnappingWithOtherWallSE()
{
	Object obj = getObjectAtCrosshairSE();
	
	if (obj.IsInherited(Chopper_Base))
	{
		return obj;
	}
	
	return null;
}

static void Chopper_Message( PlayerBase player, string txt ) 
{
	if ( GetGame().IsServer() && GetGame().IsMultiplayer() )
	{
		player.MessageImportant( txt);
	} 
	else 
	{
    	GetGame().GetMission().OnEvent( ChatMessageEventTypeID, new ChatMessageEventParams( CCDirect, "", txt, "" ) );
	}
}
 */
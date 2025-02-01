/* modded class MissionGameplay
{
	// SNAPPING
	override void OnKeyRelease(int key)
	{
		super.OnKeyRelease(key);
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if(!player) return;
		ItemBase item_in_hands = ItemBase.Cast(player.GetHumanInventory().GetEntityInHands());
		
		if ( key == KeyCode.KC_B )  //TOGGLE SNAPPING
		{
			if(item_in_hands)
			{
				if (item_in_hands.canSnapSE())
				{	
					toggleSnappingSE();
				}
				if (item_in_hands.canSnapFloorSE())
				{	
					toggleSnappingSE();
				}
			}
        }
		if ( key == KeyCode.KC_K )  //SELECT SNAPPING OBJECT
		{
			if(item_in_hands)
			{
				if (item_in_hands.canSnapSE())
				{	
					SelectObjectSE();
					toggleSnappingLookingSE();
				}
				if (item_in_hands.canSnapFloorSE())
				{	
					SelectObjectSE();
					toggleSnappingLookingSE();
				}
			}
        }
		if ( key == KeyCode.KC_F )	//NEXT SNAPPING POINT
		{
			if(item_in_hands)
			{
				if (item_in_hands.canSnapSE())
				{	
					cycleSnappingNextWall();
				}
				if (item_in_hands.canSnapFloorSE())
				{	
					cycleSnappingNextFloor();
				}
			}
		}
    }

	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);

		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		ItemBase iteminhands;

		if (player)
		{
			if (player.GetHumanInventory())
			{
				if (player.GetHumanInventory().GetEntityInHands())
				{
					iteminhands = ItemBase.Cast(player.GetHumanInventory().GetEntityInHands());
				}
			}
		}

		if (snappingEnabledSE_Looking)
		{
			if (iteminhands)
			{
				if (iteminhands.canSnapSE() || iteminhands.canSnapFloorSE())
				{
					if (getObjectAtCrosshairSE())
					{
						if (getObjectAtCrosshairSE().IsInherited(Chopper_Base))
						{
							SelectObjectSE();
						}
					}
				}
			}
		}
	}
}
 */
modded class Hologram
{
	/* override protected vector GetProjectionEntityPosition ( PlayerBase player )
	{
		ItemBase item_in_hands;
		if ( player )
		{
			if ( player.GetHumanInventory() )
			{
				if ( player.GetHumanInventory().GetEntityInHands() )
				{
					item_in_hands = ItemBase.Cast(player.GetHumanInventory().GetEntityInHands());
				}
			}
		}
		if ( item_in_hands )
		{
			if ( item_in_hands.canSnapSE() || item_in_hands.canSnapFloorSE() )
			{	
				Chopper_Base otherSnappingObjectSE;
				otherSnappingObjectSE = CHOPPER_SNAPPING_OBJECT;
				if ( snappingEnabledSE && otherSnappingObjectSE != NULL )
				{
					if ( item_in_hands.canSnapSE() )
					{
						SetIsFloating( false );
						return otherSnappingObjectSE.getSnappingPointWallSE();
					}
					if ( item_in_hands.canSnapFloorSE() )
					{
						SetIsFloating( false );
						return otherSnappingObjectSE.getSnappingPointFloorSE();
					}
				}
			}
		}
		return super.GetProjectionEntityPosition(player);
	} */
	
	override string ProjectionBasedOnParent()
	{
		ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());	

		if ( item_in_hands.IsInherited(Chopper_Step_Ladder_2Kit) )
			return "Chopper_Step_Ladder_2";
		
		return super.ProjectionBasedOnParent();
	}
	
   /*  override void EvaluateCollision(ItemBase action_item = null)
    {
		ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());
		ItemBase chopperfloor = ChopperFloorCollision();
		if (item_in_hands && item_in_hands.IsInherited(Chopper_Step_Ladder_2Kit))
        {
			if (chopperfloor)
			{
				SetIsColliding(false);
				return;
			}
        }
        super.EvaluateCollision(action_item);
    }
	
	ItemBase ChopperFloorCollision()
	{
		vector center;
		vector relative_ofset; //we need to lift BBox, because it is calculated from the bottom of projection, and not from the middle
		vector absolute_ofset = "0 0.01 0"; //we need to lift BBox even more, because it colliddes with house floors due to various reasons (probably geometry or float imperfections)
		vector orientation = GetProjectionOrientation();
		vector edge_length;
		vector min_max[2];
		ref array<Object> excluded_objects = new array<Object>;
		ref array<Object> collided_objects = new array<Object>;
		m_Projection.GetCollisionBox( min_max );
		relative_ofset[1] = ( min_max[1][1] - min_max[0][1] ) / 2.4;
		center = m_Projection.GetPosition() + relative_ofset + absolute_ofset;
		edge_length = GetCollisionBoxSize( min_max );
		excluded_objects.Insert( m_Projection );
		if ( GetGame().IsBoxColliding( center, orientation, edge_length, excluded_objects, collided_objects ) )
		{	
			for ( int i = 0; i < collided_objects.Count(); i++ )
			{
				Object obj_collided = collided_objects[i];
				if ( obj_collided.IsInherited(ChopperRoof2) )
				{
					ChopperRoof2 chopper_roof_2 = ChopperRoof2.Cast(obj_collided);
					return chopper_roof_2;
				}
			}
		}
		return null;
	} */
	
	override void SetProjectionOrientation( vector orientation ) 
	{
		ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());
		if (item_in_hands.IsInherited(Chopper_BaseKit))
		{
			//m_Rotation = "0 0 0";
			m_Projection.SetOrientation( m_Rotation );
		} 
		else
		{
			super.SetProjectionOrientation(orientation);
		}
	}
	
	override vector GetProjectionRotation()
	{
		return m_Rotation;
	}
	
	override void AddProjectionRotation( float addition )
	{	
		m_Rotation[0] = m_Rotation[0] + (addition / 6 ) ;
	}
	
	override void SubtractProjectionRotation( float subtraction )
	{	
		m_Rotation[0] = m_Rotation[0] - (subtraction / 6);
	}
}

modded class Hologram
{
	
	override string ProjectionBasedOnParent()
	{
		ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());	

		if ( item_in_hands.IsInherited(Raid_Ladder_Kit) )
			return "Raid_Ladder";
		
		return super.ProjectionBasedOnParent();
	}

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

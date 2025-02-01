/* modded class BaseBuildingBase extends ItemBase
{
	bool IsSimplePart()
    {
        return false;
    }
	
	bool HasGatePart()
	{
		return false;
	}
	
	bool IsFlat()
	{
		return false;
	}
	
	bool DisableDestroy()
    {
        return false;
    }
	
	bool HasProperDistanceSB( string selection, PlayerBase player )
	{
		if ( MemoryPointExists( selection ) )
		{
			vector selection_pos = ModelToWorld( GetMemoryPointPos( selection ) );
			float distance = vector.Distance( selection_pos, player.GetPosition() );
			if ( distance >= 1.4 )
			{
				return false;
			}
		}
		return true;
	}
}
 */
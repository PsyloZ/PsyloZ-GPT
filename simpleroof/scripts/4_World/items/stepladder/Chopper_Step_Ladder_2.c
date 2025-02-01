class Chopper_Step_Ladder_2 extends ItemBase
{
	override bool CanPutInCargo(EntityAI parent)
    {
        if (!super.CanPutInCargo(parent)) {return false;}        
        if (GetNumberOfItems() == 0)
        {
            return false;
        }
        return false;
    }
    
    override bool CanPutIntoHands(EntityAI parent)
    {
        if(!super.CanPutIntoHands(parent))
        {
            return false;
        }
        if (GetNumberOfItems() == 0)
        {
            return false;
        }
        return false;
    }
	
	bool HasProperDistance( string selection, PlayerBase player )
	{
		if ( MemoryPointExists( selection ) )
		{
			vector selection_pos = ModelToWorld( GetMemoryPointPos( selection ) );
			float distance = vector.Distance( selection_pos, player.GetPosition() );
			if ( distance >= 2.3 )
			{
				return false;
			}
		}
		return true;
	}
	
    override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionFoldLadder);
    }
}

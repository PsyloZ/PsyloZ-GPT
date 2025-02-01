/* modded class VicinityItemManager
{
	override bool IsObstructed (Object filtered_object)
	{
		if ( filtered_object.CanUseConstruction() )
		{
			Chopper_Base chopperbase = Chopper_Base.Cast( filtered_object );
			if ( chopperbase )
			{
				return false;
			}
		}
		
		return super.IsObstructed (filtered_object);
	}
}
 */
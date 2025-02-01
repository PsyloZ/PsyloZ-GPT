/* modded class ActionDismantlePart: ActionContinuousBase
{
	protected bool DismantleCondition( PlayerBase player, ActionTarget target, ItemBase item, bool camera_check )
	{	
		if ( player && !player.IsLeaning() )
		{
			Object target_object = target.GetObject();
			if ( target_object && target_object.CanUseConstruction() )
			{
				string part_name = target_object.GetActionComponentName( target.GetComponentIndex() );
				BaseBuildingBase base_building = BaseBuildingBase.Cast( target_object );
				Construction construction = base_building.GetConstruction();		
				ConstructionPart construction_part = construction.GetConstructionPartToDismantle( part_name, item );
				Chopper_Base chopperbase = Chopper_Base.Cast( target.GetObject() );
				
				if ( construction_part )
				{
					if ( base_building.IsSimplePart() )
					{	
						if ( !base_building.IsFlat() )
						{
							//camera and position checks
							if ( !base_building.IsFacingPlayer( player, part_name ) && !player.GetInputController().CameraIsFreeLook() && base_building.HasProperDistance( construction_part.GetMainPartName(), player ) )
							{
								//Camera check (client-only)
								if ( camera_check )
								{
									if ( GetGame() && ( !GetGame().IsMultiplayer() || GetGame().IsClient() ) )
									{
										if ( base_building.IsFacingCamera( part_name ) )
										{
											return false;
										}
									}
								}
								//Distance check
								if ( chopperbase )
								{
									if ( !chopperbase.HasProperDistanceSB( "center", player ) )
									{
										return false;
									}
								}
								ConstructionActionData construction_action_data = player.GetConstructionActionData();
								construction_action_data.SetTargetPart( construction_part );
								return true;
							}
						}
						if( base_building.IsFlat() )
						{
							if( chopperbase )
							{
								if ( chopperbase.HasProperDistanceSB( "center", player ) )
								{
									ConstructionActionData construction_action_data_flat = player.GetConstructionActionData();
									construction_action_data_flat.SetTargetPart( construction_part );
									return true;
								}
							}
							return false;
						}
					}
					if ( !base_building.IsSimplePart() )
					{
						return super.DismantleCondition(player, target, item, camera_check);
					}
				}
			}
		}
		return false;
	}
}
 */
/* modded class MiscGameplayFunctions
{
	override static bool ComplexBuildCollideCheckClient( PlayerBase player, ActionTarget target, ItemBase item, string partName = "" )
	{
		BaseBuildingBase base_building = BaseBuildingBase.Cast( target.GetObject() );
		if (base_building && !base_building.IsSimplePart())
		{
			Construction construction = base_building.GetConstruction();
			if ( construction && BuildCondition( player, target, item, false ))
			{
				ConstructionActionData construction_action_data = player.GetConstructionActionData();
				if (partName == "")
					partName = construction_action_data.GetCurrentBuildPart().GetPartName();
				return !construction.IsColliding( partName );
			}
		}
		if (base_building && base_building.IsSimplePart())
		{
			Construction constructionSB = base_building.GetConstruction();
			if ( constructionSB && BuildCondition( player, target, item, false ))
			{
				ConstructionActionData construction_action_dataSB = player.GetConstructionActionData();
				if (partName == "")
					partName = construction_action_dataSB.GetCurrentBuildPart().GetPartName();
				return true;
			}
		}
		return false;
	}

	override static bool BuildCondition( PlayerBase player, ActionTarget target, ItemBase item, bool camera_check )
	{
		if ( player && !player.IsLeaning() )
		{
			Object targetObject = target.GetObject();
			if ( targetObject && targetObject.CanUseConstruction() )
			{
				BaseBuildingBase base_building = BaseBuildingBase.Cast( targetObject );
				ConstructionActionData construction_action_data = player.GetConstructionActionData();
				construction_action_data.SetTarget( targetObject );
				string main_part_name = targetObject.GetActionComponentName( target.GetComponentIndex() );
				if ( GetGame().IsMultiplayer() || GetGame().IsServer() )
				{
					construction_action_data.RefreshPartsToBuild( main_part_name, item, !targetObject.CanUseHandConstruction() );
				}
				ConstructionPart constrution_part = construction_action_data.GetCurrentBuildPart();


				if ( base_building && !base_building.IsSimplePart() && constrution_part )
				{
					//camera and position checks
					bool position_check = ( base_building.MustBeBuiltFromOutside() && !base_building.IsPlayerInside(player, constrution_part.GetMainPartName()) ) || ( !base_building.MustBeBuiltFromOutside() && base_building.IsPlayerInside(player, constrution_part.GetMainPartName()) );
					if ( position_check && !player.GetInputController().CameraIsFreeLook() )
					{
						//Camera check (client-only)
						if ( camera_check )
						{
							if ( GetGame() && ( !GetGame().IsMultiplayer() || GetGame().IsClient() ) )
							{
								return !base_building.IsFacingCamera( constrution_part.GetMainPartName() );
							}
						}

						return true;
					}
				}
				if ( base_building && base_building.IsSimplePart() && constrution_part )
				{
					return true;
				}
			}
		}
		return false;
	}
}; */
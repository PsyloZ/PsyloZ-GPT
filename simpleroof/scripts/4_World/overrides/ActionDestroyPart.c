/* modded class ActionDestroyPart: ActionContinuousBase
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object targetObject = target.GetObject();
		BaseBuildingBase base_building = BaseBuildingBase.Cast( targetObject );
		
		if ( !base_building.DisableDestroy() )
		{
			return DestroyCondition( player, target, item, true );
		}
		return false;
	}
}
 */
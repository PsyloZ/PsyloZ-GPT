modded class Hologram
{
    override bool IsCollidingBBox(ItemBase action_item = null)
	{
        return false;
    }
	
	override void EvaluateCollision(ItemBase action_item = null)
    {    
        SetIsColliding(false);
    }
	
	//need to investigate this more, for now it stops duplicate items when kits are placed
    override EntityAI PlaceEntity(EntityAI entity_for_placing)
    {
        return entity_for_placing;
    }

    override string ProjectionBasedOnParent()
	{
		RA_BoxKit_Base kit = RA_BoxKit_Base.Cast(m_Player.GetHumanInventory().GetEntityInHands());

		if (kit)
		{
			return kit.RA_GetItem();
		}
		return super.ProjectionBasedOnParent();
    }
}
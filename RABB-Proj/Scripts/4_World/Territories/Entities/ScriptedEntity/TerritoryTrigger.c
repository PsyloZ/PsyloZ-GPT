/*
	EOnEnter & EOnLeave will handle entities entering / exiting the zone so we dont need to update every single CE UpdateVertsEx
	SetRadius will handle entities that existed before the trigger was created
*/
class TerritoryTrigger: Trigger
{	
	protected TerritoryHQ m_TerritoryHQ;
	
	override void EOnInit(IEntity other, int extra)
	{
		//@ Initialization value
		SetCollisionSphere(0);
	}
	
	void SetHQ(TerritoryHQ hq)
	{
		m_TerritoryHQ = hq;
	}
	
	TerritoryHQ GetHQ()
	{
		return m_TerritoryHQ;
	}
			
	void SetRadius(float radius)
	{
		if (!g_Game.IsServer()) {
			return;
		}
				
		// update our collision for the server
		SetCollisionSphere(radius);
		
		vector position = GetWorldPosition();

		radius *= radius;
		
		array<EntityAI> entities = {};
		// AABB requires zero orientation change, we use GetEntitiesInBox and then check distance after for each individual entity
    	DayZPlayerUtils.SceneGetEntitiesInBox(position - Vector(radius, radius, radius), position + Vector(radius, radius, radius), entities);

		// Trigger EntityEvent.ENTER for every item in radius, let the trigger do the rest of the hard work
		for (int i = 0; i < entities.Count(); i++) {
			if (vector.DistanceSq(position, entities[i].GetWorldPosition()) <= radius && !entities[i].IsPendingDeletion()) {
				SendEvent(entities[i], EntityEvent.ENTER, 0);
			}
		}
	}
	
	override void OnEnterServerEvent(TriggerInsider insider) 
	{
		super.OnEnterServerEvent(insider);
		
		if (!m_TerritoryHQ) {
			Error("No parent HQ found for territorytrigger");
			return;
		}
		m_TerritoryHQ.RegisterItem(ItemBase.Cast(insider.GetObject()));
	}
	
	override void OnLeaveServerEvent(TriggerInsider insider) 
	{
		super.OnLeaveServerEvent(insider);
		
		if (!m_TerritoryHQ) {
			Error("No parent HQ found for territorytrigger");
			return;
		}
		
		m_TerritoryHQ.UnregisterItem(ItemBase.Cast(insider.GetObject()));
	}
			
	override bool CanAddObjectAsInsider(Object object)
	{
		return (object && object.IsInherited(ItemBase) && (GetInsiderForObject(object) == null));
	}
}
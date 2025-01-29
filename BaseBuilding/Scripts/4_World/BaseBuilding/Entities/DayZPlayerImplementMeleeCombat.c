modded class DayZPlayerImplementMeleeCombat
{
	override void Init(DayZPlayerImplement player)
	{
		super.Init(player);

		m_TargetableObjects.Insert(BaseBuilding);
	}

	override protected bool HitZoneSelectionRaycastHelper(out vector hitPos, out int hitZone, out Object target)
	{
		return HitZoneSelectionRaycast(hitPos, hitZone, target, true);
	}
}
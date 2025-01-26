modded class MissionServer
{
	protected ref array<NoBuildZone> m_NoBuildZones = {};
	
	override void OnMissionStart()
	{
		super.OnMissionStart();
		
		array<ref NoBuildZoneData> no_build_zones = {};
		RegisterNoBuildZones(no_build_zones);
		
		foreach (NoBuildZoneData no_build_zone_data: no_build_zones) {
			NoBuildZone no_build_zone = NoBuildZone.Cast(GetGame().CreateObjectEx("NoBuildZone", no_build_zone_data.Position, ECE_NONE));
			if (!no_build_zone) {
				continue;
			}
			
			no_build_zone.SetRadius(no_build_zone_data.Radius);
			//no_build_zone.SetSize(no_build_zone_data.Radius);
			m_NoBuildZones.Insert(no_build_zone);
		}
		
	}
		
	// override in init.c
	void RegisterNoBuildZones(array<ref NoBuildZoneData> no_build_zones) {}
}
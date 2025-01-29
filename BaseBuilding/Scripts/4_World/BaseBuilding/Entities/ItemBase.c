modded class ItemBase
{
	protected float m_GlobalHealthSync;
	protected TerritoryHQ m_CurrentHQ;

	#ifdef DIAG_DEVELOPER
	//easier debug
	bool m_IsDecaying;
	#endif
	
	void ItemBase()
	{
		if (GetCostToUpkeep() > 0) {
			SetFlags(EntityFlags.TOUCHTRIGGERS, false);
			RegisterNetSyncVariableObject("m_CurrentHQ");
		}
		RegisterNetSyncVariableFloat("m_GlobalHealthSync", 0.0, 1.0, 3);

#ifdef SERVER
		SetHealthSynchDirty();
#endif
	}

			
	void SetHealthSynchDirty()
	{		
#ifdef SERVER	
		m_GlobalHealthSync = GetHealth01("GlobalHealth", "Health");
		SetSynchDirty();
#endif
	}
	
	// Only info available to the client is the health from 0..1
	float GetSyncedHealth01()
	{
		return m_GlobalHealthSync;
	}
		
#ifdef SERVER	
	// update health sync on damage
	override void EEHealthLevelChanged(int oldLevel, int newLevel, string zone)
	{
		super.EEHealthLevelChanged(oldLevel, newLevel, zone);
		SetHealthSynchDirty();
	}
	
	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);		
		SetHealthSynchDirty();
	}
#endif

	void OnRaiseChanged(bool state)
	{
	}

	string RA_GetItem()
	{
		return string.Empty;
	}

	string GetKit()
	{
		return string.Empty;
	}
	
	void SetCurrentHQ(TerritoryHQ hq)
	{
		if (!g_Game.IsServer()) {
			return;
		}
		
		if (m_CurrentHQ) {
			hq = TerritoryHQ.GetOldestHQ({ m_CurrentHQ, hq });
		}
		
		m_CurrentHQ = hq;
		SetSynchDirty();
	}
	
	TerritoryHQ GetCurrentHQ()
	{
		return m_CurrentHQ;
	}

	#ifdef DIAG_DEVELOPER
	bool IsDecaying()
	{
		return m_IsDecaying;
	}

	void SetDecayingState(bool state)
	{
		m_IsDecaying = state;
	}
	#endif
	
	override void OnCEUpdate()
	{
		super.OnCEUpdate();
		
		if (GetCostToUpkeep() <= 0 || GetHierarchyParent() || IsRuined()) { //attachments do not handle well with triggers
			return;
		}
		
		TerritoryHQ current_hq = GetCurrentHQ();

		// 86400 seconds in a day multiplied by inverse dt gets us how many nails 
		// in this specific interval		
		float health_to_remove = (m_ElapsedSinceLastUpdate / GetTimeToDecay()) * GetMaxHealth("GlobalHealth", "Health");

		if (!current_hq) {
			DecreaseHealth("GlobalHealth", "Health", health_to_remove);
			return;
		}

		if (!current_hq.ConsumeNails(GetCostToUpkeep() * (m_ElapsedSinceLastUpdate / TimeSpan.DAY))) {
			DecreaseHealth("GlobalHealth", "Health", health_to_remove);
			#ifdef DIAG_DEVELOPER
			SetDecayingState(1);
			#endif
		}
		else if(GetHealth01() != 1) {
			AddHealth("GlobalHealth", "Health", health_to_remove);
			#ifdef DIAG_DEVELOPER
			SetDecayingState(0);
			#endif
		}
	}
	
	//# Value used for territory decay 
		// return: nails / 24 hrs
	float GetCostToUpkeep()
	{
		return 0;
	}
	
	//# Value used to determine health removal rate. 
		// return: seconds
	float GetTimeToDecay()
	{
		return 24.0 * 60.0 * 60.0;
	}
}
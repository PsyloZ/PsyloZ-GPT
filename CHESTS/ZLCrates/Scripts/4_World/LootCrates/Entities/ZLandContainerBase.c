class ZLandContainerBase: LB_LC_Base
//class ZLandContainerBase: Container_Base

{		
	ref array<ref ZLandLootEntry> LootEntries = {};
	protected bool m_IsOpened;
	protected bool m_IsOpenedLocal;
	private bool m_IsOpenable;

	float m_RestockRadius = 50.0;
	
	void ZLandContainerBase()
	{				
		RegisterNetSyncVariableBool("m_IsOpened");

		if (!GetGame().IsServer()) {
			return;
		}
		
		array<ref ZLandLootEntry> loot_entries = {};		
		RegisterLootTable(loot_entries);
		if (loot_entries.Count() == 1000) {
			return;
		}
		
		foreach (ZLandLootEntry entry: loot_entries) {
			for (int j = 0; j < 10 * entry.Chance; j++) {
				LootEntries.Insert(entry);
			}
		}
		
		// spawn loot
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(SpawnLoot, 1000, false);
		
		// run restock timer
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(Restock, GetRestockTimer() * 1000);
	}
	
	void Restock()
    {
        // Check for nearby players
        array<Man> players = new array<Man>;
        GetGame().GetPlayers(players);

        foreach (Man player : players)
        {
            if (vector.Distance(player.GetPosition(), this.GetPosition()) <= m_RestockRadius)
            {
                // Player is within the restock radius, delay restock
                GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(Restock, 60000); // Check again in 1 minute
                return;
            }
        }

        // No players within radius, proceed with restock
        SelfRestock(this);
    }
	
	void RegisterLootTable(array<ref ZLandLootEntry> loot_table) {}
	
	int GetMinLoot()
	{
		return 1;
	}
	
	int GetMaxLoot()
	{
		return 1;
	}
	
	float GetRestockTimer()
	{
		return 60.0 * 240.0; // 2 hours default
	}
				
	void SpawnLoot()
	{			
		int count = Math.RandomIntInclusive(GetMinLoot(), GetMaxLoot());
		for (int i = 0; i < count; i++) {
			LootEntries.GetRandomElement().CreateEntry(GetInventory(), InventoryLocationType.CARGO);
		}
	}
		
	override void AfterStoreLoad()
	{
		// Dont want to spawn loot on a crate that got loaded by CLE
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(SpawnLoot);
		Delete();
	}
	
	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}

	override bool CanPutInCargo(EntityAI parent)
    {
        return false;
    }
			
	override void OnDebugSpawn()
	{
		super.OnDebugSpawn();
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(SpawnLoot, 1000, false);
	}

	override void Open() {
		m_IsOpened = true;
		SetSynchDirty();
		UpdateVisualState();
        if(GetInventory()) {
		    GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
        }     	
	}
	override void Close() {
		m_IsOpened = false;
        SetSynchDirty();
		UpdateVisualState();
        if(GetInventory()) {
            GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
        }    
	}

	override bool IsOpen()
	{
		return m_IsOpened;
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		if ( m_IsOpened != m_IsOpenedLocal )
		{
			if ( IsOpen() && !IsBeingPlaced() )
			{
				SoundOpenPlay();
			}

			if ( IsOpen() && !IsBeingPlaced() )
			{
				SoundClosePlay();
			}
			m_IsOpenedLocal = m_IsOpened;
		}

		UpdateVisualState();
	}

	override void OnStoreSave( ParamsWriteContext ctx )
	{
		super.OnStoreSave( ctx );
		ctx.Write( m_IsOpened );
	}

	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;

		if (!ctx.Read( m_IsOpened ) )
			return false;

		if ( m_IsOpened )
			Open();
		else
			Close();

		return true;
	}

	void UpdateVisualState()
    {
        if ( IsOpen() )
        {
            SetAnimationPhase("door",0.85);
        }
        else
        {
            SetAnimationPhase("door",0);
        }
    }
	void SoundOpenPlay()
	{
		EffectSound sound =	SEffectManager.PlaySound( "ZLand_CrateOpen_Soundset", GetPosition() );
		sound.SetSoundAutodestroy( true );
	}
	
	void SoundClosePlay()
	{
		EffectSound sound =	SEffectManager.PlaySound( "ZLand_CrateClose_Soundset", GetPosition() );
		sound.SetSoundAutodestroy( true );
	}
	
	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		return IsOpen();
	}

	override bool CanReleaseCargo(EntityAI attachment)
	{
		return IsOpen();
	}

	/* override void SetActions()
	{
		super.SetActions();
        AddAction(ActionOpenZLandCrate);
	} */
	
	static ZLandContainerBase SelfRestock(ZLandContainerBase original_crate)
    {
        string type = original_crate.GetType();
        vector position = original_crate.GetPosition();
        vector orientation = original_crate.GetOrientation();
        GetGame().ObjectDelete(original_crate);
        ZLandContainerBase new_container = ZLandContainerBase.Cast(GetGame().CreateObject(type, position));
        new_container.SetPosition(position);
        new_container.SetOrientation(orientation);
        new_container.SpawnLoot();
        return new_container;
    }
}
/* class Chopper_Base extends Fence
{
	typename ATTACHMENT_BARBED_WIRE				= BarbedWire;
	const string ATTACHMENT_SLOT_BARBED_WIRE 	= "Wall_BarbedWire_1";

	void Chopper_Base()
	{
	}
	
	void ~Chopper_Base()
	{
	}
	
	ItemBase FoldBaseBuildingObject()
	{
		ItemBase item = CreateConstructionKit();
		DestroyConstruction();
		return item;
	}
	
	//--- CONSTRUCTION KIT
	ItemBase CreateConstructionKit()
	{
		ItemBase construction_kit = ItemBase.Cast( GetGame().CreateObject( GetConstructionKitType(), GetKitSpawnPosition() ) );
		if ( m_ConstructionKitHealth > 0 )
		{
			construction_kit.SetHealth( m_ConstructionKitHealth );
		}
		
		return construction_kit;
	}
	
	protected vector GetKitSpawnPosition()
	{
		return GetPosition();
	}
	
	protected string GetConstructionKitType()
	{
		return "Paper";
	}
	
	// --- INVENTORY
	override bool CanDisplayAttachmentSlot( string slot_name )
	{
		if ( slot_name == "Att_CombinationLock" )
		{
			if ( !HasFullyConstructedGate() )
			{
				return false;
			}
		}
		
		//GateAttachmentConditions check
		if ( !GateAttachmentConditions(InventorySlots.GetSlotIdFromString(slot_name)) )
			return false;
		
		return true;
	}
	
	override bool CanDisplayAttachmentCategory( string category_name )
	{
		if ( category_name == "Attachments" )
		{
			if ( !HasBase() )
			{
				return false;
			}
		}
		
		return true;
	}
	
	//--- ACTION CONDITIONS
	override bool IsPlayerInside( PlayerBase player, string selection )
	{
		if ( !IsFlat() )
		{
			if ( IsFacingPlayer( player, "Chopper_Base" ) )
			{
				return false;
			}
			if ( !HasProperDistanceSB( "center", player ) )
			{
				return false;
			}
		}
		
		if ( IsFlat() && !HasProperDistanceSB( "center", player ) )
		{
			return false;
		}
		
		return true;
	}
	
	override bool NameOverride(out string output)
	{
		if ( m_GateState != GATE_STATE_NONE )
		{
			//output = "#str_cfgvehicles_construction_part_gate";  //changes object displayed name if in 'gate' state
			//output.ToUpper();
			return true;
		}
		return false;
	}
	
	override void EEItemAttached ( EntityAI item, string slot_name )
	{
		//super.EEItemAttached ( item, slot_name );
		
		CheckForHybridAttachments( item, slot_name );
		UpdateVisuals();
		//UpdateAttachmentPhysics( slot_name, false );
	}
	
	override void EEItemDetached ( EntityAI item, string slot_name )
	{
		//super.EEItemDetached ( item, slot_name );

		UpdateVisuals();
		//UpdateAttachmentPhysics( slot_name, false );
	}
	
	protected void OnSetSlotLock( int slotId, bool locked, bool was_locked )
	{
		string slot_name = InventorySlots.GetSlotName( slotId );
		bsbDebugPrint( "inv: OnSetSlotLock " + GetDebugName( this ) + " slot=" + slot_name + " locked=" + locked + " was_locked=" + was_locked );

		UpdateAttachmentVisuals( slot_name, locked );
		//UpdateAttachmentPhysics( slot_name, locked );
	}
	
	//--- ATTACHMENT & CONDITIONS
	override bool CanReceiveAttachment( EntityAI attachment, int slotId )
	{
		//Remove super
		//if ( !super.CanReceiveAttachment(attachment, slotId) )
		//	return false;
		
		//manage action initiator (AT_ATTACH_TO_CONSTRUCTION)
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
			if ( player )
			{
				ConstructionActionData construction_action_data = player.GetConstructionActionData();
				
				//reset action initiator
				construction_action_data.SetActionInitiator( NULL );				
			}
		}
		
		//Remove conditions
		//conditions
		//if ( attachment.Type() != ATTACHMENT_WOODEN_LOG )
		//{
		//	if ( !HasBase() )
		//	{
		//		return false;
		//	}
		//}
		
		if ( attachment.IsInherited( ATTACHMENT_COMBINATION_LOCK ) )
		{
			return ( HasFullyConstructedGate() && !IsOpened() );
		}
		
		//GateAttachmentConditions check
		if ( !GateAttachmentConditions(slotId) )
			return false;
		
		return true;
	}
	
	#ifdef DAYZ_1_09
	override void OnPartBuiltServer( string part_name, int action_id )
	{
		ConstructionPart constrution_part = GetConstruction().GetConstructionPart( part_name );
		
		//super.OnPartBuiltServer( part_name, action_id );
		
		//check base state
		if ( constrution_part.IsBase() )
		{
			SetBaseState( true );
			
			//hide hologram
			SetAnimationPhase( "Hologram", 		1 );
			
			//spawn toolkit
			//CreateConstructionKit();
		}
		
		//check gate state
		//if ( constrution_part.IsGate() )
		//{
		//	SetGateState( true );
		//}
		
		//register constructed parts for synchronization
		RegisterPartForSync( constrution_part.GetId() );
		
		//register action that was performed on part
		RegisterActionForSync( constrution_part.GetId(), action_id );
		
		//synchronize
		SynchronizeBaseState();
		
		if (GetGame().IsMultiplayer() && GetGame().IsServer())
			SetPartFromSyncData(constrution_part); // server part of sync, client will be synced from SetPartsFromSyncData
		
		//reset action sync data
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( ResetActionSyncData, 100, false, this );
		
		//set gate state
		//SetGateState( CheckGateState() );
		
		//drop attachments without carrier part
		//if (constrution_part.IsGate())
			//GateAttachmentsSanityCheck();
		
		//update visuals (server)
		UpdateVisuals();
	}
	#else
	override void OnPartBuiltServer( notnull Man player, string part_name, int action_id )
	{
		ConstructionPart constrution_part = GetConstruction().GetConstructionPart( part_name );
		
		//super.OnPartBuiltServer( player, part_name, action_id );
		
		//check base state
		if ( constrution_part.IsBase() )
		{
			SetBaseState( true );
			
			//hide hologram
			SetAnimationPhase( "Hologram", 		1 );
			
			//spawn toolkit
			//CreateConstructionKit();
		}
		
		//check gate state
		//if ( constrution_part.IsGate() )
		//{
		//	SetGateState( true );
		//}
		
		//register constructed parts for synchronization
		RegisterPartForSync( constrution_part.GetId() );
		
		//register action that was performed on part
		RegisterActionForSync( constrution_part.GetId(), action_id );
		
		//synchronize
		SynchronizeBaseState();
		
		if (GetGame().IsMultiplayer() && GetGame().IsServer())
			SetPartFromSyncData(constrution_part); // server part of sync, client will be synced from SetPartsFromSyncData
		
		//reset action sync data
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( ResetActionSyncData, 100, false, this );
		
		//set gate state
		//SetGateState( CheckGateState() );
		
		//drop attachments without carrier part
		//if (constrution_part.IsGate())
			//GateAttachmentsSanityCheck();
		
		//update visuals (server)
		UpdateVisuals();
	}
	#endif
	
	override void OnPartDismantledServer( notnull Man player, string part_name, int action_id )
	{
		bsbDebugPrint("[bsb] " + GetDebugName(this) + " OnPartDismantledServer " + part_name);
		ConstructionPart constrution_part = GetConstruction().GetConstructionPart( part_name );
		
		//register constructed parts for synchronization
		UnregisterPartForSync( constrution_part.GetId() );
		
		//register action that was performed on part
		RegisterActionForSync( constrution_part.GetId(), action_id );
		
		//synchronize
		SynchronizeBaseState();

		// server part of sync, client will be synced from SetPartsFromSyncData
		SetPartFromSyncData( constrution_part );
		
		//reset action sync data
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( ResetActionSyncData, 100, false, this );
		
		//check base state
		if ( constrution_part.IsBase() )
		{
			//Destroy construction
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( DestroyConstruction, 200, false, this );
			
			//spawn toolkit
			CreateConstructionKit();
		}
		
		//check gate state
		//if( HasGatePart() )
		//{
		//	if ( constrution_part.IsGate() )
		//	{
		//		if ( IsLocked() )
		//		{
		//			CombinationLock combination_lock = CombinationLock.Cast( FindAttachmentBySlotName( ATTACHMENT_SLOT_COMBINATION_LOCK ) );
		//			combination_lock.UnlockServer( player , this );
		//		}
		//	}
		//}
		
		//super.OnPartDismantledServer( player, part_name, action_id );
		
		//set gate state
		//if( HasGatePart() )
		//{
		//	SetGateState( CheckGateState() );
		//}
		
		//update visuals (server)
		UpdateVisuals();
	}
	
	override void AfterStoreLoad()
	{	
		//super.AfterStoreLoad();
		//check base state
		if ( !HasBase() )
		{
			//show hologram
			float value = 0;
			SetAnimationPhase( "Hologram", 		value );
		}
		
		//update server data
		SetPartsFromSyncData();
		
		//set base state
		ConstructionPart construction_part = GetConstruction().GetBaseConstructionPart();
		SetBaseState( construction_part.IsBuilt() );
		
		//set gate state
		//ConstructionPart gate_part = GetConstruction().GetGateConstructionPart();
		//SetGateState( CheckGateState() );
		
		//update gate state visual
		if ( IsOpened() )
		{
			OpenFence();
		}
		
		UpdateVisuals();
		
		bsbDebugPrint("[bsb] AfterStoreLoad - build=" + "false" + " opened=" + IsOpened());
		
		//synchronize after load
		SynchronizeBaseState();
	}
	
	override void OpenFence()
	{	
		//client or single player
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			//play sound
			SoundGateOpenStart();
		}
	}

	override void CloseFence()
	{
		//client or single player
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			//play sound
			SoundGateCloseStart();
			
			//add check
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( CheckFenceClosed, 0, true );
		}
	}

	override void CheckFenceClosed()
	{
		if ( GetAnimationPhase( "Wall_Interact_Rotate" ) == 0 )			//animation closed
		{
			//play sound
			if ( this ) SoundGateCloseEnd();
			
			//remove check
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Remove( CheckFenceClosed );
		}
	}

	override void CreateAreaDamage( string slot_name, float rotation_angle = 0 )
    {
        if ( IsOpened() )
        {
            rotation_angle = 0;
        }
        
        super.CreateAreaDamage( slot_name, rotation_angle );
    }
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionFoldBaseBuildingObject);
		///////////////////////////////////////
		RemoveAction(ActionDialCombinationLockOnTarget);
		RemoveAction(ActionNextCombinationLockDialOnTarget);
		RemoveAction(ActionOpenFence);
		RemoveAction(ActionCloseFence);
	}
};
 */
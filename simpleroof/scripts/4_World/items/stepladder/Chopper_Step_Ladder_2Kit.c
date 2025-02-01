class Chopper_Step_Ladder_2Kit extends Chopper_BaseKit
{	
	ref protected EffectSound 		m_DeployLoopSound;
	protected Object				m_Object;
	
	void Chopper_Step_Ladder_2Kit()
	{
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
	}
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		if (IsDeploySound())
		{
			PlayDeploySound();
		}
		
		if (CanPlayDeployLoopSound())
		{
			PlayDeployLoopSound();
		}
		
		if (m_DeployLoopSound && !CanPlayDeployLoopSound())
		{
			StopDeployLoopSound();
		}
	}
	
    override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
    }
	
	//================================================================
	// ADVANCED PLACEMENT
	//================================================================			
		
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		if ( GetGame().IsServer() )
		{
			Chopper_Step_Ladder_2 chopperstepladder = Chopper_Step_Ladder_2.Cast( GetGame().CreateObjectEx( "Chopper_Step_Ladder_2", position, ECE_PLACE_ON_SURFACE ) );
			chopperstepladder.SetPosition( position );
			chopperstepladder.SetOrientation( orientation );
			//make the kit invisible, so it can be destroyed from deploy UA when action ends
			HideAllSelections();
			SetIsDeploySound( true );
			//snappingEnabledSE = false;
		}
	}
	
	override bool IsDeployable()
	{
		return true;
	}
	
	override string GetDeploySoundset()
	{
		return "putDown_FenceKit_SoundSet";
	}
	
	override string GetLoopDeploySoundset()
	{
		return "BarbedWire_Deploy_loop_SoundSet";
	}
	
	void PlayDeployLoopSound()
	{		
		if (GetGame().IsMultiplayer() && GetGame().IsClient() || !GetGame().IsMultiplayer())
		{		
			m_DeployLoopSound = SEffectManager.PlaySound(GetLoopDeploySoundset(), GetPosition());
		}
	}
	
	void StopDeployLoopSound()
	{
		if (GetGame().IsMultiplayer() && GetGame().IsClient() || !GetGame().IsMultiplayer())
		{	
			m_DeployLoopSound.SoundStop();
			delete m_DeployLoopSound;
		}
	}
}

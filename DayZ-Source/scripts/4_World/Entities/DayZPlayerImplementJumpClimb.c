class DayZPlayerImplementJumpClimb
{
	bool m_bIsJumpInProgress;	
	
	private DayZPlayerImplement m_Player;
	private bool m_bWasClimb;

	void DayZPlayerImplementJumpClimb(DayZPlayerImplement pPlayer)
	{
		m_Player = pPlayer;
	}

	//! Only valid immediately after 'JumpOrClimb' is called
	bool WasSuccessful()
	{
		return m_bIsJumpInProgress || m_bWasClimb;
	}
	
	//! Can't change to bool return
	void JumpOrClimb()
	{
		//! Reset states
		m_bWasClimb = false;

		//! Early exit if the player is being heavy damaged so the stagger animation can't be skipped
		if (m_Player.IsInFullbodyDamageAnimation())
			return;

		SHumanCommandClimbSettings hcls = m_Player.GetDayZPlayerType().CommandClimbSettingsW();
		
		if (m_Player.m_MovementState.m_iMovement != DayZPlayerConstants.MOVEMENTIDX_IDLE)
			hcls.m_fFwMaxDistance = 2.5;
		else
			hcls.m_fFwMaxDistance = 1.2;
		
		if (m_Player.m_MovementState.m_CommandTypeId == DayZPlayerConstants.COMMANDID_SWIM)
			hcls.m_fBackwardsCheckDist = 0.35;
		else
			hcls.m_fBackwardsCheckDist = 0;
		
		SHumanCommandClimbResult climbRes = new SHumanCommandClimbResult();
		
		HumanCommandClimb.DoPerformClimbTest(m_Player, climbRes, 0);
		if (climbRes.m_bIsClimb || climbRes.m_bIsClimbOver)
		{
			int climbType = GetClimbType(climbRes.m_fClimbHeight);
			if (!m_Player.CanClimb(climbType, climbRes))
				return;

			if (Climb(climbRes))
			{
				if (climbType == 1)
					m_Player.DepleteStamina(EStaminaModifiers.VAULT);
				else if (climbType == 2)
					m_Player.DepleteStamina(EStaminaModifiers.CLIMB);

				return;
			}
		}
		
		if (m_Player.CanJump())
		{
			Jump();
			m_Player.DepleteStamina(EStaminaModifiers.JUMP);
		}
	}
	
	void CheckAndFinishJump(int pLandType = 0)
	{
		if ( m_bIsJumpInProgress )
		{
			m_bIsJumpInProgress = false;
			m_Player.OnJumpEnd(pLandType);
		}
	}
	
	private bool Climb(SHumanCommandClimbResult pClimbRes)
	{
		int climbType = GetClimbType(pClimbRes.m_fClimbHeight);	
		if (climbType != -1)
		{
			m_Player.StartCommand_Climb(pClimbRes, climbType);
			m_Player.StopHandEvent();

			m_bWasClimb = true;
		}
		
		return climbType != -1;
	}
	
	private void Jump()
	{
		m_bIsJumpInProgress = true;
		m_Player.SetFallYDiff(m_Player.PhysicsGetPositionWS()[1]);

		m_Player.OnJumpStart();
		m_Player.StartCommand_Fall(2.6);
		m_Player.StopHandEvent();
	}
	
	private int GetClimbType(float pHeight)
	{
		int climbType = -1;
        if (pHeight < 1.1)
            climbType = 0;
        else if (pHeight >= 1.1 && pHeight < 1.7)
            climbType = 1;
        else if (pHeight >= 1.7 && pHeight < 2.75)
            climbType = 2;    
        
        return climbType;
	}
}

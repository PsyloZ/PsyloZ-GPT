class ActionToggleOpen: ActionInteractBase
{
	void ActionToggleOpen()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_HUDCursorIcon = CursorIcons.OpenDoors;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTCursor;
	}

	override bool CanBeUsedOnLadder()
	{
		return true;
	}
	
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		BaseBuilding_OpenableBase door = BaseBuilding_OpenableBase.Cast(target.GetObject());		
		if (!door) {
			return false;
		}

		BaseBuilding_HatchLadderBase hatch = BaseBuilding_HatchLadderBase.Cast(door);	
		if (hatch && hatch.IsOpen()) {
			BaseBuilding_Ladder_Memory m_Ladder = BaseBuilding_Ladder_Memory.Cast(hatch.GetLadderMemory());
			if (m_Ladder) {
				PlayerBase playerclimb = PlayerBase.Cast(m_Ladder.GetPlayer());
				if (m_Ladder && playerclimb && playerclimb.GetRAIsOnLadder()) {
					return false;
				}
			}
		}
		
		#ifndef SERVER
		if (door.IsCodeLocked(player.GetIdentity())) {
			return false;
		}
		
		if (door.GetAnimationPhase(door.GetOpenAnimation()) != 0 && door.GetAnimationPhase(door.GetOpenAnimation()) != 1) {
			return false;
		}
		
		m_Text = Ternary<string>.If(door.IsOpen(), "#close", "#open");
		#endif
		m_Sound = Ternary<string>.If(door.IsOpen(), door.GetCloseSounds().GetRandomElement(), door.GetOpenSounds().GetRandomElement());
		return true;
	}
	
	override void OnStartServer(ActionData action_data)
	{
		BaseBuilding_OpenableBase door = BaseBuilding_OpenableBase.Cast(action_data.m_Target.GetObject());	
		if (!door) {
			return;
		}

		PlayerBase player = PlayerBase.Cast(action_data.m_Player);
		if (!player) {
			return;
		}

		if (door.IsCodeLocked(player.GetIdentity())) {
			return;
		}

		door.SetOpened(!door.IsOpen());
		
		if (door.FindCodeLock()) {
			door.PlaySound("BeepSound", 0.3, false);
		}
	}
}


class ActionKnockBaseDoor: ActionInteractBase
{	
	void ActionKnockBaseDoor()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_Text = "Knock";
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTCursor;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		BaseBuilding_OpenableBase door = BaseBuilding_OpenableBase.Cast(target.GetObject());
		if (!door){
			return false;
		}

		#ifndef SERVER
		if (door.GetAnimationPhase(door.GetOpenAnimation()) != 0 && door.GetAnimationPhase(door.GetOpenAnimation()) != 1) {
			return false;
		}
		#endif

		m_Sound = Ternary<string>.If(door.GetMaterialLevel() == 2, "WoodenDoorKnock", "MetalDoorKnock");
		return true;
	}
};
modded class Hammer
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionUpgradeBase);
		AddAction(ActionRotateBase);
		AddAction(ActionRepairBase);
		
		AddAction(ActionDismantleBase);
	}
}

class RA_ClawHammer: Hammer
{
}


modded class ModItemRegisterCallbacks
{
	override void RegisterHeavy(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{
		super.RegisterHeavy(pType, pBehavior);
		
		pType.AddItemInHandsProfileIK("RA_BoxKit_Base", 	"dz/anims/workspaces/player/player_main/player_main_heavy.asi", 		pBehavior, 	"dz/anims/anm/player/ik/heavy/wooden_crate.anm");
	}

	override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{
		super.RegisterOneHanded(pType, pBehavior);
		pType.AddItemInHandsProfileIK("RA_ClawHammer", "dz/anims/workspaces/player/player_main/weapons/player_main_1h_pipe.asi", pBehavior,	"dz/anims/anm/player/ik/gear/hammer_ik.anm");
		pType.AddItemInHandsProfileIK("RA_Blueprint", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior,	"dz/anims/anm/player/ik/gear/Map_chernarus.anm");
		pType.AddItemInHandsProfileIK("RA_C4", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, 	"dz/anims/anm/player/ik/gear/PersonalRadio.anm");
		pType.AddItemInHandsProfileIK("RA_Improvised_C4", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/protector_case.anm");
	}
}
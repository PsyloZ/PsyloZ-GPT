class ActionTerritoryAuthorize: ActionInteractBase
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!super.ActionCondition(player, target, item)) {
			return false;
		}
		
		TerritoryHQ hq = TerritoryHQ.Cast(target.GetObject());
		if (!hq) {
			return false;
		}

		RA_CodeLock code_lock = RA_CodeLock.Cast(hq.FindAttachmentBySlotName("CodeLock"));
		if (code_lock && code_lock.IsLocked() && !code_lock.IsAuthorized(player.GetIdentity())) {
			return false;
		}
		
		return (!hq.IsAuthorized(player));
	}
	
	override void OnEndServer(ActionData action_data)
	{
		super.OnEndServer(action_data);

		if(!IsInReach(action_data.m_Player, action_data.m_Target, 3)) return;	
		
		TerritoryHQ hq = TerritoryHQ.Cast(action_data.m_Target.GetObject());
		if (!hq) {
			return;
		}
		
		hq.AuthorizePlayer(action_data.m_Player);

		LogToCF(action_data.m_Player, "", "", "Authorized on " + hq.GetType() + " at " + hq.GetPosition());

		if (hq.HasMaxPlayers()) {
			LogToCF(action_data.m_Player, "", "", "Exceeded Auth Count at " + hq.GetPosition());
		}
	}
	
	override string GetText()
	{
		return "Authorize";
	}
}

class ActionAdminTerritoryAuthorize: ActionInteractBase
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!super.ActionCondition(player, target, item)) {
			return false;
		}
		
		TerritoryHQ hq = TerritoryHQ.Cast(target.GetObject());
		if (!hq) {
			return false;
		}
		
		#ifndef SERVER
		if (hq.FindCodeLock() == NULL) {
			return false;
		}

		//Check admin perms
		#ifdef AVPPAdminTools
		MissionBaseWorld mission = MissionBaseWorld.Cast(g_Game.GetMission());
		if (!mission || !mission.VPPAT_AdminToolsToggled())
			return false;
		#endif
		#endif
		
		return (!hq.IsAuthorized(player));
	}
	
	override void OnEndServer(ActionData action_data)
	{
		super.OnEndServer(action_data);

		#ifdef AVPPAdminTools
		string plainId = action_data.m_Player.GetIdentity().GetPlainId();
		if (!GetPermissionManager().VerifyPermission(plainId, "FreeCamera")) {
			return;
		}
		#endif
		
		TerritoryHQ hq = TerritoryHQ.Cast(action_data.m_Target.GetObject());
		if (!hq) {
			return;
		}
		
		hq.AuthorizePlayer(action_data.m_Player);

		LogToCF(action_data.m_Player, "", "", "Admin Authorized on " + hq.GetType() + " at " + hq.GetPosition());
	}
	
	override string GetText()
	{
		return "[ADMIN] AUTHORIZE";
	}
}
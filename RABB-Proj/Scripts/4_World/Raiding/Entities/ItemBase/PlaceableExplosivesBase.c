class PlaceableExplosivesBase: ItemBase
{
	protected ref EffectSound m_EffectSound;
    protected bool m_ArmState;

	void PlaceableExplosivesBase()
	{
        RegisterNetSyncVariableBool("m_ArmState");
	}

	void ~PlaceableExplosivesBase()
	{
		if (g_Game && g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY)) {
			g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(DoExplosion);
		}
		
		delete m_EffectSound;
	}

	// arm and disarm works fine here
	void SetArmState(bool state)
	{
		if (!g_Game.IsServer()) {
			Error("SetArmState must be called on server");
			return;
		}

		if (state) {
			g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(DoExplosion, GetArmDelay() * 1000);
		} else {
			g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(DoExplosion);
		}

		m_ArmState = state;
        SetSynchDirty();
	}

	float GetArmDelay()
	{
		return 58.0;
	}
	
	typename GetExplosiveType()
	{
		return ScriptedExplosion;
	}

	bool IsArmed()
	{
		return m_ArmState;
	}

	override bool CanPutInCargo(EntityAI parent)
	{
		return !IsArmed();
	}

	override bool CanPutIntoHands(EntityAI parent)
	{
		return !IsArmed();
	}
	
	protected void DoExplosion()
	{
		if (!GetExplosiveType().IsInherited(ScriptedExplosion)) {
			Error("GetExplosiveType must inherit from ScriptedExplosion");
			return;
		}
		
		ScriptedExplosion scripted_explosion = ScriptedExplosion.Cast(g_Game.CreateObjectEx(GetExplosiveType().ToString(), GetPosition(), ECE_NONE));
		scripted_explosion.DoExplosion(this);
		g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(Delete, 100);
	}
	
	override bool CanPlaceInEnemyTerritory()
	{
		return true;
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionArmAndPlaceC4);
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionToggleArmExplosive);
		
		RemoveAction(ActionTakeItem);
	}
		
	override void OnVariablesSynchronized()
	{
		#ifndef SERVER
		if (m_EffectSound) {
			delete m_EffectSound;
		}
		
		if (m_ArmState && !m_EffectSound) {
			m_EffectSound = SEffectManager.PlaySound("C4_Beep_SoundSet", GetPosition());
		}
		#endif
	}

	override void OnPlacementComplete(Man player, vector position = "0 0 0", vector orientation = "0 0 0")
	{
		super.OnPlacementComplete(player, position, orientation);
		
		if (g_Game.IsServer()) {
			LogToCF(player, "", "", string.Format("Placed %1 at pos: %2 utc: %3", GetType(), position.ToString(), CF_Date.Now(true).DateToString()));
		}
	}
}

static void LogToCF(Man player, string item, string target, string action)
{
#ifdef GameLabs
	if (!GetGameLabs() || g_Game.IsClient()) {
		return;
	}
	
	_LogPlayer log_player = new _LogPlayer();

	PlayerBase pb = PlayerBase.Cast(player);
	
	if (!player || !pb) {
		return;
	}

	#ifdef REARMED_SERVER
	if (player.GetIdentity()) {
		log_player.id = player.GetIdentity().GetPlainId();
	}
	else {
		log_player.id = pb.GetLastKnownIdentity();
	}
	#else
	if (player.GetIdentity()) {
		log_player.id = player.GetIdentity().GetPlainId();
	}
	else {
		return;
	}
	#endif

	log_player.position = player.GetPosition();
	log_player.blood =  player.GetHealth("GlobalHealth", "Blood");
	log_player.health = player.GetHealth("GlobalHealth","Health");

	GetGameLabs().GetApi().ItemInteract(new _Callback(), new _Payload_ItemInteract(log_player, item, target, action));
#endif
}
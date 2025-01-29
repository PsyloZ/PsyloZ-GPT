enum CodeLockState 
{
	PENDING = 0, // Default on placement
	UNLOCKED = 1,
	LOCKED = 2
};

class RA_CodeLock: ItemBase
{
	static const int SLOT = InventorySlots.GetSlotIdFromString("CodeLock");
	
	static const int CODE_LENGTH = 4;
	
	static const int RPC_UPDATE_DATA = 235928;
	static const int RPC_TRY_AUTHENTICATE = 235929;
	static const int RPC_TRY_AUTHENTICATE_CALLBACK = 235930;
	static const int RPC_SET_CODE = 235931;
	static const int RPC_SET_STATE = 235932;
	
	protected CodeLockState m_CodeLockState;
	protected ref array<string> m_AuthorizationList = {};
	
	// Server only
	protected string m_Code;
	
	// Client only
	
	//@ arg0: CodeLock this
	//@ arg1: bool success
	protected ref ScriptCaller m_TryAuthorizeCallback;
	protected ref CodeLockViewMenu m_CodeLockViewMenu;
	
	void RA_CodeLock()
	{
		RegisterNetSyncVariableInt("m_CodeLockState", 0, 3);
		
#ifndef SERVER
#ifdef DIAG_DEVELOPER
		//g_Game.GetUpdateQueue(CALL_CATEGORY_GUI).Insert(DiagUpdate);
#endif
#endif
	}

	void ~RA_CodeLock()
	{
		delete m_TryAuthorizeCallback;
		delete m_CodeLockViewMenu;
	}
	
#ifdef DIAG_DEVELOPER
	void DiagUpdate(float dt)
	{
		string txt = string.Format("Authed: %1", IsAuthorized(g_Game.GetPlayer().GetIdentity()));
	//Re enable for Auth List readout (Too cluttered and in the way but good for finding bases for inspect/testing)
	/*	foreach (string authed_user: m_AuthorizationList) {
			txt += "\n" + authed_user;
		}
	*/	
		DayZPlayerUtils.DrawDebugText(txt, GetPosition(), 1);
	}
#endif
	
	override bool NameOverride(out string output)
	{
		if (m_CodeLockState == CodeLockState.PENDING) {
			return false;
		}
		
		string display_name = ConfigGetString("displayName");
		output = string.Format("%1 [%2]", display_name, typename.EnumToString(CodeLockState, m_CodeLockState));
		return true;
	}
	
	override void EEInit()
	{
		super.EEInit();
		
		// Request data update
		if (!g_Game.IsDedicatedServer()) {
			ScriptRPC().Send(this, RPC_UPDATE_DATA, true);
		}
	}
		
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent, slot_id);
		
		if (g_Game.IsDedicatedServer()) {
			SetState(CodeLockState.PENDING);
		}
	}
	
	override bool EEOnDamageCalculated(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
    {
		return false;
	}
	
	//@ Todo: Abstract this out to core on dev, HQ uses the same system of extra data grab
	protected void SendUpdateData(PlayerIdentity identity = null)
	{
		if (!g_Game.IsDedicatedServer()) {
			return;
		}
				
		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(m_AuthorizationList);
		rpc.Send(this, RPC_UPDATE_DATA, true, identity);
	}
	
	protected void ReadUpdateData(ParamsReadContext ctx)
	{
		if (g_Game.IsDedicatedServer()) {
			return;
		}
		
		ctx.Read(m_AuthorizationList);
	}
	
	void OnAuthenticationSuccess(notnull PlayerIdentity identity)
	{
		AuthorizePlayer(identity);
	}
	
	void OnAuthenticationFailed(notnull PlayerIdentity identity)
	{
		// subtract some health on fail
		identity.GetPlayer().AddHealth("GlobalHealth", "Health", -7.5);
	}
	
	void AuthorizePlayer(notnull PlayerIdentity identity)
	{		
		m_AuthorizationList.Insert(identity.GetId());
		SendUpdateData();
	}
	
	void DeauthorizePlayer(notnull PlayerIdentity identity)
	{		
		m_AuthorizationList.RemoveItem(identity.GetId());
		SendUpdateData();
	}
	
	void ClearAuthorizations()
	{		
		m_AuthorizationList.Clear();
		SendUpdateData();
	}
	
	bool IsAuthorized(notnull PlayerIdentity identity)
	{
		if (!m_AuthorizationList) {
			return false;
		}
		
		return m_AuthorizationList.Find(identity.GetId()) != -1;
	}
	
	void SetState(CodeLockState state)
	{
		if (!g_Game.IsDedicatedServer()) {
			return;
		}
		
		m_CodeLockState = state;
		SetSynchDirty();
	}
	
	CodeLockState GetState()
	{
		return m_CodeLockState;
	}
		
	bool IsLocked()
	{
		return GetState() == CodeLockState.LOCKED;
	}

	bool IsUnlocked()
	{
		return GetState() == CodeLockState.UNLOCKED || GetState() == CodeLockState.PENDING;
	}
					// callback has 1 arg, success boolean
	void TryAuthorize(string code, ScriptCaller callback)
	{
		if (g_Game.IsDedicatedServer()) {
			return;
		}
		
		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(code);
		rpc.Send(this, RPC_TRY_AUTHENTICATE, true);
		
		m_TryAuthorizeCallback = callback;
	}
	
	void TrySetCode(string code)
	{
		if (g_Game.IsDedicatedServer()) {
			return;
		}
		
		if (m_CodeLockState != CodeLockState.PENDING) {
			return;
		}
		
		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(code);
		rpc.Send(this, RPC_SET_CODE, true);
	}
	
	void SetCode(string code, PlayerIdentity sender)
	{
		if (!g_Game.IsDedicatedServer()) {
			return;
		}
		
		if (m_CodeLockState != CodeLockState.PENDING) {
			if (sender) {
				Error("User attempted to set code non-pending lock " + sender.GetId());
			}
			
			return;
		}
		
		// Set code value, set locked
		m_Code = code;
		SetState(CodeLockState.LOCKED);
		
		// Clear all current authorizations, dont sync yet!!
		m_AuthorizationList.Clear();
		
		// auto-authenticate
		if (sender) {
			m_AuthorizationList.Insert(sender.GetId());
		}
						
		// finally sync (this was causing race conditions and breaking)
		SendUpdateData();
	}
		
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
		
		switch (rpc_type) {
			case RPC_UPDATE_DATA: {
				// server recieved a request for data, serialize and send
				if (g_Game.IsDedicatedServer()) {
					SendUpdateData(sender);
				}
				
				else {
					ReadUpdateData(ctx);
				}
				
				break;
			}
			
			case RPC_TRY_AUTHENTICATE: {
				if (!g_Game.IsDedicatedServer()) {
					break;
				}	
				
				string code;
				bool auth_success;				
				if (ctx.Read(code)) {
					auth_success = (code == m_Code);
				}

				ScriptRPC callback_rpc = new ScriptRPC();
				callback_rpc.Write(auth_success);
				callback_rpc.Send(this, RPC_TRY_AUTHENTICATE_CALLBACK, true, sender);
				
				if (auth_success) {
					OnAuthenticationSuccess(sender);
				} else {
					OnAuthenticationFailed(sender);
				}
				
				break;
			}
			
			case RPC_TRY_AUTHENTICATE_CALLBACK: {
				if (g_Game.IsDedicatedServer()) {
					break;
				}
				
				bool auth_success_cb;
				if (!ctx.Read(auth_success_cb)) {
					break;
				}
				
				if (m_TryAuthorizeCallback) {
					m_TryAuthorizeCallback.Invoke(this, auth_success_cb);
				}
				
				break;
			}
			
			case RPC_SET_CODE: {
				if (!g_Game.IsDedicatedServer()) {
					break;
				}
								
				string set_code;
				if (!ctx.Read(set_code)) {
					break;
				}
								
				SetCode(set_code, sender);
				break;
			}
			
			case RPC_SET_STATE: {
				if (!g_Game.IsDedicatedServer()) {
					break;
				}
				
				CodeLockState set_state;
				if (!ctx.Read(set_state)) {
					break;
				}
				
				if (!IsAuthorized(sender)) {
					Error("User attempted to set state while unauthorized " + sender.GetId());
					break;
				}
				
				SetState(set_state);
				break;
			}
		}
	}
	
	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);
		
		ctx.Write(m_CodeLockState);
		ctx.Write(m_AuthorizationList);
		ctx.Write(m_Code);
	}
	
	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{
		if (!super.OnStoreLoad(ctx, version)) {
			return false;
		}
		
		if (!ctx.Read(m_CodeLockState)) {
			return false;
		}
		
		if (!ctx.Read(m_AuthorizationList)) {
			return false;
		}
		
		if (!ctx.Read(m_Code)) {
			// failsafe if our code isnt saved properly. use the auth list as a fallback
			m_Code = string.Format("%1%2%3%4", Math.RandomInt(0, 9), Math.RandomInt(0, 9), Math.RandomInt(0, 9), Math.RandomInt(0, 9));
		}
		
		return true;
	}
	
	override void AfterStoreLoad()
	{
		super.AfterStoreLoad();
		
		SetSynchDirty();
	}
	
	override bool CanDetachAttachment(EntityAI parent)
	{
		return super.CanDetachAttachment(parent) && IsUnlocked();
	}
	
	override bool CanPutIntoHands(EntityAI parent)
	{
		return super.CanPutIntoHands(parent) && IsUnlocked();
	}
	
	override bool IsTakeable()
	{
		return IsUnlocked();
	}
	
	override void SetActions()
	{
		super.SetActions();

		RemoveAction(ActionTakeItemToHands);
		RemoveAction(ActionTakeItem);
		
		AddAction(ActionAttach);
		AddAction(ActionToggleOpenCodeLock);
		AddAction(ActionCodeLockSetCode);
		AddAction(ActionCodeLockAuthenticate);
		AddAction(ActionCodeLockUnlock);
		AddAction(ActionCodeLockLock);
		AddAction(ActionCodeLockReset);
	}
	
	// Client UI stuff
	CodeLockViewMenu OpenMenu(ScriptCaller complete_cb)
	{
#ifndef NO_GUI
		m_CodeLockViewMenu = new CodeLockViewMenu(this, complete_cb);
		return m_CodeLockViewMenu;
#endif
	}
	
	void CloseMenu()
	{
#ifndef NO_GUI		
		m_CodeLockViewMenu.Close();
#endif
	}
	
	CodeLockViewMenu GetMenu()
	{
		return m_CodeLockViewMenu;
	}
}
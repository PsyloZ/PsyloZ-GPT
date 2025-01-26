modded class ItemBase
{
	// Quick function, client and server, shows whether or not something is locked.
	//		if identity is not null, it will check the lock for remembered identities
	bool IsCodeLocked(PlayerIdentity identity = null)
	{
		RA_CodeLock code_lock = RA_CodeLock.Cast(FindCodeLock());
		if (!code_lock) {
			return false;
		}
		
		if (code_lock.GetState() != CodeLockState.LOCKED) {
			return false;
		}
		
		if (identity && code_lock.IsAuthorized(identity)) {
			return false;
		}
		
		return true;
	}
	
	RA_CodeLock FindCodeLock()
	{
		#ifdef REARMED_SERVER
		return RA_CodeLock.Cast(GetInventory().FindAttachment(RA_CodeLock.SLOT));
		#else
		RA_CodeLock code_lock;
		code_lock = RA_CodeLock.Cast(FindAttachmentBySlotName("CodeLock"));
		if (code_lock) {
			return code_lock;
		}
		code_lock = RA_CodeLock.Cast(FindAttachmentBySlotName("Att_CombinationLock"));
		if (code_lock) {
			return code_lock;
		}
		return NULL;
		#endif
	}
}
modded class PermissionManager
{
	void PermissionManager()
	{
		GetRPCManager().AddRPC("RPC_PermitManager", "PermitRABaseBuilding", this, SingeplayerExecutionType.Server);
	}

	void PermitRABaseBuilding(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
	{
		if( type == CallType.Server )
        {
			Param1<bool> data;

        	if (!ctx.Read(data))
        		return;

			bool state = data.param1;

			PlayerBase pb = GetPermissionManager().GetPlayerBaseByID(sender.GetPlainId());

			pb.SetAdminMode(state);
		}
	}
}
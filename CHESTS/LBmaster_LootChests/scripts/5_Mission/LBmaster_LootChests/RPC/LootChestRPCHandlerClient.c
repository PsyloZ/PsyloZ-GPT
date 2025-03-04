[RegisterLBRPCHandler(LBConverter.TypenameToString(LootChestRPCHandlerClient), LBRPCHandlerType.CLIENT)]
class LootChestRPCHandlerClient : LB_RPCHandler {
	
	static ref array<ref Param2<vector, vector>> positionList;

	void LootChestRPCHandlerClient() {
		RegisterRPC(LB_LC_RPCs.REQUEST_POSITIONS, ScriptCaller.Create(HandleStaticPositions));
	}

	void HandleStaticPositions(){
		ctx.Read(positionList);
		Print("Received " + positionList.Count() + " Positions");
	}
	
}
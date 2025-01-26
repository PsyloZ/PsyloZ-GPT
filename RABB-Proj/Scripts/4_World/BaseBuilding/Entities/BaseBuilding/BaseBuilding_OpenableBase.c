class BaseBuilding_OpenableBase: BaseBuilding
{
	override bool CanPermanentlyDismantle()
	{
		return (FindCodeLock() == NULL);
	}
	
	array<string> GetOpenSounds()
	{
		return {};
	}
	
	array<string> GetCloseSounds()
	{
		return {};
	}
	
	string GetOpenAnimation()
	{
		return "door";
	}
		
	void SetOpened(bool state)
	{
		if (!g_Game || !g_Game.IsServer()) {
			return;
		}

		SetAnimationPhase(GetOpenAnimation(), state);
		
		// Update pathgraph
		g_Game.UpdatePathgraphRegionByObject(this);
		g_Game.GetWorld().UpdatePathgraphDoorByAnimationSourceName(this, GetOpenAnimation());
	}
	
	override void Open()
	{
		SetOpened(true);
	}
	
	override void Close()
	{
		SetOpened(false);
	}
		
	override bool IsOpen()
	{
		return GetAnimationPhase(GetOpenAnimation()) > 0;
	}
	
	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);
		
		ctx.Write(IsOpen());
	}
	
	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{
		if (!super.OnStoreLoad(ctx, version)) {
			return false;
		}
		
		bool is_open;
		if (!ctx.Read(is_open)) {
			return false;
		}
		
		if(is_open == 1) {
			g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(SetOpened, 0, false, is_open);
		}
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionToggleOpen);
		AddAction(ActionKnockBaseDoor);
	}
}
class BaseBuilding_HatchLadderBase: BaseBuilding_OpenableBase
{
	protected BaseBuilding_Ladder_Memory m_Ladder;

	override void SetOpened(bool state)
	{
		super.SetOpened(state);

		HandleLadder(state);
	}

	BaseBuilding_Ladder_Memory GetLadderMemory()
	{
		return m_Ladder;
	}

	void HandleLadder(bool state)
	{
		if (!m_Ladder && state) {
			m_Ladder = BaseBuilding_Ladder_Memory.Cast(g_Game.CreateObjectEx("BaseBuilding_Ladder_Memory" , GetPosition(), ECE_SETUP | ECE_CREATEPHYSICS | ECE_NOLIFETIME));
			m_Ladder.SetOrientation(GetOrientation() + "180 0 0");
		}
		if (m_Ladder && !state) {
			PlayerBase player = PlayerBase.Cast(m_Ladder.GetPlayer());
			if (m_Ladder && player && player.GetRAIsOnLadder()) {
				return;
			}
			g_Game.ObjectDelete(m_Ladder);
		}
	}

	#ifdef SERVER
	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);

		if (IsOpen()) {
			PlayerBase player = PlayerBase.Cast(m_Ladder.GetPlayer());
			if (m_Ladder && player && player.GetRAIsOnLadder()) {
				return;
			}
		}
		
		g_Game.ObjectDelete(m_Ladder);
	}
	#endif

	override string GetOpenAnimation()
	{
		return "ladder_extend";
	}

	override float GetSmallRotationStep()
	{
		return 0.0;
	}
	
	override float GetLargeRotationStep()
	{
		return 90.0;
	}
	
	override bool IsOccupancyExclusive()
	{
		return true;
	}
}

class BaseBuilding_WoodHatchLadder: BaseBuilding_HatchLadderBase
{
	override array<string> GetOpenSounds()
	{
		return {"doorWoodSmallOpen_1","doorWoodSmallOpen_2","doorWoodSmallOpen_3","doorWoodSmallOpen_4"};
	}
	
	override array<string> GetCloseSounds()
	{
		return {"doorWoodSmallClose_1","doorWoodSmallClose_2","doorWoodSmallClose_3","doorWoodSmallClose_4","doorWoodSmallClose_5","doorWoodSmallClose_6","doorWoodSmallClose_7"};
	}
}

class BaseBuilding_MetalHatchLadder: BaseBuilding_HatchLadderBase
{
	override array<string> GetOpenSounds()
	{
		return {"doorMetalGateOpen_1", "doorMetalGateOpen_2"};
	}
	
	override array<string> GetCloseSounds()
	{
		return {"doorMetalGateClose_1", "doorMetalGateClose_2"};
	}
}

class BaseBuilding_VaultHatchLadder: BaseBuilding_HatchLadderBase
{
	override array<string> GetOpenSounds()
	{
		return {"doorMetalGateOpen_1", "doorMetalGateOpen_2"};
	}
	
	override array<string> GetCloseSounds()
	{
		return {"doorMetalGateClose_1", "doorMetalGateClose_2"};
	}
}

class BaseBuilding_Ladder_Memory: House
{
	protected PlayerBase m_Player;

	void SetPlayer(PlayerBase player)
	{
		if (!g_Game.IsServer()) {
			Error("SetLadder must be called on server");
			return;
		}

		m_Player = player;
		//SetSynchDirty();
	}

	PlayerBase GetPlayer()
	{
		return m_Player;
	}
};
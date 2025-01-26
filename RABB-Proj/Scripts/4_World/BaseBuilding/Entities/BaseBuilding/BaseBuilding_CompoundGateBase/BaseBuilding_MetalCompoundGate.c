class BaseBuilding_MetalCompoundGate: BaseBuilding_CompoundGateBase
{
	override array<string> GetCloseSounds()
	{
		return {"MetalCompoundGate_Open"};
	}
	
	override array<string> GetOpenSounds()
	{
		return {"MetalCompoundGate_Close"};
	}
}
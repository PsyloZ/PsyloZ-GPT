modded class TentBase
{
    override float GetCostToUpkeep()
	{
		return 0.00001;
	}
}

//barrel, seachest, wood crate, etc
modded class DeployableContainer_Base
{
    override float GetCostToUpkeep()
	{
		return 0.00001;
	}
}
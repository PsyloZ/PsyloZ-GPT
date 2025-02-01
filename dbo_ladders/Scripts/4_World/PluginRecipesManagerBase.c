modded class PluginRecipesManagerBase extends PluginBase
{	
	override void RegisterRecipies()
	{
		super.RegisterRecipies();				// Calling base RegisterRecipies()

		RegisterRecipe(new LadderRecipe);
		RegisterRecipe(new LadderRecipeL);
		RegisterRecipe(new LadderRecipePART);
		RegisterRecipe(new LadderRecipePT);
	//	UnregisterRecipe("CraftStoneKnife");	// Removing an existing recipe
	}
};
/**
 * ExpansionSettings.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2022 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class ExpansionSettings
{
	static ref ScriptInvoker SI_Airdrop = new ScriptInvoker();
	static ref ScriptInvoker SI_Mission = new ScriptInvoker();

	override void Init()
	{
		super.Init();

		Init(ExpansionAirdropSettings);
		Init(ExpansionMissionSettings);
	}

	ExpansionAirdropSettings GetAirdrop(bool checkLoaded = true)
	{
		return ExpansionAirdropSettings.Cast(Get(ExpansionAirdropSettings, checkLoaded));
	}

	ExpansionMissionSettings GetMission(bool checkLoaded = true)
	{
		return ExpansionMissionSettings.Cast(Get(ExpansionMissionSettings, checkLoaded));
	}
};

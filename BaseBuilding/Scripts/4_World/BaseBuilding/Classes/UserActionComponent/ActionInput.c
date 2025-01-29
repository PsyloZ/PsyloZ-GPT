class BlueprintChangeActionInput: NoIndicationActionInputBase
{
	void BlueprintChangeActionInput(PlayerBase player)
	{
		SetInput("UATempRaiseWeapon");
		m_InputType 		= ActionInputType.AIT_CONTINUOUS;
		m_Priority 			= 200;
		m_DetectFromItem 	= true;
		m_DetectFromTarget	= false;
		m_DetectFromPlayer	= false;
	}
}
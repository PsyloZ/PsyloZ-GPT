modded class DayZPlayerImplement
{	
	void OnRaiseChanged(bool state)
	{
	}
		
	private bool _isRaised;
	
	override bool ModCommandHandlerBefore(float pDt, int pCurrentCommandID, bool pCurrentCommandFinished)
	{		
		GetMovementState(m_MovementState);
		if (_isRaised != m_MovementState.IsRaised()) {
			_isRaised = m_MovementState.IsRaised();
			OnRaiseChanged(_isRaised);
		}
		
		return super.ModCommandHandlerBefore(pDt, pCurrentCommandID, pCurrentCommandFinished);
	}
}
class CodeLockViewMenu: ScriptViewMenu
{
	protected CodeLockViewController m_TemplateController;
	CodeLockViewController GetTemplateContoller()
	{
		return m_TemplateController;
	}

	//@ arg0: CodeLock code_lock
	//@ arg2: string code
	protected ref ScriptCaller m_Callback;
	
	protected RA_CodeLock m_CodeLock;
	TextWidget Readout;
		
	void CodeLockViewMenu(RA_CodeLock code_lock, ScriptCaller callback)
	{
		m_CodeLock = code_lock;
		m_Callback = callback;
		
		m_TemplateController = CodeLockViewController.Cast(m_Controller);
	}
		
	override void OnMenuEnter(UIMenuPanel parent_panel)
	{
		super.OnMenuEnter(parent_panel);
		PPERequesterBank.GetRequester(PPERequesterBank.REQ_INVENTORYBLUR).Start();		
	}
	
	override void OnMenuExit(UIMenuPanel parent_panel)
	{
		super.OnMenuExit(parent_panel);
		PPERequesterBank.GetRequester(PPERequesterBank.REQ_INVENTORYBLUR).Stop();		
	}
	
	protected override void Update(float dt)
	{
		super.Update(dt);
		
		if (GetUApi().GetInputByID(UAUIBack).LocalPress()) {
			Close();
			return;
		}
		
		CodeLockKey current_key = CodeLockKey.GetCurrentKey(true);
		if (current_key != CodeLockKey.KEY_NONE) {
			EnterKey(current_key);
		}
	}
	
	protected void OnKeypadExecute(ButtonCommandArgs args)
	{
		// Enum value is stored in User id of button
		EnterKey(args.Source.GetUserID());
	}

	void EnterKey(CodeLockKey key)
	{
		switch (key) {
			case CodeLockKey.KEY_0: {
				m_TemplateController.Code += "0";
				break;
			}
			
			case CodeLockKey.KEY_1: {
				m_TemplateController.Code += "1";
				break;
			}
			
			case CodeLockKey.KEY_2: {
				m_TemplateController.Code += "2";
				break;
			}
			
			case CodeLockKey.KEY_3: {
				m_TemplateController.Code += "3";
				break;
			}
			
			case CodeLockKey.KEY_4: {
				m_TemplateController.Code += "4";
				break;
			}
			
			case CodeLockKey.KEY_5: {
				m_TemplateController.Code += "5";
				break;
			}
			
			case CodeLockKey.KEY_6: {
				m_TemplateController.Code += "6";
				break;
			}
			
			case CodeLockKey.KEY_7: {
				m_TemplateController.Code += "7";
				break;
			}
			
			case CodeLockKey.KEY_8: {
				m_TemplateController.Code += "8";
				break;
			}
			
			case CodeLockKey.KEY_9: {
				m_TemplateController.Code += "9";
				break;
			}
			
			case CodeLockKey.KEY_BACK: {
				m_TemplateController.Code = m_TemplateController.Code.Substring(0, m_TemplateController.Code.Length() - 1);
				break;
			}
			
			case CodeLockKey.KEY_CLEAR: {
				m_TemplateController.Code = string.Empty;
				break;
			}

			case CodeLockKey.KEY_NONE: 
			default: {
				return;
			}
		}
		
		SEffectManager.PlaySound("Beep_SoundSet", m_CodeLock.GetWorldPosition()).SetSoundAutodestroy(true);
		
		m_TemplateController.NotifyPropertyChanged("Code");
		if (m_TemplateController.Code.Length() >= RA_CodeLock.CODE_LENGTH) {
			m_Callback.Invoke(m_CodeLock, m_TemplateController.Code);
		}
	}
	
	void OnAuthenticationFailed()
	{
		WidgetAnimator.AnimateLoop(Readout, WidgetAnimatorProperty.POSITION_X, -5, 5, 50);
		g_Game.GetCallQueue(CALL_CATEGORY_GUI).CallLater(FinishAuthenticationFailedAnimation, 200);
	}
	
	protected void FinishAuthenticationFailedAnimation()
	{
		WidgetAnimator.CancelAnimate(Readout, WidgetAnimatorProperty.POSITION_X, true);
		m_TemplateController.Code = string.Empty;
		m_TemplateController.NotifyPropertyChanged("Code");
		
		EffectSound snd = SEffectManager.PlaySound("Beep_SoundSet", m_CodeLock.GetWorldPosition());
		snd.GetSoundObject().SetVolume(0.5);
		snd.GetSoundObject().SetFrequency(0.5);
		snd.SetSoundAutodestroy(true);
	}
	
	override bool UseMouse()
	{
		return true;
	}
	
	override array<string> GetInputExcludes()
	{
		return { "menu" };
	}
	
	override array<int> GetInputRestrictions()
	{
		return { UAWalkRunForced };
	}

	override string GetLayoutFile()
	{
		return "RA_BaseBuilding\\GUI\\layouts\\code_lock.layout";
	}
	
	override typename GetControllerType()
	{
		return CodeLockViewController;
	}
}
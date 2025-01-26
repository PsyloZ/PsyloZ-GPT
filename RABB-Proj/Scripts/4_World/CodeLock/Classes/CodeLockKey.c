typedef int CodeLockKey;
class CodeLockKey: int
{
	static const CodeLockKey KEY_NONE = -1;
	static const CodeLockKey KEY_0 = 0;
	static const CodeLockKey KEY_1 = 1;
	static const CodeLockKey KEY_2 = 2;
	static const CodeLockKey KEY_3 = 3;
	static const CodeLockKey KEY_4 = 4;
	static const CodeLockKey KEY_5 = 5;
	static const CodeLockKey KEY_6 = 6;
	static const CodeLockKey KEY_7 = 7;
	static const CodeLockKey KEY_8 = 8;
	static const CodeLockKey KEY_9 = 9;
	static const CodeLockKey KEY_BACK = 10;
	static const CodeLockKey KEY_CLEAR = 11;

	private void CodeLockKey();
	private void ~CodeLockKey();

	// Gets key pressed on current frame
	static CodeLockKey GetCurrentKey(bool consume = false)
	{
		map<int, CodeLockKey> key_codes = new map<int, CodeLockKey>();
		key_codes[KeyCode.KC_0] = KEY_0;
		key_codes[KeyCode.KC_1] = KEY_1;
		key_codes[KeyCode.KC_2] = KEY_2;
		key_codes[KeyCode.KC_3] = KEY_3;
		key_codes[KeyCode.KC_4] = KEY_4;
		key_codes[KeyCode.KC_5] = KEY_5;
		key_codes[KeyCode.KC_6] = KEY_6;
		key_codes[KeyCode.KC_7] = KEY_7;
		key_codes[KeyCode.KC_8] = KEY_8;
		key_codes[KeyCode.KC_9] = KEY_9;

		// Weirdo numpad owners
		key_codes[KeyCode.KC_NUMPAD0] = KEY_0;
		key_codes[KeyCode.KC_NUMPAD1] = KEY_1;
		key_codes[KeyCode.KC_NUMPAD2] = KEY_2;
		key_codes[KeyCode.KC_NUMPAD3] = KEY_3;
		key_codes[KeyCode.KC_NUMPAD4] = KEY_4;
		key_codes[KeyCode.KC_NUMPAD5] = KEY_5;
		key_codes[KeyCode.KC_NUMPAD6] = KEY_6;
		key_codes[KeyCode.KC_NUMPAD7] = KEY_7;
		key_codes[KeyCode.KC_NUMPAD8] = KEY_8;
		key_codes[KeyCode.KC_NUMPAD9] = KEY_9;

		// Misc
		key_codes[KeyCode.KC_DELETE] = KEY_CLEAR;
		key_codes[KeyCode.KC_BACK] = KEY_BACK;
		key_codes[KeyCode.KC_C] = KEY_CLEAR;
		
		foreach (int key_code, CodeLockKey code_lock_key: key_codes) {
			if (KeyState(key_code)) {
				if (consume) {
					ClearKey(key_code);
				}

				return code_lock_key;
			}
		}

		return KEY_NONE;
	}
}
class CodeLockViewController: ViewController
{
	string Code, ObfuscatedCode;
	
	override void PropertyChanged(string property_name)
	{
		switch (property_name) {
			case "Code": {
				ObfuscatedCode = string.Empty;
				for (int i = 0; i < Code.Length(); i++) {
					ObfuscatedCode += "*";
				}

				NotifyPropertyChanged("ObfuscatedCode");
				break;
			}
		}
	}
}
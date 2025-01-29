//@ Matches config defines
typedef int MaterialLevel;
class MaterialLevel: int
{
	static const int INVALID    = -1;
	static const int HOLOGRAM	= 0;
	static const int FRAME 		= 1;
	static const int WOOD 		= 2;
	static const int METAL 		= 3;
	static const int CONCRETE = 4;

	string GetFormattedName()
	{
		switch (value) {
			case HOLOGRAM: return "Hologram";
			case FRAME: return "Frame";
			case WOOD: return "Wood";
			case METAL: return "Metal";
			case CONCRETE: return "Concrete";
		}

		return string.Empty;
	}
	
	static MaterialLevel FromString(string name)
	{
		name.ToLower();
		switch (name) {
			case "hologram": return HOLOGRAM;
			case "frame": return FRAME;
			case "wood": return WOOD;
			case "metal": return METAL;
			case "concrete": return CONCRETE;
		}
		
		return INVALID;
	}
}
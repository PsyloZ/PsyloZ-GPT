class LB_LC_ChestSpawnPos {

	vector pos; // x,y,z position of the chest (it's recommended to use the ingame admin menu to place the chests)
	vector dir; // yaw, pitch, roll (orientation) of the chest at this position

	static LB_LC_ChestSpawnPos Init(vector pos_, vector dir_) {
		LB_LC_ChestSpawnPos n = new LB_LC_ChestSpawnPos();
		n.pos = pos_;
		n.dir = dir_;
		return n;
	}
	
	string ToListString(int column) {
		return pos.ToString() + " (" + dir.ToString() + ")";
	}
	
}
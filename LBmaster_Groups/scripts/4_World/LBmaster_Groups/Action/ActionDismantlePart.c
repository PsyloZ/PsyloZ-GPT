#ifdef LBmaster_GroupDLCPlotpole
modded class ActionDismantlePart {

	override bool Can(PlayerBase player, ActionTarget target, ItemBase item, int condition_mask) {
		if (!super.Can(player, target, item, condition_mask))
			return false;
		int type = 2;

		#ifdef RA_BaseBuilding_Scripts
			TerritoryHQ flag = TerritoryHQ.Cast(target.GetObject());
		#else
			TerritoryFlag flag = TerritoryFlag.Cast(target.GetObject());
		#endif

		if (flag) {
			type = 5;
			if (vector.Distance(player.GetPosition(), flag.GetPosition()) > LBTerritoryConfig.Get.maxDistanceToDismantleFlag) {
				return false;
			}
		}
		return LBTerritoryConfig.Get.CanExecuteAction(player, target, type, item);
	}

	override protected bool DismantleCondition(PlayerBase player, ActionTarget target, ItemBase item, bool camera_check) {
		#ifdef RA_BaseBuilding_Scripts
			TerritoryHQ flag = TerritoryHQ.Cast(target.GetObject());
		#else
			TerritoryFlag flag = TerritoryFlag.Cast(target.GetObject());
			if (flag && LBTerritoryConfig.Get.allowDestroyWithFlagAttached) {
			flag.dismantleWorkaround = true;
			bool ok = super.DismantleCondition(player, target, item, camera_check);
			flag.dismantleWorkaround = false;
			return ok;
		}
		#endif	
			
		return super.DismantleCondition(player, target, item, camera_check);
	}

}
#endif
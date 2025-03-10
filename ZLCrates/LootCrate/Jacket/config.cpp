class CfgPatches
{
	class RA_Gear_Jackets
	{
		units[]=
		{
			"RA_Static_BomberJacket",
			"RA_Static_BomberJacket_2",
			"RA_Static_FireFighterJacket_2",
			"RA_Coat_Hook"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgVehicles
{
	class ZLandContainerBase;
	class RA_Static_BomberJacket: ZLandContainerBase
	{
		scope=2;
		displayName="Jacket";
		model="ZLCrates\LootCrate\Jacket\Bomber_Jacket.p3d";
		physLayer="item_large";
		class Cargo
		{
			itemsCargoSize[]={3,6};
			openable=1;
			allowOwnedCargoManipulation=1;
		};
	};
	class RA_Static_BomberJacket_2: RA_Static_BomberJacket
	{
		model="ZLCrates\LootCrate\Jacket\Bomber_Jacket_2.p3d";
	};
	class RA_Static_FireFighterJacket_2: RA_Static_BomberJacket
	{
		displayName="Fire Fighters Jacket";
		model="ZLCrates\LootCrate\Jacket\FireFighter_Jacket.p3d";
	};
	class HouseNoDestruct;
	class RA_Coat_Hook: HouseNoDestruct
	{
		scope=2;
		model="ZLCrates\LootCrate\Jacket\Coat_Hook.p3d";
	};
};

class CfgPatches
{
	class RA_BreachingCharge_C4
	{
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
		units[]=
		{
			"RA_C4"
		};
		ammo[]=
		{
			"C4_Explosive_Ammo"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class RA_C4: Inventory_Base
	{
		scope=2;
		displayName="$STR_RA_C4";
		descriptionShort="$STR_DES_RA_C4";
		model="RearmedServer\BaseBuilding\Tools\Explosives\C4\C4.p3d";
		rotationFlags=2;
		itemBehaviour=2;
		itemSize[]={3,3};
		weight=2000;
		inventorySlot[]={};
		slopeTolerance=0.5;
		alignHologramToTerain=1;
		yawPitchRollLimit[]={20,20,20};
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"RearmedServer\BaseBuilding\Tools\Explosives\C4\data\C4_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"RearmedServer\BaseBuilding\Tools\Explosives\C4\data\C4.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=10000;
				};
			};
		};
	};
};
class CfgAmmo
{
	class DefaultAmmo;
	class C4_Explosive_Ammo: DefaultAmmo
	{
		indirectHit=1;
		indirectHitRange=3;
		indirectHitRangeMultiplier=1e-07;
		explosive=1;
		typicalSpeed=3;
		initSpeed=3;
		simulation="shotShell";
		simulationStep=0.050000001;
		soundSetExplosion[]=
		{
			"Plastic_Explosion_SoundSet",
			"Plastic_Explosion_Tail_SoundSet"
		};
		class DamageApplied
		{
			type="FragGrenade";
			class Health
			{
				damage=300;
			};
			class Blood
			{
				damage=0;
			};
			class Shock
			{
				damage=100;
			};
		};
		class NoiseExplosion
		{
			strength=300;
			type="shot";
		};
	};
};

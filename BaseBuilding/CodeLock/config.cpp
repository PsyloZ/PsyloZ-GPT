class CfgPatches
{
	class Gear_CodeLock
	{
		units[]=
		{
			"RA_CodeLock"
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
	class Inventory_Base;
	class RA_CodeLock: Inventory_Base
	{
		scope=2;
		displayName="$STR_RA_CODELOCK";
		descriptionShort="$STR_DES_RA_CODELOCK";
		model="RearmedServer\BaseBuilding\CodeLock\CodeLock.p3d";
		hiddenSelections[]=
		{
			"display0",
			"display1",
			"display2",
			"display3",
			"display4",
			"display5",
			"green",
			"orange",
			"red"
		};
		itemSize[]={1,2};
		weight=400;
		inventorySlot[]=
		{
			"CodeLock",
			"Att_CombinationLock"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1500;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
			};
		};
		soundImpactType="metal";
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyCodeLock: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"CodeLock"
		};
		model="RearmedServer\BaseBuilding\CodeLock\CodeLock.p3d";
	};
};

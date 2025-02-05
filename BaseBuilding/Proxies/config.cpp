class CfgPatches
{
	class RA_BaseBuilding_Proxies
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class proxyUniversalLock: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"CodeLock"
		};
		model="RearmedServer\BaseBuilding\Proxies\UniversalLock.p3d";
	};
};

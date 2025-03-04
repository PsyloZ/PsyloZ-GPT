class CfgPatches
{
	class ZLCrates
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Scripts"
		};
	};
};
class CfgMods
{
	class ZLCrates
	{
		dir="ZLCrates";
		picture="";
		action="";
		type="mod";
		dependencies[]=
		{
			"World"
		};
		class defs
		{
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"ZLCrates/Scripts/4_World"
				};
			};
		};
	};
};
class cfgvehicles
{
	class Inventory_Base;
};

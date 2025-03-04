class CfgMods
{
	class RaidLadder
	{
		dir="RaidLadder";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="RaidLadder";
		credits="";
		author="ZolysP";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"World",
			"Mission"
		};
		class defs
		{
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"RaidLadder/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"RaidLadder/scripts/5_Mission"
				};
			};
		};
	};
};

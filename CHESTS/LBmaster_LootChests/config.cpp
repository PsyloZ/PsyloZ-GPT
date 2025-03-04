class CfgPatches
{
	class LBmaster_LootChests
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"LBmaster_Core"};
	};
};

class CfgMods
{
	class LBmaster_LootChests
	{
		dir="LBmaster_LootChests";
		picture="";
		action="";
		hideName=0;
		hidePicture=1;
		name="LBmaster_LootChests";
		author="LBmaster";
		credits="LBmaster";
		authorID="0";
		version="1.0";
		type="mod";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"LBmaster_LootChests/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"LBmaster_LootChests/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"LBmaster_LootChests/scripts/5_Mission"
				};
			};
		};
	};
};

class CfgVehicles {
	
	class Container_Base;
	class Inventory_Base;
	class HouseNoDestruct;
	class LB_LC_Placeholder : HouseNoDestruct {
		scope = 1;
		model="\LBmaster_LootChestsItems\items\PlaceholderPlacement\Placeholder.p3d";
	};
	class LB_LC_KeyBase : Inventory_Base {
		scope=0;
		weight=100;
		class AnimEvents
		{
			class SoundWeapon
			{
				class lockpicker_move_in
				{
					soundSet="lockpicker_move_in_SoundSet";
					id=110202;
				};
				class lockpicker_move_out
				{
					soundSet="lockpicker_move_out_SoundSet";
					id=110203;
				};
				class lockpicker_loop
				{
					soundSet="lockpicker_loop_SoundSet";
					id=203;
				};
				class lockpicker_end
				{
					soundSet="lockpicker_end_SoundSet";
					id=110204;
				};
			};
		};
	};
	class LB_LC_Base : Container_Base {
		scope=0;
		itemsCargoSize[]={10,50};
		lbSpawnOffsetPos[] = {0,0,0}; // Used to correct model center point. This position is added to the position the item is spawned at. To move an item 0.5m down into the ground, you would use lbSpawnOffsetPos[] = {0,-0.5,0}; 
		lbSpawnOffsetDir[] = {0,0,0}; // Used to correct model rotation for example for 2d models rotated by 180 Degrees you can use lbSpawnOffsetDir[] = {-180,0,0};
	};
	class LB_LC_StashBase : LB_LC_Base {
		
	};
	class LB_LC_StashBarrelBase: LB_LC_StashBase
	{
		model="\dz\gear\containers\55galDrum.p3d";
		lbSpawnOffsetPos[] = {0,-0.65,0};
		hiddenSelections[]=
		{
			"camoGround"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=5000000;
				};
			};
		};
		class AnimationSources
		{
			class Lid
			{
				source="user";
				initPhase=0;
				animPeriod=0.01;
			};
			class Lid2
			{
				source="user";
				initPhase=1;
				animPeriod=0.01;
			};
		};
		soundImpactType="metal";
	};
	class LB_LC_StashPlastic: LB_LC_StashBase
	{
		scope=2;
		model="\LBmaster_LootChestsItems\items\LB_LC_Stash\stash.p3d";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=5000000;
				};
			};
		};
		class AnimationSources
		{
			class top_open
			{
				source="user";
				initPhase=1;
				animPeriod=0.01;
			};
			class top_closed
			{
				source="user";
				initPhase=0;
				animPeriod=0.01;
			};
		};
		soundImpactType="plastic";
	};
	class LB_LC_StashBarrelGreen : LB_LC_StashBarrelBase {
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\dz\gear\containers\data\barrel_green_co.paa"
		};
	};
	class LB_LC_StashBarrelBlue : LB_LC_StashBarrelBase {
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\dz\gear\containers\data\barrel_blue_co.paa"
		};
	};
	class LB_LC_StashBarrelRed : LB_LC_StashBarrelBase {
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\dz\gear\containers\data\barrel_red_co.paa"
		};
	};
	class LB_LC_StashBarrelYellow : LB_LC_StashBarrelBase {
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\dz\gear\containers\data\barrel_yellow_co.paa"
		};
	};
	class LB_LC_Safe_Base : LB_LC_Base {
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=5000000;
				};
			};
		};
	};
	class LB_LC_Safe_1 : LB_LC_Safe_Base {
		scope=2;
		model="\LBmaster_LootChestsItems\items\LB_LC_Safe\Safe1.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1.5;
			};
			class bolts
			{
				source="user";
				initPhase=0;
				animPeriod=1.5;
			};
			class lock_lever
			{
				source="user";
				initPhase=0;
				animPeriod=1.5;
			};
		};
	};
	class LB_LC_Safe_2 : LB_LC_Safe_Base {
		scope=2;
		model="\LBmaster_LootChestsItems\items\LB_LC_Safe\Safe2.p3d";
		class AnimationSources
		{
			class door
			{
				source="user";
				initPhase=0;
				animPeriod=1.5;
			};
			class bolts
			{
				source="user";
				initPhase=0;
				animPeriod=1.5;
			};
			class wheel_top
			{
				source="user";
				initPhase=0;
				animPeriod=1.5;
			};
			class wheel_bottom
			{
				source="user";
				initPhase=0;
				animPeriod=1.5;
			};
		};
	};
	class LB_LC_Military_Base : LB_LC_Base {
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=5000000;
				};
			};
		};
		class AnimationSources
		{
			class cover
			{
				source="user";
				initPhase=0;
				animPeriod=0.7;
			};
		};
	};
	class LB_LC_Military1_Green : LB_LC_Military_Base {
		scope=2;
		model="\LBmaster_LootChestsItems\items\LB_LC_Military\LB_LC_Military1.p3d";
	};
	class LB_LC_Military2_Green : LB_LC_Military_Base {
		scope=2;
		model="\LBmaster_LootChestsItems\items\LB_LC_Military\LB_LC_Military2.p3d";
	};
	class LB_LC_Military3_Green : LB_LC_Military_Base {
		scope=2;
		model="\LBmaster_LootChestsItems\items\LB_LC_Military\LB_LC_Military3.p3d";
	};
	class LB_LC_Military4_Green : LB_LC_Military_Base {
		scope=2;
		model="\LBmaster_LootChestsItems\items\LB_LC_Military\LB_LC_Military4.p3d";
	};
	class LB_LC_Military5_Green : LB_LC_Military_Base {
		scope=2;
		model="\LBmaster_LootChestsItems\items\LB_LC_Military\LB_LC_Military5.p3d";
	};
	class LB_LC_Wood1 : LB_LC_Military_Base {
		scope=2;
		model="\LBmaster_LootChestsItems\items\LB_LC_Military\LB_LC_Wood1.p3d";
	};
	class LB_LC_Military1_Sand : LB_LC_Military_Base {
		scope=2;
		model="\LBmaster_LootChestsItems\items\LB_LC_Military\LB_LC_Military1s.p3d";
	};
	class LB_LC_Military2_Sand : LB_LC_Military_Base {
		scope=2;
		model="\LBmaster_LootChestsItems\items\LB_LC_Military\LB_LC_Military2s.p3d";
	};
	class LB_LC_Military3_Sand : LB_LC_Military_Base {
		scope=2;
		model="\LBmaster_LootChestsItems\items\LB_LC_Military\LB_LC_Military3s.p3d";
	};
	class LB_LC_Military4_Sand : LB_LC_Military_Base {
		scope=2;
		model="\LBmaster_LootChestsItems\items\LB_LC_Military\LB_LC_Military4s.p3d";
	};
	class LB_LC_Military5_Sand : LB_LC_Military_Base {
		scope=2;
		model="\LBmaster_LootChestsItems\items\LB_LC_Military\LB_LC_Military5s.p3d";
	};
	class LB_LC_Military1_Black : LB_LC_Military_Base {
		scope=2;
		model="\LBmaster_LootChestsItems\items\LB_LC_Military\LB_LC_Military1b.p3d";
	};
	class LB_LC_Military2_Black : LB_LC_Military_Base {
		scope=2;
		model="\LBmaster_LootChestsItems\items\LB_LC_Military\LB_LC_Military2b.p3d";
	};
	class LB_LC_Military3_Black : LB_LC_Military_Base {
		scope=2;
		model="\LBmaster_LootChestsItems\items\LB_LC_Military\LB_LC_Military3b.p3d";
	};
	class LB_LC_Military4_Black : LB_LC_Military_Base {
		scope=2;
		model="\LBmaster_LootChestsItems\items\LB_LC_Military\LB_LC_Military4b.p3d";
	};
	class LB_LC_Military5_Black : LB_LC_Military_Base {
		scope=2;
		model="\LBmaster_LootChestsItems\items\LB_LC_Military\LB_LC_Military5b.p3d";
	};
	class LB_LC_KeyColorBase : LB_LC_KeyBase {
		hiddenSelections[]={
			"color"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							{
								"LBmaster_LootChestsItems\items\LB_LC_Keys\LB_LC_Keys_3.rvmat"
							}
						},
						{
							0.7,
							{
								"LBmaster_LootChestsItems\items\LB_LC_Keys\LB_LC_Keys_3.rvmat"
							}
						},
						{
							0.5,
							{
								"LBmaster_LootChestsItems\items\LB_LC_Keys\LB_LC_Keys_3_damage.rvmat"
							}
						},
						{
							0.3,
							{
								"LBmaster_LootChestsItems\items\LB_LC_Keys\LB_LC_Keys_3_damage.rvmat"
							}
						},
						{
							0,
							{
								"LBmaster_LootChestsItems\items\LB_LC_Keys\LB_LC_Keys_3_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class LB_LC_Key1_Red : LB_LC_KeyColorBase {
		scope=2;
		hiddenSelectionsTextures[]={
            "#(rgb,8,8,3)color(0.9098039,0.078431375,0.08627451,1)"
		};
		model="\LBmaster_LootChestsItems\items\LB_LC_Keys\key_red_1.p3d";
	};
	class LB_LC_Key2_Red : LB_LC_KeyColorBase {
		scope=2;
		hiddenSelectionsTextures[]={
            "#(rgb,8,8,3)color(0.9098039,0.078431375,0.08627451,1)"
		};
		model="\LBmaster_LootChestsItems\items\LB_LC_Keys\key_red_2.p3d";
	};
	class LB_LC_Key1_Orange : LB_LC_KeyColorBase {
		scope=2;
		hiddenSelectionsTextures[]={
            "#(rgb,8,8,3)color(1.0,0.64705884,0.0,1)"
		};
		model="\LBmaster_LootChestsItems\items\LB_LC_Keys\key_red_1.p3d";
	};
	class LB_LC_Key2_Orange : LB_LC_KeyColorBase {
		scope=2;
		hiddenSelectionsTextures[]={
            "#(rgb,8,8,3)color(1.0,0.64705884,0.0,1)"
		};
		model="\LBmaster_LootChestsItems\items\LB_LC_Keys\key_red_2.p3d";
	};
	class LB_LC_Key1_Yellow : LB_LC_KeyColorBase {
		scope=2;
		hiddenSelectionsTextures[]={
            "#(rgb,8,8,3)color(0.98039216,0.92156863,0.21176471,1)"
		};
		model="\LBmaster_LootChestsItems\items\LB_LC_Keys\key_red_1.p3d";
	};
	class LB_LC_Key2_Yellow : LB_LC_KeyColorBase {
		scope=2;
		hiddenSelectionsTextures[]={
            "#(rgb,8,8,3)color(0.98039216,0.92156863,0.21176471,1)"
		};
		model="\LBmaster_LootChestsItems\items\LB_LC_Keys\key_red_2.p3d";
	};
	class LB_LC_Key1_Green : LB_LC_KeyColorBase {
		scope=2;
		hiddenSelectionsTextures[]={
            "#(rgb,8,8,3)color(0.4745098,0.7647059,0.078431375,1)"
		};
		model="\LBmaster_LootChestsItems\items\LB_LC_Keys\key_red_1.p3d";
	};
	class LB_LC_Key2_Green : LB_LC_KeyColorBase {
		scope=2;
		hiddenSelectionsTextures[]={
            "#(rgb,8,8,3)color(0.4745098,0.7647059,0.078431375,1)"
		};
		model="\LBmaster_LootChestsItems\items\LB_LC_Keys\key_red_2.p3d";
	};
	class LB_LC_Key1_Blue : LB_LC_KeyColorBase {
		scope=2;
		hiddenSelectionsTextures[]={
            "#(rgb,8,8,3)color(0.28235295,0.49019608,0.90588236,1)"
		};
		model="\LBmaster_LootChestsItems\items\LB_LC_Keys\key_red_1.p3d";
	};
	class LB_LC_Key2_Blue : LB_LC_KeyColorBase {
		scope=2;
		hiddenSelectionsTextures[]={
            "#(rgb,8,8,3)color(0.28235295,0.49019608,0.90588236,1)"
		};
		model="\LBmaster_LootChestsItems\items\LB_LC_Keys\key_red_2.p3d";
	};
	class LB_LC_Key1_Violet : LB_LC_KeyColorBase {
		scope=2;
		hiddenSelectionsTextures[]={
            "#(rgb,8,8,3)color(0.4392157,0.21176471,0.6156863,1)"
		};
		model="\LBmaster_LootChestsItems\items\LB_LC_Keys\key_red_1.p3d";
	};
	class LB_LC_Key2_Violet : LB_LC_KeyColorBase {
		scope=2;
		hiddenSelectionsTextures[]={
            "#(rgb,8,8,3)color(0.4392157,0.21176471,0.6156863,1)"
		};
		model="\LBmaster_LootChestsItems\items\LB_LC_Keys\key_red_2.p3d";
	};
	class LB_LC_Key1_White : LB_LC_KeyColorBase {
		scope=2;
		hiddenSelectionsTextures[]={
            "#(rgb,8,8,3)color(1,1,1,1)"
		};
		model="\LBmaster_LootChestsItems\items\LB_LC_Keys\key_red_1.p3d";
	};
	class LB_LC_Key2_White : LB_LC_KeyColorBase {
		scope=2;
		hiddenSelectionsTextures[]={
            "#(rgb,8,8,3)color(1,1,1,1)"
		};
		model="\LBmaster_LootChestsItems\items\LB_LC_Keys\key_red_2.p3d";
	};
	class LB_LC_Key1_Grey : LB_LC_KeyColorBase {
		scope=2;
		hiddenSelectionsTextures[]={
            "#(rgb,8,8,3)color(0.5,0.5,0.5,1)"
		};
		model="\LBmaster_LootChestsItems\items\LB_LC_Keys\key_red_1.p3d";
	};
	class LB_LC_Key2_Grey : LB_LC_KeyColorBase {
		scope=2;
		hiddenSelectionsTextures[]={
            "#(rgb,8,8,3)color(0.5,0.5,0.5,1)"
		};
		model="\LBmaster_LootChestsItems\items\LB_LC_Keys\key_red_2.p3d";
	};
	class LB_LC_Key1_Black : LB_LC_KeyColorBase {
		scope=2;
		hiddenSelectionsTextures[]={
            "#(rgb,8,8,3)color(0,0,0,1)"
		};
		model="\LBmaster_LootChestsItems\items\LB_LC_Keys\key_red_1.p3d";
	};
	class LB_LC_Key2_Black : LB_LC_KeyColorBase {
		scope=2;
		hiddenSelectionsTextures[]={
            "#(rgb,8,8,3)color(0,0,0,1)"
		};
		model="\LBmaster_LootChestsItems\items\LB_LC_Keys\key_red_2.p3d";
	};
};
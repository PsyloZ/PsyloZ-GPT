class CfgPatches
{
	class Rearmed_BaseBuilding_Sounds
	{
		requiredAddons[]=
		{
			"DZ_Data"
		};
		units[]={};
		weapons[]={};
	};
};
class CfgSounds
{
	class WoodenDoorKnock
	{
		sound[]=
		{
			"\RearmedServer\BaseBuilding\Sounds\data\DoorKnock",
			12,
			1,
			30
		};
	};
	class MetalDoorKnock
	{
		sound[]=
		{
			"\RearmedServer\BaseBuilding\Sounds\data\MetalDoorKnock",
			15,
			1,
			30
		};
	};
	class BeepSound
	{
		sound[]=
		{
			"\RearmedServer\BaseBuilding\Sounds\data\Beep",
			1,
			1,
			30
		};
	};
	class MetalGarageDoorSound_Close
	{
		sound[]=
		{
			"\RearmedServer\BaseBuilding\Sounds\data\MetalGarageDoorSound_Close",
			1,
			1,
			30
		};
	};
	class MetalGarageDoorSound_Open
	{
		sound[]=
		{
			"\RearmedServer\BaseBuilding\Sounds\data\MetalGarageDoorSound_Open",
			1,
			1,
			30
		};
	};
	class MetalCompoundGate_Open
	{
		sound[]=
		{
			"\RearmedServer\BaseBuilding\Sounds\data\MetalCompoundGate_Open",
			2,
			1,
			30
		};
	};
	class MetalCompoundGate_Close
	{
		sound[]=
		{
			"\RearmedServer\BaseBuilding\Sounds\data\MetalCompoundGate_Close",
			2,
			1,
			30
		};
	};
};
class CfgSoundShaders
{
	class C4_Beep_SoundShader
	{
		samples[]=
		{
			
			{
				"RearmedServer\BaseBuilding\Sounds\data\C4_60Beep",
				1
			}
		};
		range=50;
		volume=2;
	};
};
class CfgSoundSets
{
	class C4_Beep_SoundSet
	{
		soundShaders[]=
		{
			"C4_Beep_SoundShader"
		};
	};
};

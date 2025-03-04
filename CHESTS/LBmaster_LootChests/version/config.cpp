class CfgPatches {
    class Advanced_Loot_Chests_Version {
        requiredVersion = 1.0;
        requiredAddons[] = {};
    };
};
class CfgMods {
    class Advanced_Loot_Chests_Version {
        dir="Advanced_Loot_Chests_Version";
        name="Advanced_Loot_Chests_Version";
        type="mod";
        dependencies[]=
        {
            "gamelib"
        };
        class defs
        {
            class gameLibScriptModule
            {
                value="";
                files[]=
                {
                    "LBmaster_LootChests/version/scripts"
                };
            };
        };
    };
};
class LBVersions {
    class LBmaster_LootChests {
        version= "1.1.1";
    };
};

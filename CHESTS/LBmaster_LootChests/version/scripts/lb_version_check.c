#ifndef LB_VERSION_CHECK
#define LB_VERSION_CHECK
string lb_version_list;
#endif
int lb_version_Advanced_Loot_Chests = lb_version_Advanced_Loot_Chests_();
int lb_version_Advanced_Loot_Chests_() {
    Print("Loaded Advanced Loot Chests (Client PBO) Version 1.1.1:stable");
    lb_version_list += "Advanced_Loot_Chests#1.1.1:stable;";
    return 0;
}
string lb_version2_Advanced_Loot_Chests = lb_version2_Advanced_Loot_Chests_();
string lb_version2_Advanced_Loot_Chests_() {
    #ifdef SERVER
    #ifndef DIAG
    #ifndef WORKBENCH
    string version = "None";
    int index = lb_version_list.IndexOf("Advanced_Loot_Chests_Server#");
    if (index == -1) {
        string mods = "NOT SET";
        string servermods = "NOT SET";
        if (GetCLIParam("mod", mods)) {
            mods = "-mod=" + mods;
        } else {
            mods = "-mod NOT SET";
        }
        if (GetCLIParam("servermod", servermods)) {
            servermods = "-servermod=" + servermods;
        } else {
            servermods = "-servermod NOT SET";
        }
        Print("" + mods);
        Print("" + servermods);
        Print("Advanced Loot Chests requires a Serverside PBO ! If you bought the product, download the latest version from https://lbmaster.de/download/index.php?p=43 or buy it from https://lbmaster.de/product.php?id=43 Make sure the Server PBO is properly loaded and check if the -mod and -servermod parameter are setup properly or the Server PBO is added to the Addons folder of your DayZ Server. Do not upload it to the steam workshop !");
        Error2("LBmaster Version Check", "Advanced Loot Chests requires a Serverside PBO ! If you bought the product, download the latest version from https://lbmaster.de/download/index.php?p=43 or buy it from https://lbmaster.de/product.php?id=43 Make sure the Server PBO is properly loaded and check if the -mod and -servermod parameter are setup properly or the Server PBO is added to the Addons folder of your DayZ Server. Do not upload it to the steam workshop !");
        int i = 7 % (1 - 1);
    }
    #endif
    #endif
    #endif
    return "";
}


#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <string>

#define MODE_SAVE 0
#define MODE_LOAD 1

static std::string g_REDTMPPath = "%userprofile%\\Documents\\Commandos - Beyond the call of duty\\OUTPUT\\REDTMP";
static std::string g_savesPath = "saves\\";
static std::string g_InfoFileName = "Info.dat";

constexpr int g_CharactersOfFileInfoPerFileSave = 10;

#endif //CONSTANTS_H
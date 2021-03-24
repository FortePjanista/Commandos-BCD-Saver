#ifndef DIRECTORIES_HANDLER_H
#define DIRECTORIES_HANDLER_H

#include <string>

class DirectoriesHandler
{
private:
	DirectoriesHandler() {};
public:
	static DirectoriesHandler& GetInstance();

	DirectoriesHandler(const DirectoriesHandler& other) = delete;
	DirectoriesHandler& operator= (const DirectoriesHandler& other) = delete;

public:
	std::string g_REDTMPPath = "%userprofile%\\Documents\\Commandos - Beyond the call of duty\\OUTPUT\\REDTMP";
	std::string g_savesPath = "saves\\";
	std::string g_InfoFileName = "Info.dat";
};

#endif // DIRECTORIES_HANDLER_H
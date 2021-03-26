#include "pathsHandler.h"

#include <cstdlib> // getenv()

// Disables getenv("USERPROFILE") warning
#pragma warning(disable : 4996)

using namespace boost::filesystem;

PathsHandler::PathsHandler():
	commandosUserDirectory(path(getenv("USERPROFILE")) / "Documents" / "Commandos - Beyond the call of duty/"),
	savesDirectory("saves/"),
	infoFileName("Info.dat")
{}

PathsHandler &PathsHandler::Get()
{
	static PathsHandler self;
	return self;
}

path PathsHandler::getSavePath(int id)
{
	return savesDirectory / std::string(std::to_string(id) + ".sav");
}

path PathsHandler::getREDTMPPath()
{
	return commandosUserDirectory / "OUTPUT" / "REDTMP";
}

path PathsHandler::getInfoFilePath()
{
	return savesDirectory / infoFileName;
}

path PathsHandler::getSavesDirectoryPath()
{
	return savesDirectory;
}

path PathsHandler::getCommandosUserDirectoryPath()
{
	return commandosUserDirectory;
}

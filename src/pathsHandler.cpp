#include "pathsHandler.h"

#include <stdlib.h> // getenv() -> deprecated, we use _dupenv_s instead

// Disables getenv("USERPROFILE") warning
#pragma warning(disable : 4996)

using namespace boost::filesystem;

PathsHandler::PathsHandler()
	: commandosUserDirectory( path(getenv("USERPROFILE")) / "Documents" / "Commandos - Beyond the call of duty/" ),
	savesDirectory("saves/"),
	infoFileName("Info.dat")
{}

PathsHandler & PathsHandler::Get()
{
	static PathsHandler self;
	return self;
}

path PathsHandler::getSavePath(int id)
{
	return savesDirectory / path(std::to_string(id) + ".sav");
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

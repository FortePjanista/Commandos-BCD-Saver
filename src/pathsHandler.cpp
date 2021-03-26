#include "pathsHandler.h"

#include <cstdlib> // getenv()

// Disables getenv("USERPROFILE") warning
#pragma warning(disable : 4996)

PathsHandler::PathsHandler():
	REDTMPPath(boost::filesystem::path(getenv("USERPROFILE")) / "Documents/Commandos - Beyond the call of duty/OUTPUT/REDTMP"),
	savesPath("saves/"),
	infoFileName("Info.dat")
{}

PathsHandler& PathsHandler::Get()
{
	static PathsHandler self;
	return self;
}

bool PathsHandler::IsCommandosInstalled()
{
	return boost::filesystem::is_directory(boost::filesystem::path(getenv("USERPROFILE")) / "Documents/Commandos - Beyond the call of duty/");
}

bool PathsHandler::DoesREDTMPExist()
{
	return boost::filesystem::exists(REDTMPPath);
}

boost::filesystem::path PathsHandler::getSavePath(int id)
{
	return boost::filesystem::path(savesPath / std::string(std::to_string(id) + ".sav"));
}

#include "pathsHandler.h"

#include <cstdlib> // getenv()

// Disables getenv("USERPROFILE") warning
#pragma warning(disable : 4996)

PathsHandler::PathsHandler():
	REDTMPPath(boost::filesystem::path(getenv("USERPROFILE")) / "Documents/Commandos - Beyond the call of duty/OUTPUT/REDTMP"),
	savesPath("saves/"),
	infoFileName("Info.dat")
{}

PathsHandler& PathsHandler::GetInstance()
{
	static PathsHandler self;
	return self;
}
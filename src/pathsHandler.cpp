#include "pathsHandler.h"

PathsHandler::PathsHandler():
	REDTMPPath("%userprofile%\\Documents\\Commandos - Beyond the call of duty\\OUTPUT\\REDTMP"),
	savesPath("saves\\"),
	infoFileName("Info.dat")
{}

PathsHandler& PathsHandler::GetInstance()
{
	static PathsHandler self;
	return self;
}
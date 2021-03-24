#include "directoriesHandler.h"

DirectoriesHandler& DirectoriesHandler::GetInstance()
{
	static DirectoriesHandler self;
	return self;
}
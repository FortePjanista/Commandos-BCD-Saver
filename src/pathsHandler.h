#ifndef DIRECTORIES_HANDLER_H
#define DIRECTORIES_HANDLER_H

#include <string>

class PathsHandler
{
private:
	PathsHandler();

public:
	static PathsHandler& GetInstance();
	PathsHandler(const PathsHandler& other) = delete;
	PathsHandler& operator= (const PathsHandler& other) = delete;

public:
	std::string REDTMPPath;
	std::string savesPath;
	std::string infoFileName;
};

#endif // DIRECTORIES_HANDLER_H
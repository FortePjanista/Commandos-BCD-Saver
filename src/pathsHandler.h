#ifndef DIRECTORIES_HANDLER_H
#define DIRECTORIES_HANDLER_H

#include <boost/filesystem.hpp>

class PathsHandler
{
private:
	PathsHandler();

public:
	static PathsHandler& GetInstance();
	PathsHandler(const PathsHandler& other) = delete;
	PathsHandler& operator= (const PathsHandler& other) = delete;

public:
	boost::filesystem::path REDTMPPath;
	boost::filesystem::path savesPath;
	boost::filesystem::path infoFileName;
};

#endif // DIRECTORIES_HANDLER_H
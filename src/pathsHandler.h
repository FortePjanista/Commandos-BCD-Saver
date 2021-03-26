#ifndef DIRECTORIES_HANDLER_H
#define DIRECTORIES_HANDLER_H

#include <boost/filesystem.hpp>

class PathsHandler
{
public:
	static PathsHandler& Get();

	bool IsCommandosInstalled();
	bool DoesREDTMPExist();
	boost::filesystem::path getSavePath(int id);

	boost::filesystem::path REDTMPPath;
	boost::filesystem::path savesPath;
	boost::filesystem::path infoFileName;

	PathsHandler(const PathsHandler& other) = delete;
	PathsHandler& operator= (const PathsHandler& other) = delete;

private:
	PathsHandler();
};

#endif // DIRECTORIES_HANDLER_H
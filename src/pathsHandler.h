#ifndef DIRECTORIES_HANDLER_H
#define DIRECTORIES_HANDLER_H

#include <boost/filesystem.hpp>

class PathsHandler
{
public:
	static PathsHandler & Get();

	boost::filesystem::path getSavePath(int id);
	boost::filesystem::path getREDTMPPath();
	boost::filesystem::path getInfoFilePath();
	boost::filesystem::path getSavesDirectoryPath();
	boost::filesystem::path getCommandosUserDirectoryPath();

	PathsHandler(const PathsHandler & other) = delete;
	PathsHandler & operator= (const PathsHandler & other) = delete;

private:
	PathsHandler();

	boost::filesystem::path commandosUserDirectory;
	boost::filesystem::path savesDirectory;
	boost::filesystem::path infoFileName;
};

#endif // DIRECTORIES_HANDLER_H
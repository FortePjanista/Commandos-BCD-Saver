#ifndef SAVES_HANDLER_H
#define SAVES_HANDLER_H

#include "saveFile.h"
class SavesHandler
{
public:
	SavesHandler(int nrOfSaveFiles);

public:
	int saveFilesAmount;
	//std::array<std::unique_ptr<SaveFile>, SaveFilesCount> saveFiles;
	SaveFile ** saveFiles;
	std::string * info;

private:
	void loadInfoFromInfoFile();
	void saveInfoIntoInfoFile();
	bool isInfoFileCreated();
	void createEmptyInfoFile();

public:
	void loadInfoIntoSaveFiles();
	std::string getSaveFileInfo(int fileID);
	void save(int fileID, std::string newInfo);
	void load(int fileID);
};

#endif //SAVES_HANDLER_H
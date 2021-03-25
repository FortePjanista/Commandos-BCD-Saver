#ifndef SAVES_HANDLER_H
#define SAVES_HANDLER_H
#include "saveFile.h"

class SavesHandler
{
public:
	SavesHandler();

private:
	constexpr static int saveFilesAmount = SAVE_FILES_COUNT;
	std::unique_ptr<SaveFile> saveFiles[SAVE_FILES_COUNT];

	//Updates info file
	void saveNamesIntoInfoFile();

	//Retrieves names from info file and assigns them to respective save files
	void loadNamesFromInfoFileIntoSaveFiles();
public:
	std::string getSaveFileName(int fileID);
	void save(int fileID, const std::string &newName);
	void load(int fileID);
};

#endif //SAVES_HANDLER_H
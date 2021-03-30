#ifndef SAVES_HANDLER_H
#define SAVES_HANDLER_H

#include <memory>
#include <string>

#include "constants.h"
#include "saveFile.h"
class SavesHandler
{
public:
	SavesHandler();

	// Returns one of error_codes (constants.h)
	int save(int fileID, const std::string &newName);
	int load(int fileID);
	std::string getSaveFileName(int fileID);

private:
	constexpr static int saveFilesAmount = SAVE_FILES_COUNT;

	std::unique_ptr<SaveFile> saveFiles[SAVE_FILES_COUNT];

	// Updates info file
	void saveNamesIntoInfoFile();

	// Retrieves names from info file and assigns them to respective save files
	void loadNamesFromInfoFileIntoSaveFiles();
};

#endif // SAVES_HANDLER_H
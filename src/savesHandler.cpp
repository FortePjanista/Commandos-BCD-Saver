#include "savesHandler.h"
#include "pathsHandler.h"

using namespace boost::filesystem;

namespace
{
	bool isInfoFileCreated()
	{
		auto & paths = PathsHandler::Get();
		return exists(paths.getInfoFilePath());
	}

	void createEmptyInfoFile()
	{
		auto & paths = PathsHandler::Get();

		//Create "saves" folder if doesn't exist
		if (!exists(paths.getSavesDirectoryPath()))
			create_directory(paths.getSavesDirectoryPath());

		ofstream file;
		file.open(paths.getInfoFilePath());
		for (int i = 0; i < SAVE_FILES_COUNT; i++)
		{
			file << "Empty" << std::endl;
		}
		file.close();
	}
}

SavesHandler::SavesHandler()
{
	for (int i = 0; i < saveFilesAmount; i++)
	{
		saveFiles[i] = std::make_unique<SaveFile>(i, "Empty");
	}

	//Init directory and empty saves if not created yet (First app's launch)
	if (!isInfoFileCreated())
		createEmptyInfoFile();
	else
		loadNamesFromInfoFileIntoSaveFiles();
}

void SavesHandler::loadNamesFromInfoFileIntoSaveFiles()
{
	auto & paths = PathsHandler::Get();

	ifstream file;
	file.open(paths.getInfoFilePath());

	char buffer[256];
	for (int i = 0; i < saveFilesAmount; i++)
	{
		file.getline(buffer, 256);
		saveFiles[i]->setName(buffer);
	}
	file.close();
}

void SavesHandler::saveNamesIntoInfoFile()
{
	auto & paths = PathsHandler::Get();

	ofstream file;
	file.open(paths.getInfoFilePath());
	for (int i = 0; i < saveFilesAmount; i++)
	{
		file << saveFiles[i]->getName() << std::endl;
	}
	file.close();
}

std::string SavesHandler::getSaveFileName(int fileID)
{
	return saveFiles[fileID]->getName();
}

bool SavesHandler::save(int id, const std::string &newName)
{
	auto & paths = PathsHandler::Get();

	if (!exists(paths.getREDTMPPath())) return false;

	saveFiles[id]->save();
	saveFiles[id]->setName(newName);

	//update info file
	saveNamesIntoInfoFile();
	return true;
}

void SavesHandler::load(int id)
{
	saveFiles[id]->load();
}

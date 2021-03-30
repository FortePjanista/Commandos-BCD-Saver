#include "savesHandler.h"

#include "pathsHandler.h"

using namespace boost::filesystem;

namespace
{
	void InitInfoFile(const path & path, const std::string & defaultSaveName)
	{
		ofstream file(path);
		for (int i = 0; i < SAVE_FILES_COUNT; i++)
		{
			file << defaultSaveName << std::endl;
		}
		file.close();
	}
}

SavesHandler::SavesHandler()
{
	// Init SaveFile objects
	for (int i = 0; i < saveFilesAmount; i++)
	{
		saveFiles[i] = std::make_unique<SaveFile>(i, "Empty");
	}

	auto & paths = PathsHandler::Get();
	path infoFilePath = paths.getInfoFilePath();

	//Init directory and empty saves if not created yet (First app's launch for example)
	if (!exists(infoFilePath))
	{
		create_directory(paths.getSavesDirectoryPath());
		InitInfoFile(infoFilePath, "Empty");
	}
	else
	{
		// Update save file objects from info.dat
		loadNamesFromInfoFileIntoSaveFiles();
	}
}

void SavesHandler::loadNamesFromInfoFileIntoSaveFiles()
{
	auto & paths = PathsHandler::Get();

	std::string line;
	ifstream file(paths.getInfoFilePath());
	for (int i = 0; i < saveFilesAmount; i++)
	{
		std::getline(file, line);
		saveFiles[i]->setName(line);
	}
	file.close();
}

void SavesHandler::saveNamesIntoInfoFile()
{
	auto & paths = PathsHandler::Get();

	ofstream file(paths.getInfoFilePath());
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

int SavesHandler::save(int id, const std::string &newName)
{
	auto & paths = PathsHandler::Get();

	int result = saveFiles[id]->save();

	// Stop execution on error
	if (result != ERROR_SUCCESS)
		return result;

	// Update save file object on success
	saveFiles[id]->setName(newName);

	// Update info.dat on success
	saveNamesIntoInfoFile();

	return ERROR_SUCCESS;
}

int SavesHandler::load(int id)
{
	return saveFiles[id]->load();
}

#include "savesHandler.h"
#include "pathsHandler.h"

namespace
{
	bool isInfoFileCreated()
	{
		bool ret_value;
		auto& ph = PathsHandler::GetInstance();
		std::ifstream file;
		file.open(ph.savesPath + ph.infoFileName);
		ret_value = file.is_open();
		file.close();
		return ret_value;
	}

	void createEmptyInfoFile()
	{
		auto& ph = PathsHandler::GetInstance();
		//Creating a saves folder
		std::string command = "if not exist \"" + ph.savesPath + "\" mkdir \"" + ph.savesPath + "\"";
		system(command.c_str());

		std::ofstream file;
		file.open(ph.savesPath + ph.infoFileName, std::ofstream::out);

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

	if (!isInfoFileCreated())
		createEmptyInfoFile();
	else
		loadNamesFromInfoFileIntoSaveFiles();
}

void SavesHandler::loadNamesFromInfoFileIntoSaveFiles()
{
	auto& ph = PathsHandler::GetInstance();

	std::ifstream file;
	file.open(ph.savesPath + ph.infoFileName);

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
	auto& ph = PathsHandler::GetInstance();

	std::ofstream file;
	file.open(ph.savesPath + ph.infoFileName);
	for (int i = 0; i < saveFilesAmount; i++)
	{
		file << saveFiles[i]->getName() << std::endl;
	}
	file.close();
}

std::string SavesHandler::getSaveFileName(int _fileID)
{
	return saveFiles[_fileID]->getName();
}

void SavesHandler::save(int fileID, const std::string &newName)
{
	saveFiles[fileID]->save();

	saveFiles[fileID]->setName(newName);

	//update info file
	saveNamesIntoInfoFile();
}

void SavesHandler::load(int fileID)
{
	saveFiles[fileID]->load();
}

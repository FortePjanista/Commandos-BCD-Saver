#include "savesHandler.h"
#include "pathsHandler.h"

namespace fs = boost::filesystem;

namespace
{
	bool isInfoFileCreated()
	{
		auto &ph = PathsHandler::GetInstance();
		return fs::exists(ph.savesPath / ph.infoFileName);
	}

	void createEmptyInfoFile()
	{
		auto &ph = PathsHandler::GetInstance();

		//Create "saves" folder if doesn't exist
		if (!fs::exists(ph.savesPath))
			fs::create_directory(ph.savesPath);

		fs::ofstream file;
		file.open(ph.savesPath / ph.infoFileName);

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
	auto &ph = PathsHandler::GetInstance();

	fs::ifstream file;
	file.open(ph.savesPath / ph.infoFileName);

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
	auto &ph = PathsHandler::GetInstance();

	fs::ofstream file;
	file.open(ph.savesPath / ph.infoFileName);
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

bool SavesHandler::save(int fileID, const std::string &newName)
{
	auto &ph = PathsHandler::GetInstance();
	if (!ph.DoesREDTMPExist())
		return false;

	saveFiles[fileID]->save();

	saveFiles[fileID]->setName(newName);

	//update info file
	saveNamesIntoInfoFile();
	return true;
}

void SavesHandler::load(int fileID)
{
	saveFiles[fileID]->load();
}

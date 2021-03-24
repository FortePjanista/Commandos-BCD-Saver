#include "savesHandler.h"

SavesHandler::SavesHandler()
{
	for (int i = 0; i < saveFilesAmount; i++)
	{
		saveFiles[i] = std::make_unique<SaveFile>(i, "Empty");
	}

	for (int i = 0; i < saveFilesAmount; i++)
	{
		names[i] = "Empty";
	}
	if (!isInfoFileCreated())
		createEmptyInfoFile();
	else
		loadNamesIntoSaveFiles();
}

void SavesHandler::loadNamesFromInfoFile()
{
	std::ifstream file;
	file.open(g_savesPath + g_InfoFileName);

	char buffer[256];
	for (int i = 0; i < saveFilesAmount; i++)
	{
		file.getline(buffer, 256);
		names[i] = buffer;
	}
	file.close();
}

void SavesHandler::saveNamesIntoInfoFile()
{
	std::ofstream file;
	file.open(g_savesPath + g_InfoFileName);
	for (int i = 0; i < saveFilesAmount; i++)
	{
		file << names[i] << std::endl;
	}
	file.close();
}

bool SavesHandler::isInfoFileCreated()
{
	bool ret_value;
	std::ifstream file;
	file.open(g_savesPath + g_InfoFileName);
	ret_value = file.is_open();
	file.close();
	return ret_value;
}

void SavesHandler::loadNamesIntoSaveFiles()
{
	loadNamesFromInfoFile();
	for (int i = 0; i < saveFilesAmount; i++)
	{
		saveFiles[i]->setName(names[i]);
	}
}

std::string SavesHandler::getSaveFileName(int _fileID)
{
	return saveFiles[_fileID]->getName();
}

void SavesHandler::createEmptyInfoFile()
{
	//Creating a saves folder
	std::string command = "if not exist \"" + g_savesPath + "\" mkdir \"" + g_savesPath + "\"";
	system(command.c_str());

	std::ofstream file;
	file.open(g_savesPath + g_InfoFileName, std::ofstream::out);

	for (int i = 0; i < saveFilesAmount; i++)
	{
		file << "Empty" << std::endl;
	}
	file.close();
}

void SavesHandler::save(int fileID, std::string newName)
{
	saveFiles[fileID]->save();
	
	//set name
	names[fileID] = newName;

	//update info file
	saveNamesIntoInfoFile();

	//update save file local variable
	saveFiles[fileID]->setName(names[fileID]);
}

void SavesHandler::load(int fileID)
{
	saveFiles[fileID]->load();
}

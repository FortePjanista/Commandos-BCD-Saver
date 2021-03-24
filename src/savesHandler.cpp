#include "savesHandler.h"

SavesHandler::SavesHandler(int _nrOfSaveFiles)
{
	saveFilesAmount = _nrOfSaveFiles;
	saveFiles = saveFiles = new SaveFile * [saveFilesAmount];
	for (int i = 0; i < saveFilesAmount; i++)
	{
		saveFiles[i] = new SaveFile(i, "Empty");
	}

	info = new std::string[saveFilesAmount];
	for (int i = 0; i < saveFilesAmount; i++)
	{
		info[i] = "Empty";
	}
	if (!isInfoFileCreated()) createEmptyInfoFile();
}

void SavesHandler::loadInfoFromInfoFile()
{
	std::ifstream file;
	file.open(g_savesPath + g_InfoFileName);

	char buffer[256];
	for (int i = 0; i < saveFilesAmount; i++)
	{
		file.getline(buffer, 256);
		info[i] = buffer;
	}
	file.close();
}

void SavesHandler::saveInfoIntoInfoFile()
{
	std::ofstream file;
	file.open(g_savesPath + g_InfoFileName);
	for (int i = 0; i < saveFilesAmount; i++)
	{
		file << info[i] << std::endl;
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

void SavesHandler::loadInfoIntoSaveFiles()
{
	loadInfoFromInfoFile();
	for (int i = 0; i < saveFilesAmount; i++)
	{
		saveFiles[i]->setName(info[i]);
	}
}

std::string SavesHandler::getSaveFileInfo(int _fileID)
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

void SavesHandler::save(int _fileID, std::string _newInfo)
{
	saveFiles[_fileID]->save();
	
	//set name
	info[_fileID] = _newInfo;

	//update info file
	saveInfoIntoInfoFile();

	//update save file local variable
	saveFiles[_fileID]->setName(info[_fileID]);
}

void SavesHandler::load(int _fileID)
{
	saveFiles[_fileID]->load();
}

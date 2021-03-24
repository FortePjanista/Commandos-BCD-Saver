#include "saveFile.h"

SaveFile::SaveFile(int _nr, std::string _info) : nr(_nr), info(_info) {}

//Saves REDTMP file into this file
void SaveFile::save()
{
	std::string command = "type \"" + g_REDTMPPath + "\" > \"" + g_savesPath + std::to_string(nr) + ".sav\"";
	
	system(command.c_str());
}

//Loads this file into REDTMP
bool SaveFile::load()
{
	if (isEmpty()) return false;

	std::string command = "type \"" + g_savesPath + std::to_string(nr) + ".sav\" > \"" + g_REDTMPPath + "\"";
	system(command.c_str());
	return true;
}

std::string SaveFile::getInfo()
{
	return info;
}

void SaveFile::setInfo(std::string n)
{
	info = n;
}

int SaveFile::getNr()
{
	return nr;
}

void SaveFile::setNr(int n)
{
	nr = n;
}

bool SaveFile::isEmpty()
{
	bool ret_value;

	std::ifstream file;
	file.open(g_savesPath + std::to_string(nr) + ".sav");

	ret_value = file.peek() == EOF;

	file.close();
	
	return ret_value;
}

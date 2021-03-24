#include "saveFile.h"

SaveFile::SaveFile(int _nr, std::string _name) : nr(_nr), name(_name) {}

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

std::string SaveFile::getName()
{
	return name;
}

void SaveFile::setName(std::string n)
{
	name = n;
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

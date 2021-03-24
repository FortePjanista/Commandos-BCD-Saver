#include "saveFile.h"

SaveFile::SaveFile(int _id, const std::string& _name) : id(_id), name(_name) {}


bool SaveFile::isEmpty()
{
	bool ret_value;

	std::ifstream file;
	file.open(g_savesPath + std::to_string(id) + ".sav");

	ret_value = file.peek() == EOF;

	file.close();

	return ret_value;
}


//Saves REDTMP file into this file
void SaveFile::save()
{
	std::string command = "type \"" + g_REDTMPPath + "\" > \"" + g_savesPath + std::to_string(id) + ".sav\"";
	
	system(command.c_str());
}

//Loads this file into REDTMP
bool SaveFile::load()
{
	if (isEmpty()) return false;

	std::string command = "type \"" + g_savesPath + std::to_string(id) + ".sav\" > \"" + g_REDTMPPath + "\"";
	system(command.c_str());
	return true;
}

std::string SaveFile::getName()
{
	return name;
}

void SaveFile::setName(const std::string& n)
{
	name = n;
}
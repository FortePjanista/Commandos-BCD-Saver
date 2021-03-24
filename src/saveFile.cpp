#include "saveFile.h"

SaveFile::SaveFile(int _id, const std::string& _name) : id(_id), name(_name) {}

namespace
{
	bool isEmpty(int id)
	{
		bool ret_value;

		std::ifstream file;
		file.open(g_savesPath + std::to_string(id) + ".sav");

		ret_value = file.peek() == EOF;

		file.close();

		return ret_value;
	}
}

void SaveFile::save()
{
	std::string command = "type \"" + g_REDTMPPath + "\" > \"" + g_savesPath + std::to_string(id) + ".sav\"";
	
	system(command.c_str());
}

bool SaveFile::load()
{
	if (isEmpty(id)) return false;

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
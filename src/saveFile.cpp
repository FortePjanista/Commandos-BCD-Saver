#include "saveFile.h"
#include "pathsHandler.h"

SaveFile::SaveFile(int _id, const std::string& _name) : id(_id), name(_name) {}

namespace
{
	bool isEmpty(int id)
	{
		bool ret_value;

		auto& ph = PathsHandler::GetInstance();
		std::ifstream file;
		file.open(ph.savesPath + std::to_string(id) + ".sav");

		ret_value = file.peek() == EOF;

		file.close();

		return ret_value;
	}
}

void SaveFile::save()
{
	auto& ph = PathsHandler::GetInstance();
	std::string command = "type \"" + ph.REDTMPPath + "\" > \"" + ph.savesPath + std::to_string(id) + ".sav\"";
	
	system(command.c_str());
}

bool SaveFile::load()
{
	if (isEmpty(id)) return false;

	auto& ph = PathsHandler::GetInstance();
	std::string command = "type \"" + ph.savesPath + std::to_string(id) + ".sav\" > \"" + ph.REDTMPPath + "\"";
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
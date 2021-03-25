#include "saveFile.h"
#include "pathsHandler.h"

namespace fs = boost::filesystem;

SaveFile::SaveFile(int _id, const std::string& _name) : id(_id), name(_name) {}

namespace
{
	bool isEmpty(int id)
	{
		auto& ph = PathsHandler::GetInstance();
		return fs::is_empty(ph.savesPath / std::to_string(id) / ".sav");
	}
}

void SaveFile::save()
{
	auto& ph = PathsHandler::GetInstance();
	fs::copy_file(ph.REDTMPPath, ph.savesPath / std::to_string(id) / ".sav");
}

bool SaveFile::load()
{
	if (isEmpty(id)) return false;

	auto& ph = PathsHandler::GetInstance();
	fs::copy_file(ph.savesPath / std::to_string(id) / ".sav", ph.REDTMPPath);
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
#include "saveFile.h"
#include "pathsHandler.h"

namespace fs = boost::filesystem;

SaveFile::SaveFile(int _id, const std::string& _name) : id(_id), name(_name) {}

namespace
{
	bool isEmpty(int id)
	{
		auto &ph = PathsHandler::GetInstance();
		fs::path save(ph.savesPath / std::string(std::to_string(id) + ".sav"));
		if (!fs::exists(save))
			return true;
		return fs::is_empty(save);
	}
}

void SaveFile::save()
{
	auto &ph = PathsHandler::GetInstance();
	fs::copy_file(ph.REDTMPPath, ph.savesPath / std::string(std::to_string(id) + ".sav"), fs::copy_option::overwrite_if_exists);
}

bool SaveFile::load()
{
	if (isEmpty(id)) return false;

	auto &ph = PathsHandler::GetInstance();
	fs::copy_file(ph.savesPath / std::string(std::to_string(id) + ".sav"), ph.REDTMPPath, fs::copy_option::overwrite_if_exists);
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
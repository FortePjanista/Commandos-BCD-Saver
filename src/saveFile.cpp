#include "saveFile.h"
#include "pathsHandler.h"

namespace bf = boost::filesystem;

namespace
{
	bool isEmpty(int id)
	{
		auto & paths = PathsHandler::GetInstance();
		bf::path fullSavePath = paths.getSavePath(id);
		if (!bf::exists(fullSavePath)) return true;
		return bf::is_empty(fullSavePath);
	}
}

SaveFile::SaveFile(int _id, const std::string& _name) : id(_id), name(_name) {}

void SaveFile::save()
{
	auto & paths = PathsHandler::GetInstance();
	bf::copy_file(paths.REDTMPPath, paths.getSavePath(id), bf::copy_option::overwrite_if_exists);
}

bool SaveFile::load()
{
	if (isEmpty(id)) return false;
	auto & paths = PathsHandler::GetInstance();
	bf::copy_file(paths.getSavePath(id), paths.REDTMPPath, bf::copy_option::overwrite_if_exists);
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
#include "saveFile.h"
#include "pathsHandler.h"

using namespace boost::filesystem;

namespace
{
	bool isEmpty(int id)
	{
		auto & paths = PathsHandler::Get();
		path fullSavePath = paths.getSavePath(id);
		if (!exists(fullSavePath)) return true;
		return is_empty(fullSavePath);
	}
}

SaveFile::SaveFile(int id, const std::string& name) : id(id), name(name)
{}

void SaveFile::save()
{
	auto & paths = PathsHandler::Get();
	copy_file(paths.getREDTMPPath(), paths.getSavePath(id), copy_option::overwrite_if_exists);
}

bool SaveFile::load()
{
	if (isEmpty(id)) return false;
	auto & paths = PathsHandler::Get();
	copy_file(paths.getSavePath(id), paths.getREDTMPPath(), copy_option::overwrite_if_exists);
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
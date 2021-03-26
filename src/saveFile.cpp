#include "saveFile.h"

#include "pathsHandler.h"
#include "constants.h"
#include <iostream>

using namespace boost::filesystem;

SaveFile::SaveFile(int id, const std::string& name) : id(id), name(name)
{}

int SaveFile::save()
{
	auto & paths = PathsHandler::Get();

	if(!exists(paths.getREDTMPPath()))
		return ERROR_REDTMP_DOESNT_EXIST;

	if (!exists(paths.getSavePath(id)))
		return ERROR_SAVE_FILE_DOESNT_EXIST;

	copy_file(paths.getREDTMPPath(), paths.getSavePath(id), copy_option::overwrite_if_exists);

	return ERROR_SUCCESS;
}

int SaveFile::load()
{
	auto & paths = PathsHandler::Get();

	if (!exists(paths.getREDTMPPath()))
		return ERROR_REDTMP_DOESNT_EXIST;

	if (!exists(paths.getSavePath(id)))
		return ERROR_SAVE_FILE_DOESNT_EXIST;

	if (is_empty(paths.getSavePath(id))) 
		return ERROR_SAVE_FILE_IS_EMPTY;

	copy_file(paths.getSavePath(id), paths.getREDTMPPath(), copy_option::overwrite_if_exists);

	return ERROR_SUCCESS;
}

std::string SaveFile::getName()
{
	return name;
}

void SaveFile::setName(const std::string& n)
{
	name = n;
}

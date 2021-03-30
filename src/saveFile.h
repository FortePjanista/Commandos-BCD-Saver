#ifndef SAVE_FILE_H
#define SAVE_FILE_H

#include <string>

// This class represents a single .sav file or a save slot
class SaveFile
{
public:
	SaveFile(int id, const std::string& name);

	std::string getName();
	void setName(const std::string& name);

	// Saves REDTMP file into .sav file
	// Returns one of error_codes (constants.h)
	int save();

	// Loads this save file into REDTMP
	// Returns one of error_codes (constants.h)
	int load();

private:
	std::string name;
	int id;
};

#endif //SAVE_FILE_H
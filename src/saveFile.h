#ifndef SAVE_FILE_H
#define SAVE_FILE_H
#include <string>
#include <iostream>
#include <fstream>
#include "constants.h"
//This class represents a single .sav file or a save slot
class SaveFile
{
public:
	SaveFile(int id, const std::string& name);

	std::string getName();
	void setName(const std::string& name);

	//Saves REDTMP file into .sav file
	void save();

	//Loads this save file into REDTMP
	//returns false if physical savefile is empty
	bool load();

private:
	std::string name;
	int id;
};

#endif //SAVE_FILE_H
#ifndef SAVE_FILE_H
#define SAVE_FILE_H
#include <string>
#include <iostream>
#include <fstream>
#include "constants.h"
//This class represents a single .sav file or a save slot
class SaveFile
{
private:
	int id;
	std::string name;

public:
	SaveFile(int id, std::string name);

	std::string getName();
	void setName(std::string name);

	bool isEmpty();

	//Saves REDTMP file into this file
	void save();

	//Loads this save file into REDTMP
	//returns false if physical savefile is empty
	bool load();

	std::string getNameFromInfoFile();
	void setNameIntoInfoFile();
};

#endif //SAVE_FILE_H
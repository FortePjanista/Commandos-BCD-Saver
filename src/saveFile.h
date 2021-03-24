#ifndef SAVE_FILE_H
#define SAVE_FILE_H
#include <string>
#include <iostream>
#include <fstream>
#include "constants.h"
class SaveFile
{
private:
	int nr;
	std::string name;

public:
	SaveFile(int nr, std::string name);

	std::string getName();
	void setName(std::string name);

	int getNr();
	void setNr(int nr);

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
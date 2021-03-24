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
	std::string info;

public:
	SaveFile(int nr, std::string info);

	std::string getInfo();
	void setInfo(std::string info);

	int getNr();
	void setNr(int nr);

	bool isEmpty();

	//Saves REDTMP file into this file
	void save();

	//Loads this save file into REDTMP
	//returns false if physical savefile is empty
	bool load();

	std::string getInfoFromInfoFile();
	void setInfoIntoInfoFile();
};

#endif //SAVE_FILE_H
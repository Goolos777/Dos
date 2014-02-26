#pragma once
#include <string>
#include "FSElement.h"
class Bilder
{
	void createFle(std::string fileName, std::string path);
public:
	Bilder(std::string fileName , std::string path) ;
	FSElement* create();
	~Bilder();
};


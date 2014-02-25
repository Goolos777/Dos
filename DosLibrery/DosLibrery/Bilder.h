#pragma once
#include <string>
#include "FSElement.h"
class Bilder
{
public:
	Bilder(std::string path);
	FSElement* create();
	~Bilder();
};


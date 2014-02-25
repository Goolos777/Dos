#pragma once
#include "FSElement.h"
class File : public FSElement
{
	bool readOnly;
	std::string name;
	std::string ext;
	unsigned int SIZE;

public:
	File(bool readOnly, std::string name, std::string ext, unsigned int SIZE) :
		readOnly(readOnly), name(name), ext(ext), SIZE(SIZE){};
	~File();
};


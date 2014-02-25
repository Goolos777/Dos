#pragma once
#include "FSElement.h"
class Forder :	public FSElement
{
	bool readOnly;
	std::string name;
public:
	Forder(bool readOnly, std::string name) :readOnly(readOnly), name(name){};
	~Forder(){};
};


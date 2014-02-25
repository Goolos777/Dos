#pragma once
#include "FSElement.h"
class XMLManager
{
public:
	XMLManager();
	FSElement* loadXML();
	void saveAll(FSElement* root);
	~XMLManager();
};


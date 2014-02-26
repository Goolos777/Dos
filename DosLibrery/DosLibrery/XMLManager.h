#pragma once
#include "FSElement.h"
class XMLManager
{
public:
	XMLManager();
	FSElement* loadXML();
	void SaveAll(FSElement* root);
	~XMLManager();
};


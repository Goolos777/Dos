#pragma once
#include <string>
#include <windows.h>
#include <stdio.h>
#include <strsafe.h>
#include <atlconv.h>
#include "FSElement.h"
#include "Folder.h"
#include "File.h"

class Bilder
{


	void create(FSElement* element);
public:
	Bilder(std::string fileName , std::string path) ;
	FSElement* Create();
	~Bilder();
};


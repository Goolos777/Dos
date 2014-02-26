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
	FSElement* root;
	void create(FSElement* element);
public:
	Bilder(wstring path);
	FSElement* Create(){return root;}
	~Bilder();
};


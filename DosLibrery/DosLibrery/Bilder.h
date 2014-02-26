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
	void createTree(FSElement* element);
	void deleteTree(FSElement* element);
public:
	Bilder(wstring path);
	FSElement* Create(){return root;}
	~Bilder();
};


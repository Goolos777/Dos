
#pragma once
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include "FSElement.h"
using namespace std;
class XMLManager
{
	wstring path;

public:

	XMLManager(wstring path);

	void SaveAll(FSElement* root);

	~XMLManager();

};




#pragma once
#include "FSElement.h"
#include <string>

using namespace std;

class Folder :	public FSElement
{
	long tmp = 0;

	vector<FSElement*>filesSystem;

public:

	Folder(bool readOnly, bool isFolder, std::wstring name, FSElement *up);

	virtual void AddFSElement(FSElement& element);

	virtual vector<FSElement*>& GetFilesSystem();

	virtual const long& GetSIZE();

	virtual ~Folder();
};



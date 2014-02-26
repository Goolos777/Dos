#pragma once
#include "FSElement.h"
#include <string>

using namespace std;

class Folder :	public FSElement
{
	vector<FSElement*>filesSystem;
public:
	Folder(bool readOnly, bool isFolder, std::wstring name, FSElement *up) : FSElement(readOnly, isFolder, name, up)
												{ std::vector<const FSElement*>filesSystem; };
	virtual void AddFSElement(FSElement& element);
	virtual vector<FSElement*>& GetFilesSystem(){ return filesSystem; }
	virtual const wstring& Print();
	virtual ~Folder(){};
};



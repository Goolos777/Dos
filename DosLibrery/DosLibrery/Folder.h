#pragma once
#include "FSElement.h"
#include <string>

using namespace std;

class Folder :	public FSElement
{
	const long isFolder=-1;
public:
	Folder(bool readOnly, std::wstring name, long SIZE, FSElement *up);

	virtual void AddFSElement(FSElement& element);
	virtual vector<FSElement*>& GetFilesSystem();

	virtual const long& GetSIZE();
	virtual void SetSIZE(long Folder){}
	virtual ~Folder(){};
};
Folder::Folder(bool readOnly, std::wstring name, long SIZE, FSElement *up) :
												FSElement(readOnly, name,SIZE, up)	
{
	std::vector<const FSElement*>filesSystem;
};
vector<FSElement*>& Folder::GetFilesSystem()
{ 
	return filesSystem; 
}
const long& Folder::GetSIZE()
{ 
	return isFolder; 
}

#pragma once
#include "FSElement.h"
#include <string>
class Folder :	public FSElement
{
	std::vector<const FSElement*>filesSystem;
public:
	Folder(bool readOnly, std::wstring name) : FSElement(readOnly, name){ std::vector<const FSElement*>filesSystem; };
	
	virtual void addFSElement(const FSElement& element);
	virtual const FSElement* getFolder();

	virtual ~Folder(){};
};



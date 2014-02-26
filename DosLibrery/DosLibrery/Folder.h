#pragma once
#include "FSElement.h"
#include <string>
class Folder :	public FSElement
{
	std::vector<const FSElement*>filesSystem;
public:
	Folder(bool readOnly, std::wstring name) : FSElement(readOnly, name){ std::vector<const FSElement*>filesSystem; };
	
	virtual void AddFSElement(const FSElement& element);
	virtual const FSElement* GetFolder();

	virtual ~Folder(){};
};


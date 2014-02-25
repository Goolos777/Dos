#pragma once

#include <vector>
#include <string>

class FSElement
{
	std::vector<FSElement*>filesSystem;
public:
	FSElement(){ std::vector<FSElement*>filesSystem; }
	void addFSElement(FSElement* element);
	void setReadOnly(bool readOnly);
	void setExt(std::string ext);
	void setName(std::string name);
	void setSIZE(unsigned int size);
	virtual ~FSElement()=0;
};


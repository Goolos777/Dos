#pragma once

#include <vector>
#include <string>

class FSElement
{
	bool mReadOnly;
	std::wstring mName;
	FSElement *upFSElement;
public:
	FSElement(const bool readOnly, const std::wstring& name, FSElement *up = nullptr)
		:mReadOnly(readOnly), mName(name),upFSElement(up) {};
	
	void setReadOnly(const bool readOnly){ mReadOnly=readOnly; }
	void setName(const std::wstring& name){ mName = name; }
	void setExt(const std::wstring& ext);
	void setSIZE(unsigned int size);
	
	virtual void addFSElement(FSElement* element);
	virtual const FSElement* getFolder();
	void setUpFSElement(FSElement *up){ upFSElement = up; }
	virtual const FSElement* getUpFSElement(){ return upFSElement; }

	virtual bool getReadOnly(){ return mReadOnly; }
	virtual const std::wstring& getName(){ return mName; }
	virtual const std::wstring& getExt();
	virtual const unsigned int getSIZE();
	

	virtual ~FSElement()=0;
};


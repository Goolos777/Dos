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
	
	void SetReadOnly(const bool readOnly){ mReadOnly=readOnly; }
	void SetName(const std::wstring& name){ mName = name; }
	void SetExt(const std::wstring& ext);
	void SetSIZE(unsigned int size);
	
	virtual void AddFSElement(FSElement* element);
	virtual const FSElement* GetFolder();
	void SetUpFSElement(FSElement *up){ upFSElement = up; }
	virtual const FSElement* GetUpFSElement(){ return upFSElement; }

	virtual bool GetReadOnly(){ return mReadOnly; }
	virtual const std::wstring& GetName(){ return mName; }
	virtual const std::wstring& GetExt();
	virtual const unsigned int GetSIZE();
	

	virtual ~FSElement()=0;
};


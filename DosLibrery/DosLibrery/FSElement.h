#pragma once

#include <vector>
#include <string>
using namespace std;
class FSElement
{
	bool mReadOnly;
	wstring mName;
	FSElement *upFSElement;
public:
	FSElement(const bool readOnly, const wstring& name, FSElement *up = nullptr)
		:mReadOnly(readOnly), mName(name),upFSElement(up) {};
	
	void SetReadOnly(const bool readOnly){ mReadOnly=readOnly; }
	void SetName(const wstring& name){ mName = name; }
	virtual void SetSIZE(long size);
	
	
	virtual void AddFSElement(FSElement* element);
	virtual const FSElement* GetFolder();
	void SetUpFSElement(FSElement *up){ upFSElement = up; }
	virtual const FSElement* GetUpFSElement(){ return upFSElement; }

	virtual bool GetReadOnly(){ return mReadOnly; }
	virtual const wstring& GetName(){ return mName; }
	virtual const long& GetSIZE();
	

	virtual ~FSElement()=0;
};


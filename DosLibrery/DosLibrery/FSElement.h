#pragma once

#include <vector>
#include <string>

using namespace std;
class FSElement
{
	bool mReadOnly;
	wstring mName;
	FSElement *upFSElement;
	bool isFolder;
protected:
	vector<FSElement*>filesSystem;
public:
	FSElement(const bool readOnly, bool isFolder, const wstring& name, FSElement *up)
		:mReadOnly(readOnly), mName(name), upFSElement(up) {};
	
	void SetReadOnly(const bool readOnly){ mReadOnly=readOnly; }
	void SetName(const wstring& name){ mName = name; }
	virtual void SetSIZE(long size){};
	
	
	virtual void AddFSElement(FSElement* element){ filesSystem.push_back(element); }
	virtual vector<FSElement*>& GetFilesSystem(){ return filesSystem; };
	void SetUpFSElement(FSElement *up){ upFSElement = up; }
	virtual const FSElement* GetUpFSElement(){ return upFSElement; }
	bool GetisFolder(){ return isFolder; }
	virtual bool GetReadOnly(){ return mReadOnly; }
	virtual const wstring& GetName(){ return mName; }
	virtual const long& GetSIZE() = 0;
	const wstring& Print(){	return mName;	}

	virtual ~FSElement(){};
};


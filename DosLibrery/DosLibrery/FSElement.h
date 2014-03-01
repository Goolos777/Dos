#pragma once
#include <vector>
#include <string>
using namespace std;
class FSElement
{
	bool mReadOnly;

	bool isFolder;

	wstring mName;

	FSElement *upFSElement;

	vector<FSElement*>filesSystem;
public:

	FSElement(const bool readOnly, bool isFolder, const wstring& name, FSElement *up);

	void SetReadOnly(const bool readOnly);

	void SetName(const wstring& name);

	virtual void SetSIZE(long size);

	void SetUpFSElement(FSElement *up);

	virtual void AddFSElement(FSElement* element);

	virtual vector<FSElement*>& GetFilesSystem();

	virtual const FSElement* GetUpFSElement();

	bool GetisFolder();

	virtual bool GetReadOnly();

	virtual const wstring& GetName();

	virtual const long& GetSIZE() = 0;

	const wstring& Print();

	virtual ~FSElement();;
};


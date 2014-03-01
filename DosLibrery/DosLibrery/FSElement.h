#pragma once

#include <vector>
#include <string>

using namespace std;
class FSElement
{
	bool mReadOnly;
	wstring mName;
	FSElement *upFSElement;
protected:
	vector<FSElement*>filesSystem;
public:
	FSElement(bool readOnly, std::wstring name, long SIZE, FSElement *up);

	void SetReadOnly(const bool readOnly);
	virtual bool GetReadOnly();

	void SetName(const wstring& name);
	virtual const wstring& GetName();

	virtual void AddFSElement(FSElement* element);
	virtual vector<FSElement*>& GetFilesSystem();

	void SetUpFSElement(FSElement *up);
	virtual const FSElement* GetUpFSElement();

	const wstring& Print();

	virtual void SetSIZE(long size) = 0;
	virtual const long& GetSIZE() = 0;

	virtual ~FSElement();
};
FSElement::FSElement(bool readOnly, std::wstring name, long SIZE, FSElement *up)
										:mReadOnly(readOnly), mName(name), upFSElement(up) {};

void FSElement::SetReadOnly(const bool readOnly)
{ 
	mReadOnly = readOnly; 
}
void FSElement::SetName(const wstring& name)
{ 
	mName = name;
}
void FSElement::AddFSElement(FSElement* element)
{ 
	filesSystem.push_back(element);
}
vector<FSElement*>& FSElement::GetFilesSystem()
{
	return filesSystem;
}
void FSElement::SetUpFSElement(FSElement *up)
{ 
	upFSElement = up; 
}
const FSElement* FSElement::GetUpFSElement()
{ 
	return upFSElement;
}
bool FSElement::GetReadOnly()
{
	return mReadOnly;
}
const wstring& FSElement::GetName()
{ 
	return mName;
}

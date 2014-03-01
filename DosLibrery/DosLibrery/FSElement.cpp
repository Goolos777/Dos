#include "FSElement.h"

FSElement::FSElement(const bool readOnly, bool isFolder, const wstring& name, FSElement *up)
:mReadOnly(readOnly), mName(name), upFSElement(up)
{

}

void FSElement::SetReadOnly(const bool readOnly)
{
	mReadOnly = readOnly;
}

void FSElement::SetName(const wstring& name)
{
	mName = name;
}

void FSElement::SetSIZE(long size)
{

}

void FSElement::AddFSElement(FSElement* element)
{

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

bool FSElement::GetisFolder()
{
	return isFolder;
}

bool FSElement::GetReadOnly()
{
	return mReadOnly;
}

const wstring& FSElement::GetName()
{
	return mName;
}

const wstring& FSElement::Print()
{
	return mName;
}

FSElement::~FSElement()
{

}

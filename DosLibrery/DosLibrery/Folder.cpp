#include "Folder.h"
#include "FSElement.h"

void Folder::AddFSElement(FSElement& element)
{
	filesSystem.push_back(&element);
}

Folder::Folder(bool readOnly, bool isFolder, std::wstring name, FSElement *up) : FSElement(readOnly, isFolder, name, up)
{
	std::vector<const FSElement*>filesSystem;
}

vector<FSElement*>& Folder::GetFilesSystem()
{
	return filesSystem;
}

const long& Folder::GetSIZE()
{
	return tmp;
}

Folder::~Folder()
{

}

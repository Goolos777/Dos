#include "Folder.h"
#include "FSElement.h"

void Folder::AddFSElement(const FSElement& element)
{
	filesSystem.push_back(&element);
}
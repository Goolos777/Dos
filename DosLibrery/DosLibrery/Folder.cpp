#include "Folder.h"
#include "FSElement.h"

void Folder::AddFSElement(FSElement& element)
{
	filesSystem.push_back(&element);
}

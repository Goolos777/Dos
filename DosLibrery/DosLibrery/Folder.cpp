#include "Folder.h"
#include "FSElement.h"

void Folder::addFSElement(const FSElement& element)
{
	filesSystem.push_back(&element);
}
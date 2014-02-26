#include "Bilder.h"


Bilder::Bilder(wstring path)
{
	root = new Folder(false, path, nullptr);
	create(root);
}

void Bilder::create(FSElement* element)
{
	WIN32_FIND_DATA ffd;
	LARGE_INTEGER filesize;
	HANDLE hFind = FindFirstFile(element->GetName().c_str(), &ffd);
	do
	{
		FSElement *el;
		if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{	
			el = new Folder(ffd.dwFileAttributes & FILE_ATTRIBUTE_READONLY, ffd.cFileName, element);
			create(el);
		}
		else
		{
			long SIZE = ffd.nFileSizeLow + ffd.nFileSizeHigh;
			el = new File(ffd.dwFileAttributes & FILE_ATTRIBUTE_READONLY, ffd.cFileName, SIZE,element);
		}
		element->AddFSElement(el);
		
	} while (FindNextFile(hFind, &ffd) != 0);

}
Bilder::~Bilder()
{

}
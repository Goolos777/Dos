#include "Bilder.h"


Bilder::Bilder(wstring path)
{
	root = new Folder(false,true, path, nullptr);
	createTree(root);
}

void Bilder::createTree(FSElement* element)
{
	WIN32_FIND_DATA ffd;
	LARGE_INTEGER filesize;
	LPCTSTR t = element->GetName().c_str();
	HANDLE hFind = FindFirstFile(element->GetName().c_str(), &ffd);
	do
	{
		FSElement *el;
		if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{	
			el = new Folder(ffd.dwFileAttributes & FILE_ATTRIBUTE_READONLY,
							ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY,
							ffd.cFileName, element);
			createTree(el);
		}
		else
		{
			long SIZE = ffd.nFileSizeLow + ffd.nFileSizeHigh;
			el = new File(ffd.dwFileAttributes & FILE_ATTRIBUTE_READONLY, 
							ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY, 
							ffd.cFileName, SIZE, element);
		}
		element->AddFSElement(el);
		
	} while (FindNextFile(hFind, &ffd) != 0);

}
void Bilder::deleteTree(FSElement* element)
{
	for (FSElement *temp : element->GetFilesSystem())
	{
		if (temp->GetisFolder())deleteTree(temp);
		delete temp;
	}
	delete element;
}

Bilder::~Bilder()
{
	deleteTree(root);
}
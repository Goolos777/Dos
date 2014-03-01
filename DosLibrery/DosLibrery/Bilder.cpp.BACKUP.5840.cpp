#include "Bilder.h"


<<<<<<< HEAD
Bilde::Bilde()
{
	wstring path = L"c:\\*";
	root = new Folder(false, path,-1, nullptr);
=======
Bilder::Bilder(wstring path)
{
	root = new Folder(false,true, path, nullptr);
>>>>>>> parent of 7dfcee7... капец
	createTree(root);
}

void Bilde::createTree(FSElement* element)
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
			el = new Folder(ffd.dwFileAttributes & FILE_ATTRIBUTE_READONLY,	ffd.cFileName,-1, element);
			createTree(el);
		}
		else
		{
			long SIZE = ffd.nFileSizeLow + ffd.nFileSizeHigh;
			el = new File(ffd.dwFileAttributes & FILE_ATTRIBUTE_READONLY, ffd.cFileName, SIZE, element);
		}
		element->AddFSElement(el);
		
	} while (FindNextFile(hFind, &ffd) != 0);

}
void Bilde::deleteTree(FSElement* element)
{
	for (FSElement *temp : element->GetFilesSystem())
	{
		if (temp->GetSIZE() == -1)deleteTree(temp);
		delete temp;
	}
	delete element;
}

Bilde::~Bilde()
{
	deleteTree(root);
}
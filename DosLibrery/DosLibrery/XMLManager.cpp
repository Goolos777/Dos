#include "XMLManager.h"


XMLManager::~XMLManager()
{
}

void XMLManager::SaveAll(FSElement* root)
{
	fstream f(path.c_str());
	for (FSElement *temp : root->GetFilesSystem())
	{
		f.write((char*)temp->Print().c_str(), temp->Print().length());

		if (temp->GetisFolder())
		{
			SaveAll(temp);
		}
	}
}
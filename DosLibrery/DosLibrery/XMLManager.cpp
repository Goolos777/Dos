#include "XMLManager.h"

#include <iostream>
void XMLManager::SaveAll(FSElement* root)
{
	if (!root)return;
	fstream f;
	f.open(path.c_str());
	for (FSElement *temp : root->GetFilesSystem())
	{
		f.open("d:\\M.txt");
		
		f.write((char*)temp->Print().c_str(), temp->Print().length());
	
		if (temp->GetisFolder())
		{
			SaveAll(temp);
		}
	}
}


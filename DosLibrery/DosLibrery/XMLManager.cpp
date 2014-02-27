#include "XMLManager.h"

#include <iostream>
void XMLManager::SaveAll(FSElement* root)
{
	if (!root)return;
	fstream FileStreet("D:\\file.txt");
	
	fstream f;
	
	for (FSElement *temp : root->GetFilesSystem())
	{
		f.open("c:\\M.txt");
		f.write((char*)temp->Print().c_str(), temp->Print().size());
	
		if (temp->GetisFolder())
		{
			//SaveAll(temp);
		}
	}
	f.close();


}


#include "XMLManager.h"


void XMLManager::SaveAll(FSElement* root)
{






	ofstream myfile;// ���������� ������ ofstream 

	char * buffer;// ���������� ���������
	const long int size = 10;// ����������� ���������� ���� int lohg 

	buffer = new char[size];// ��������� �������������� ������ ���� char 
	for (int i = 0; i < 10; i++)
	{
		buffer[i] = 'l';
		myfile.open("d:\\M.txt");
		myfile.write(buffer, size);

	}
	myfile.close();
	









	//fstream f;
	//f.open("c:\\M.txt");

	//f.open(path.c_str());
	//for (FSElement *temp : root->GetFilesSystem())
	//{
	//	f.write((char*)temp->Print().c_str(), temp->Print().length());
	//
	//	if (temp->GetisFolder())
	//	{
	//		//SaveAll(temp);
	//	}
	//}
}


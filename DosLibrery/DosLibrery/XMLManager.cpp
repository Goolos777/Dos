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
}

XMLManager::XMLManager(wstring path) : path(path)
{

}

XMLManager::~XMLManager()
{

}


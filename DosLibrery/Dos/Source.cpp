#include <string>
#include "XMLManager.h"
#include "Bilder.h"
using namespace std;
int main()
{
	Bilder bilder(L"c:\\");
	XMLManager xml(L"c:\\aa1.txt");
	xml.SaveAll(bilder.Create());
}
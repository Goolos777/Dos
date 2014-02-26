#include <string>
#include "XMLManager.h"
#include "Bilder.h"
using namespace std;
int main()
{
	XMLManager manager(L"as");
	manager.SaveAll(nullptr);
}
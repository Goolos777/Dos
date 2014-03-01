#include "gtest/gtest.h"
#include <string>
#include "XMLManager.h"
#include "Bilder.h"
using namespace std;

TEST(XMLManager, testSaveAll)
{
	XMLManager manager(L"as");
	manager.SaveAll(nullptr);
}
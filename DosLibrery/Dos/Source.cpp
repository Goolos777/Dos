#include <windows.h>
#include <tchar.h> 
#include <stdio.h>
#include <strsafe.h>
#include "Bilder.h"
#include "XMLManager.h"
#pragma comment(lib, "User32.lib")

void DisplayErrorBox(LPTSTR lpszFunction);

int _tmain(int argc, TCHAR *argv[])
{
	TCHAR a[] = L"c:\\";
	WIN32_FIND_DATA ffd;
	LARGE_INTEGER filesize;
	TCHAR szDir[MAX_PATH];
	size_t length_of_arg;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	DWORD dwError = 0;
	
	_tprintf(TEXT("\nTarget directory is %s\n\n"), a);
	StringCchCopy(szDir, MAX_PATH, a);
	StringCchCat(szDir, MAX_PATH, TEXT("\\aa1.txt"));
	
	Bilder bilder;
	XMLManager  manager(a);
	manager.SaveAll(bilder.Create());
	

	
	return 0;
}

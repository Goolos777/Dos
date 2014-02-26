#pragma once
#include "FSElement.h"
class File : public FSElement
{
	long filesize;
public:
	File(bool readOnly, std::wstring name, long SIZE) :
		filesize(SIZE), FSElement(readOnly, name){};

	
	virtual void SetSIZE(long size){ filesize = size; }
	virtual const long& GetSIZE() { return filesize; };

	~File();
};


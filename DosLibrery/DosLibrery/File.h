#pragma once
#include "FSElement.h"
class File : public FSElement
{

	long filesize;

public:

	File(bool readOnly, bool isFolder, std::wstring name, long SIZE, FSElement *up);
	
	virtual void SetSIZE(long size);

	virtual const long& GetSIZE();

	virtual ~File();

};

File::File(bool readOnly, bool isFolder, std::wstring name, long SIZE, FSElement *up) :
									filesize(SIZE), FSElement(readOnly, isFolder, name, up){};

void File::SetSIZE(long size){ filesize = size; }

const long& File::GetSIZE() { return filesize; };

File::~File(){};
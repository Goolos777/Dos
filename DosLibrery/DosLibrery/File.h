#pragma once
#include "FSElement.h"
class File : public FSElement
{
	long filesize;
public:
	File(bool readOnly, std::wstring name, long SIZE, FSElement *up);
	virtual void SetSIZE(long size){ filesize = size; }
	virtual const long& GetSIZE() { return filesize; };

	virtual ~File(){};
};

File::File(bool readOnly, std::wstring name, long SIZE, FSElement *up) :
								filesize(SIZE), FSElement(readOnly, name,SIZE, up){};
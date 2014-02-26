#pragma once
#include "FSElement.h"
class File : public FSElement
{
	std::wstring ext;
	unsigned int SIZE;

public:
	File(bool readOnly, std::wstring name, std::wstring ext, unsigned int SIZE) :
								ext(ext), SIZE(SIZE), FSElement(readOnly,name){};

	virtual void setExt(const std::wstring& ext){ this->ext = ext; }
	virtual void setSIZE(unsigned int size){ SIZE = size; }

	virtual  std::wstring& getExt(){ return ext; };
	virtual const unsigned int getSIZE(){ return SIZE; };

	~File();
};


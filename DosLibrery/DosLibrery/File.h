#pragma once
#include "FSElement.h"
class File : public FSElement
{
	std::wstring ext;
	unsigned int SIZE;

public:
	File(bool readOnly, std::wstring name, std::wstring ext, unsigned int SIZE) :
								ext(ext), SIZE(SIZE), FSElement(readOnly,name){};

	virtual void SetExt(const std::wstring& ext){ this->ext = ext; }
	virtual void SetSIZE(unsigned int size){ SIZE = size; }

	virtual  std::wstring& GetExt(){ return ext; };
	virtual const unsigned int GetSIZE(){ return SIZE; };

	~File();
};


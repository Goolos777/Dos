#pragma once
#include <string>
#include "Bilder.h"
#include "ShowTree.h"
#include "XMLManager.h"
class ConsolCommander
{
	std::string fileName;
	std::string paths;
public:
	ConsolCommander(std::string fileName, std::string paths = "not") : fileName(fileName), paths(paths){};
	// � ����������� �� ��������� ��������� �������� ���������.
	~ConsolCommander();
};


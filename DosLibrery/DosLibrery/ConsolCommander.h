#pragma once
#include <string>



class ConsolCommander
{
	std::string fileName;
	std::string paths;
public:
	ConsolCommander(std::string fileName, std::string paths = "not") : fileName(fileName), paths(paths){};
	// в зависимости от принятого аргумента выбираес стратегию.
	~ConsolCommander();
};


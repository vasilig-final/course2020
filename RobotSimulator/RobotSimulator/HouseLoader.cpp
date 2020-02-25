#include "HouseLoader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <fmt/format.h>

HouseUPtr HouseLoader::loadFromFile(char const* fileName)
{
	std::ifstream houseFile(fileName);

	if (!houseFile.is_open())
		return nullptr;

	auto house = createHouseFromHeader(houseFile);
	for (size_t r = 0; r < house->getHeight(); ++r)
	{
		std::string line;
		if (!std::getline(houseFile, line) || line.size() != house->getWidth())
			throw std::runtime_error("Invalid row");
		
		for (size_t c = 0; c < house->getWidth(); ++c)
			house->set({ c, r }, line[c]);
	}

	if (!house->getDockPosition().isValid(house->getWidth(), house->getHeight()))
		throw std::runtime_error("No dock found");

//	house->print();
	return house;
}

HouseUPtr HouseLoader::createHouseFromHeader(std::ifstream& houseFile)
{
	std::string houseName;
	if (!std::getline(houseFile, houseName) || houseName.empty())
		throw std::runtime_error("Invalid house name");

	std::string tmp;
	if (!std::getline(houseFile, tmp))
		throw std::runtime_error("Invalid max steps");
	size_t maxSteps = std::stol(tmp);

	if (!std::getline(houseFile, tmp))
		throw std::runtime_error("Invalid row/cols");

	int rows, cols;
	std::istringstream ss(tmp);
	ss >> rows;
	while (!isdigit(ss.peek()))
		ss.ignore();
	ss >> cols;

	return std::make_unique<House>(rows, cols, maxSteps, houseName);
}

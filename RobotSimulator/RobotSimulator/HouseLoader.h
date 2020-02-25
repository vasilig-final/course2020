#ifndef __HOUSE_LOADER_H__
#define __HOUSE_LOADER_H__

#pragma once

#include "House.h"
#include <memory>

class House;

class HouseLoader
{
	static std::unique_ptr<House> createHouseFromHeader(std::ifstream& houseFile);
	
public:
	static std::unique_ptr<House> loadFromFile(char const* fileName);
};

#endif
#ifndef __HOUSE_LOADER_H__
#define __HOUSE_LOADER_H__

#pragma once

#include <memory>

class House;

class HouseLoader
{
public:
	static std::unique_ptr<House> loadFromFile(char const* fileName);
};

#endif
#ifndef __HOUSE_LOADER_H__
#define __HOUSE_LOADER_H__

#pragma once

#include <memory>
#include "House.h"
#include <fstream>
#include <string>
#include <iostream>

//using namespace std;

class House;

class HouseLoader
{
public:
	static std::unique_ptr<House> loadFromFile(char const* fileName)
	{
		std::ifstream houseFile;
		houseFile.open(fileName);
		std::string row;

		if (houseFile.is_open())
		{
			std::unique_ptr<House> house;

			//read name of house
			std::getline(houseFile, row);
			
			std::cout << row << std::endl;

			while (!houseFile.eof()) 
			{
				//read max steps
				std::getline(houseFile, row);
				int maxSteps = std::stoi(row);


			}
		}
		return nullptr;
	}
};

#endif
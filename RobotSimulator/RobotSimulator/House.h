#ifndef __HOUSE_H__
#define __HOUSE_H__

#pragma once

#include <cstdint>
#include "AlgoInterface.h"

struct Position
{
	int x, y;

	Position operator+(Direction d) const;
	Position& operator+=(Direction d);
};

class House
{	
public:
	using CellContent = uint8_t;
	
	static constexpr CellContent CLEAN = 0;
	static constexpr CellContent WALL = 0xff;
	static constexpr CellContent DOCK_STATION = 0xfe;

	size_t getHeight() const;
	size_t getWidth() const;

	CellContent get(Position const& p) const;
	void set(Position const& p, CellContent content);

	Position getDockPosition() const;
	size_t getMaxSteps() const;

protected:

	int _maxSteps;
	int _rows;
	int _cols;
	int map[][];
		 
};

#endif

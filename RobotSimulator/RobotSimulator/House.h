#ifndef __HOUSE_H__
#define __HOUSE_H__

#pragma once

#include <cstdint>

struct Position
{
	size_t x, y;
};

class House
{	
public:
	using CellContent = uint8_t;
	
	static constexpr CellContent WALL = 0xff;
	static constexpr CellContent DOCK_STATION = 0xfe;

	size_t getHeight() const;
	size_t getWidth() const;

	CellContent get(size_t x, size_t y) const;
	void set(size_t x, size_t y, CellContent content);

	Position getDockPosition() const;
};

#endif

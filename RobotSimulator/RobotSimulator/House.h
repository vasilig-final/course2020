#ifndef __HOUSE_H__
#define __HOUSE_H__

#pragma once

#include <cstdint>
#include <vector>
#include "AlgoInterface.h"

struct Position
{
	int _x, _y;

	Position(int x, int y) : _x(x), _y(y) {}
	Position(size_t x, size_t y) : _x(static_cast<int>(x)), _y(static_cast<int>(y)) {}

	bool operator==(Position const& rhs) const;
	bool operator!=(Position const& rhs) const;

	Position operator+(Direction d) const;
	Position& operator+=(Direction d);

	bool isValid(size_t rows, size_t cols) const;
};

class House
{	
public:
	using CellContent = uint8_t;
	
	static constexpr CellContent CLEAN = '0';
	static constexpr CellContent WALL = 'W';
	static constexpr CellContent DOCK_STATION = 'D';

public:
	House(size_t rows, size_t cols, size_t maxSteps, std::string name);

	size_t getHeight() const { return _rows; }
	size_t getWidth() const { return _cols; }

	CellContent get(Position const& p) const;
	void set(Position const& p, CellContent val);

	Position getDockPosition() const { return _dockPos; }
	size_t getMaxSteps() const { return _maxSteps; }

	size_t getTotalDirt() const;

	void print() const;

protected:
	size_t _rows;
	size_t _cols;
	size_t _maxSteps;
	std::string _name;
	std::vector<CellContent> _map;

	Position _dockPos{-1, -1};
};
using HouseUPtr = std::unique_ptr<House>;

#endif

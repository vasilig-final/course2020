#include "House.h"
#include <iostream>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Position

bool Position::operator==(Position const& rhs) const
{
    return _x == rhs._x && _y == rhs._y;
}

bool Position::operator!=(Position const& rhs) const
{
    return !(*this == rhs);
}

Position Position::operator+(Direction d) const
{
    Position p = *this;

	switch (d)
	{
    case Direction::LEFT:  --p._x; break;
    case Direction::UP:    --p._y; break;
    case Direction::RIGHT: ++p._x; break;
    case Direction::DOWN:  ++p._y; break;
    case Direction::STAY:
    default:
        break;
	}

    return p;
}

Position& Position::operator+=(Direction d)
{
    *this = *this + d;
    return *this;
}

bool Position::isValid(size_t rows, size_t cols) const
{
    return _x >= 0 && _x < static_cast<int>(cols) &&
        _y >= 0 && _y < static_cast<int>(rows);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// House

House::House(size_t rows, size_t cols, size_t maxSteps, std::string name)
    : _rows(rows), _cols(cols), _maxSteps(maxSteps), _name(std::move(name)), _map(rows * cols)
{
    if (0 == _rows || 0 == _cols)
        throw std::runtime_error("Invalid map dimensions");
}

auto House::get(Position const& p) const -> CellContent
{
    return _map[p._y * _cols + p._x];
}

void House::set(Position const& p, CellContent val)
{
    if (p._x == 0 || p._y == 0 || p._x == static_cast<int>(_cols - 1) || p._y == static_cast<int>(_rows - 1))
        val = WALL;

    if (val == ' ')
        val = CLEAN;
    else if (val == DOCK_STATION)
    {
        if (_dockPos == Position{-1, -1})
            _dockPos = p;
        else
            throw std::runtime_error("Invalid map, multiple docking stations found");
    }

    _map[p._y * _cols + p._x] = val;
}

size_t House::getTotalDirt() const
{
    size_t total = 0;
	
    for (size_t r = 0; r < getHeight(); ++r)
        for (size_t c = 0; c < getWidth(); ++c)
        {
            auto content = get({c, r});
            if (content != WALL && content != DOCK_STATION)
                total += content - CLEAN;
        }

    return total;
}

void House::print() const
{
	for (size_t r = 0; r < getHeight(); ++r)
    {
		for (size_t c = 0; c < getWidth(); ++c)
			std::cout << get({ c, r });

        std::cout << "\n";
    }
}

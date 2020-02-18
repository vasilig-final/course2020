#include "House.h"

Position Position::operator+(Direction d) const
{
    Position p = *this;

	switch (d)
	{
    case Direction::LEFT:  --p.x; break;
    case Direction::UP:    --p.y; break;
    case Direction::RIGHT: ++p.x; break;
    case Direction::DOWN:  ++p.y; break;
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

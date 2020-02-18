#include "House.h"

void Position::update(Direction d)
{
	switch (d)
	{
    case Direction::LEFT:  --x; break;
    case Direction::UP:    --y; break;
    case Direction::RIGHT: ++x; break;
    case Direction::DOWN:  ++y; break;
    case Direction::STAY:
    default:
        break;
	}
}

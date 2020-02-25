#include "DummyAlgorithm.h"

Direction DummyAlgorithm::nextStep(Direction lastMove, bool& finish)
{
	// Check that interfaces work...
	bool wall = _wallSensor->isWall(Direction::UP);
	bool dirty = _dirtSensor->isDirty();
	int stepsLeft = _batterySensor->stepsLeft();

	return Direction::STAY;
}

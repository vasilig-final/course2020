#include "SingleSimRun.h"
#include <chrono>
#include <stdexcept>

using namespace std::chrono;

namespace {

template<typename Func>
auto measureRunTime(Func f)
{
	auto tp1 = high_resolution_clock::now();
	f();
	auto tp2 = high_resolution_clock::now();
	return tp2 - tp1;
}

} // Local stuff


SingleSimRun::SingleSimRun(RobotAlgorithm& algo, House house, ConfigMap config, ScoreFunc scoreFunc)
	: _algo(algo), _house(std::move(house)), _config(std::move(config)), _scoreFunc(std::move(scoreFunc))
	, _currentPos(_house.getDockPosition())
{
}

int SingleSimRun::runAndScore()
{
	_algo.init(*this, _config);
	
	bool finish = false;
	Direction direction = Direction::STAY;

	auto totalRunTime = nanoseconds::zero();
	for (_curStep = 0; _curStep < _house.getMaxSteps() && !finish; ++_curStep)
	{
		totalRunTime += measureRunTime([&]() { direction = _algo.nextStep(direction, finish); });

		auto intendedPos = _currentPos + direction;
		if (_house.get(intendedPos) == House::WALL)
			direction = Direction::STAY;
		else
			_currentPos = intendedPos;

		cleanCurCell();
	}

	if (_currentPos != _house.getDockPosition())
		return 0; // Algorithm that doesn't return to dock gets score of zero.

	return _scoreFunc(_house.getTotalDirt(), _curStep, totalRunTime);
}

bool SingleSimRun::isWall(Direction d) const
{
	return _house.get(_currentPos + d) == House::WALL;	
}

bool SingleSimRun::isDirty() const
{
	auto content = _house.get(_currentPos);
	return content != House::CLEAN && content != House::DOCK_STATION;	
}

int SingleSimRun::stepsLeft() const
{
	return static_cast<int>(_house.getMaxSteps() - _curStep);
}

void SingleSimRun::cleanCurCell()
{
	auto content = _house.get(_currentPos);
	if (content == House::CLEAN || content == House::DOCK_STATION)
		return;

	if (content == House::WALL)
		throw std::runtime_error("Trying to clean wall, bug in simulator!");

	_house.set(_currentPos, --content);
}

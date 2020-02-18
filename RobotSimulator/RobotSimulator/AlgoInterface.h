#ifndef __ALGO_INTERFACE_H__
#define __ALGO_INTERFACE_H__

#pragma once

#include <map>
#include <string>

enum class Direction {
	LEFT, UP, RIGHT, DOWN, STAY
};

class WallSensor
{
public:
	virtual bool isWall(Direction d) const = 0;
};

class DirtSensor
{
public:
	virtual bool isDirty() const = 0;
};

class BatterySensor
{
public:
	virtual int stepsLeft() const = 0;
};

/*class RobotAlgorithm
{
public:
	template<typename RobotRep>
	void init(RobotRep& robot, std::map<std::string, int> config);

	Direction nextStep(Direction lastMove, bool& finish);

	std::string const& getName() const;
	std::string const& getDescription() const;
};*/

#endif
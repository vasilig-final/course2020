#ifndef __ALGO_INTERFACE_H__
#define __ALGO_INTERFACE_H__

#pragma once

#include <chrono>
#include <functional>
#include <map>
#include <memory>
#include <string>

enum class Direction {
	LEFT, UP, RIGHT, DOWN, STAY
};

class WallSensor
{
public:
	virtual ~WallSensor() = default;

	virtual bool isWall(Direction d) const = 0;
};

class DirtSensor
{
public:
	virtual ~DirtSensor() = default;

	virtual bool isDirty() const = 0;
};

class BatterySensor
{
public:
	virtual ~BatterySensor() = default;

	virtual int stepsLeft() const = 0;
};

using ConfigMap = std::map<std::string, int>;

class RobotAlgorithm
{
public:
	virtual ~RobotAlgorithm() = default;
	
	template<typename RobotRep>
	void init(RobotRep& robot, ConfigMap config)
	{
		_wallSensor = &robot.getWallSensor();
		_dirtSensor = &robot.getDirtSensor();
		_batterySensor = &robot.getBatterySensor();

		_config = std::move(config);
	}

	virtual Direction nextStep(Direction lastMove, bool& finish) = 0;

	virtual std::string const& getName() const = 0;
	virtual std::string const& getDescription() const = 0;

protected:
	WallSensor const* _wallSensor = nullptr;
	DirtSensor const* _dirtSensor = nullptr;
	BatterySensor const* _batterySensor = nullptr;

	ConfigMap _config;
};
using RobotAlgorithmUPtr = std::unique_ptr<RobotAlgorithm>;

using ScoreFunc = std::function<int(size_t dirtLeft, size_t steps, std::chrono::nanoseconds totalRunTime)>;
using ScoreSumFunc = std::function<int(std::vector<int> scores)>;

#endif
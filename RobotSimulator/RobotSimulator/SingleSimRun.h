#ifndef __SINGLE_SIM_RUN_H__
#define __SINGLE_SIM_RUN_H__

#pragma once

#include "AlgoInterface.h"
#include "House.h"
#include <functional>

class RobotAlgorithm;

class SingleSimRun : public WallSensor, public DirtSensor, public BatterySensor
{	
public:	
	SingleSimRun(RobotAlgorithm& algo, House house, ConfigMap config, ScoreFunc scoreFunc);

	int runAndScore();

	WallSensor const& getWallSensor() const { return *this; }
	DirtSensor const& getDirtSensor() const { return *this; }
	BatterySensor const& getBatterySensor() const { return *this; }

private:
	virtual bool isWall(Direction d) const override;
	virtual bool isDirty() const override;
	virtual int stepsLeft() const override;

	void cleanCurCell();
	
	RobotAlgorithm& _algo;
	House _house;
	std::map<std::string, int> _config;
	ScoreFunc _scoreFunc;

	Position _currentPos;
	size_t _curStep = 0;
};

#endif

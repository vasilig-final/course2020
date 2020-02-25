#ifndef __SIMULATION_RUNNER_H__
#define __SIMULATION_RUNNER_H__

#pragma once

#include "House.h"
#include <string>
#include <vector>

class SimulationRunner
{
public:
	SimulationRunner(std::string const& houseDir, std::vector<RobotAlgorithmUPtr> const& algorithms,
		ConfigMap const& config, ScoreFunc scoreFunc, ScoreSumFunc sumFunc);

	void runAndScoreAll(std::string const& outCsv);

	std::vector<RobotAlgorithmUPtr> const& _algorithms;
	ConfigMap const& _config;
	const ScoreFunc _scoreFunc;
	const ScoreSumFunc _sumFunc;

	std::vector<HouseUPtr> _houses;
};

#endif

// RobotSimulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Algorithms/DummyAlgorithm.h"
#include "SimulationRunner.h"
#include <fmt/format.h>
#include <numeric>


int calcScore(size_t dirtLeft, size_t steps, std::chrono::nanoseconds totalRunTime)
{
	auto score = static_cast<double>(std::numeric_limits<int>::max()) / dirtLeft / steps / totalRunTime.count();
	return static_cast<int>(round(score));
}

int sumScores(std::vector<int> scores)
{
	return static_cast<int>(std::accumulate(scores.begin(), scores.end(), 0LL) / scores.size());
}

int main()
{
	std::vector<RobotAlgorithmUPtr> algorithms;
	algorithms.push_back(std::make_unique<DummyAlgorithm>());

	ConfigMap config = {};
	SimulationRunner(R"(C:\Dev\course2020\RobotSimulator\Houses)", algorithms, config, calcScore, sumScores)
		.runAndScoreAll("out.csv");
	
	return 0;
}

#include "SimulationRunner.h"
#include "HouseLoader.h"
#include "SingleSimRun.h"
#include <filesystem>
#include <fstream>
#include <fmt/ostream.h>

namespace fs = std::filesystem;

SimulationRunner::SimulationRunner(std::string const& houseDir,
	std::vector<RobotAlgorithmUPtr> const& algorithms, ConfigMap const& config, ScoreFunc scoreFunc, ScoreSumFunc sumFunc)
	: _algorithms(algorithms), _config(config)
	, _scoreFunc(std::move(scoreFunc)), _sumFunc(std::move(sumFunc))
{
	for (auto const& p : fs::directory_iterator(houseDir))
	{
		if (!fs::is_regular_file(p) || p.path().extension().string() != ".txt")
			continue;

		auto house = HouseLoader::loadFromFile(p.path().string().c_str());
		_houses.push_back(std::move(house));
	}

	if (_houses.empty())
		throw std::runtime_error("No houses found");

	fmt::print("Simulation loaded {} algorithms and {} houses.\n", _algorithms.size(), _houses.size());
}

void SimulationRunner::runAndScoreAll(std::string const& outCsv)
{
	std::ofstream out(outCsv);

	std::vector<int> scores;
	scores.reserve(_houses.size());

	for (auto& algo : _algorithms)
	{
		fmt::print("Running algorithm '{}'...\n", algo->getName());
		
		scores.clear();
		std::transform(_houses.begin(), _houses.end(), std::back_inserter(scores), [&](auto& house) -> int {
			SingleSimRun sim(*algo, *house, _config, _scoreFunc);
			return sim.runAndScore();
		});

		auto algoScore = _sumFunc(scores);
		fmt::print(out, "{},{},{}\n", algo->getName(), algoScore, fmt::join(scores, ","));
	}
}
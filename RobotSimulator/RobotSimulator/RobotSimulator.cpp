// RobotSimulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fmt/format.h> 

/*enum class Direction
{
	Up,
	Down,
	Left,
	Right,
};

enum class StepAction
{
	Up,
	Down,
	Left,
	Right,
	Stay,
	Finish
};

struct RobotConfig
{
	unsigned int max_steps;
	unsigned int battery_capacity;
	unsigned int drain_per_step;
	unsigned int charge_per_step;
};

class ISensors
{
public:
	virtual bool isWall(Direction dir) = 0;
	virtual bool isCurrentStopClean() = 0;
};

class IAlgorithm
{
public:
	virtual StepAction getNextStep() = 0;
};

class IAlgorithmFactory
{
public:
	virtual IAlgorithm create(RobotConfig const& cfg, ISensors const& sensors) = 0;
};*/

int main()
{
    std::cout << "Hello World!\n";
	fmt::print("He{}el\n", 5);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#ifndef __DUMMY_ALGORITHM_H__
#define __DUMMY_ALGORITHM_H__

#pragma once

#include "../AlgoInterface.h"

class DummyAlgorithm : public RobotAlgorithm
{
public:
	virtual Direction nextStep(Direction lastMove, bool& finish) override;

	virtual std::string const& getName() const override { return _name; }
	virtual std::string const& getDescription() const override { return _desc; }

private:
	std::string _name = "DummyAlgorithm";
	std::string _desc = "Stays";
};

#endif

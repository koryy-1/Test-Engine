#include "Test.h"
#include <iostream>
#include "IOHandler.h"

Test::Test(Engine *engine)
{
	this->engine = engine;
	this->MaxEnginePower = 0.0f;
	this->V_atMaxEnginePower = 0.0f;
}

Test::~Test()
{
}

void Test::RunHeatingTest()
{
	std::cout << std::endl;
	std::cout << "Running heating test" << std::endl;
	std::cout << std::endl;

	std::function<bool()> stopCondition = [this]() { return StopHeatingTest(); };
	auto values = engine->start(stopCondition);

	IOHandler::printParameters(values);
	IOHandler::printEngineRunningTime(engine->getRunningTime());
}

void Test::RunMaximumPowerTest()
{
	std::cout << std::endl;
	std::cout << "Running maximum power test" << std::endl;
	std::cout << std::endl;

	std::function<bool()> stopCondition = [this]() { return StopMaximumPowerTest(); };
	auto values = engine->start(stopCondition);

	IOHandler::printParameters(values);
	IOHandler::printMaximumPower(MaxEnginePower, V_atMaxEnginePower);
}

bool Test::StopHeatingTest()
{
	return engine->isOverheated();
}

bool Test::StopMaximumPowerTest()
{
	if (MaxEnginePower < engine->getEnginePower())
	{
		MaxEnginePower = engine->getEnginePower();
		V_atMaxEnginePower = engine->getCurrentVelocity();
	}
	return engine->isAccelerationLow();
}

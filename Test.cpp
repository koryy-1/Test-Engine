#include "Test.h"
#include <iostream>

Test::Test(Engine* Engine1)
{
	this->Engine1 = Engine1;

	stopHeatingCondition = std::bind(&Test::StopHeatingTest, this);
	stopMaximumPowerCondition = std::bind(&Test::StopMaximumPowerTest, this);
}

void Test::RunHeatingTest()
{
	
	std::function<bool()> stopCondition = [this]() { return StopHeatingTest(); };
	this->Engine1->start(stopCondition);

	std::cout << std::endl;
	std::cout << "Stoping test, engine running time is " 
		<< this->Engine1->t << " seconds" << std::endl;
}

void Test::RunMaximumPowerTest()
{
	std::function<bool()> stopCondition = [this]() { return StopMaximumPowerTest(); };
	this->Engine1->start(stopCondition);

	std::cout << std::endl;
	std::cout << "Stoping test, max enigne power is " << MaxEnginePower << " kW, at a crankshaft speed of " << V_atMaxEnginePower << " radians per second" << std::endl;
}

bool Test::StopHeatingTest()
{
	if (this->Engine1->T_engine >= this->Engine1->T_overheating)
	{
		return true;
	}
	return false;
}

bool Test::StopMaximumPowerTest()
{
	if (MaxEnginePower < this->Engine1->EnignePower)
	{
		MaxEnginePower = this->Engine1->EnignePower;
		V_atMaxEnginePower = this->Engine1->cur_V;
	}
	if (this->Engine1->acceleration < 0.005)
	{
		return true;
	}
	return false;
}

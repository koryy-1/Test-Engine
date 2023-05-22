#pragma once
#include "Engine.h"
#include <functional>

class Test
{
public:
	Test(Engine *Engine1);
	
	Engine *Engine1;

	float MaxEnginePower;
	float V_atMaxEnginePower;

	void RunHeatingTest();
	void RunMaximumPowerTest();
	bool StopHeatingTest();
	bool StopMaximumPowerTest();

private:
	std::function<bool()> stopHeatingCondition;
	std::function<bool()> stopMaximumPowerCondition;
};


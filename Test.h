#pragma once
#include "Engine.h"
#include <functional>

class Test
{
public:
	Test(Engine *engine);
	~Test();
	
	void RunHeatingTest();
	void RunMaximumPowerTest();

private:
	Engine* engine;
	float MaxEnginePower;
	float V_atMaxEnginePower;

	bool StopHeatingTest();
	bool StopMaximumPowerTest();
};


#pragma once
#include <vector>

class IOHandler
{
public:
	static float readEnvironmentTemperature();
	static int chooseTestOption();
	static void printParameters(const std::vector<std::vector<float>>& values);
	static void printEngineRunningTime(float runningTime);
	static void printMaximumPower(float maxEnginePower, float crankshaftSpeed);
	static void waitForEnter();
};


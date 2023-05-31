#pragma once
#include <functional>
#include <vector>

class Engine
{
public:
	Engine(float T_environment);
	~Engine();

	std::vector<std::vector<float>> start(std::function<bool()> EndOfRunCondition);
	bool isOverheated();
	float getEnginePower();
	float getCurrentVelocity();
	bool isAccelerationLow();
	float getRunningTime();

private:
	int I;
	std::vector<int> M;
	std::vector<int> V;
	float cur_M;
	float cur_V;
	int V0;
	float acceleration;

	int T_overheating;
	float T_environment;
	float T_engine;

	float Hm;
	float Hv;
	float C;

	float time;
	float timeStep;

	float EnginePower;

	float calc_V_heating();
	float calc_V_cooling();
	float calc_delta_T_engine();

	float CalcEnginePower();
};

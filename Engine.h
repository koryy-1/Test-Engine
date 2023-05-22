#pragma once
#include <functional>

class Engine
{
public:
	Engine(float &T_environment);
	int I;
	int* M;
	int* V;
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

	float t;
	float increment;

	float EnignePower;

	void start(std::function<bool()> EndOfRunCondition);
	float calc_V_heating();
	float calc_V_cooling();
	float calc_delta_T_engine();

	float CalcEnginePower();
};

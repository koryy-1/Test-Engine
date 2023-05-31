#include "Engine.h"
#include <cmath>
#include <iostream>

Engine::Engine(float T_environment) {
	this->I = 10;
	this->M = { 20, 75, 100, 105, 75, 0 };
	this->V = { 0, 75, 150, 200, 250, 300 };

	this->cur_M = M[0];
	this->cur_V = V[0];

	this->V0 = V[0];
	this->acceleration = cur_M / I;

	this->T_overheating = 110;
	this->T_environment = T_environment;
	this->T_engine = T_environment;

	this->Hm = 0.1f;
	this->Hv = 0.0001f;
	this->C = 0.1f;

	this->EnginePower = 0.0f;

	// контролировать погрешность измерений можно с помощью значения шага
	this->timeStep = 0.1f;

	// время в течение которого работает двигатель
	this->time = 0.0f;
}

Engine::~Engine()
{
	std::vector<int>().swap(M);
	std::vector<int>().swap(V);
}

std::vector<std::vector<float>> Engine::start(std::function<bool()> EndOfRunCondition)
{
	int index1 = 0;
	int index2 = 0;
	std::vector<std::vector<float>> values;

	for (size_t i = 0; i < 5; i++)
	{
		index1 = i;
		index2 = i + 1;

		int M1 = M[index1];
		int M2 = M[index2];
		int V1 = V[index1];
		int V2 = V[index2];

		do
		{
			values.push_back({ cur_V, cur_M, acceleration, T_engine, EnginePower, time });

			T_engine += calc_delta_T_engine() * timeStep;

			EnginePower = CalcEnginePower();

			cur_V += acceleration * timeStep;

			// Вычисляем коэффициент для линейной интерполяции
			float alpha = (cur_V - V1) / (V2 - V1);

			// Вычисляем значение крутящего момента
			// с использованием интерполяции
			cur_M = M1 + alpha * (M2 - M1);

			// обновляем значение ускорения
			acceleration = cur_M / I;

			time += timeStep;

			if (EndOfRunCondition())
			{
				return values;
			}
		} while (cur_V + 0.0005f < V[i + 1]);
	}
	return values;
}

bool Engine::isOverheated()
{
	return T_engine >= T_overheating;
}

float Engine::getEnginePower()
{
	return EnginePower;
}

float Engine::getCurrentVelocity()
{
	return cur_V;
}

bool Engine::isAccelerationLow()
{
	return acceleration < 0.005f;
}

float Engine::getRunningTime()
{
	return time;
}

float Engine::calc_V_heating()
{
	return cur_M * Hm + pow(cur_V, 2) * Hv;
}

float Engine::calc_V_cooling()
{
	return C * (T_environment - T_engine);
}

float Engine::calc_delta_T_engine()
{
	return calc_V_heating() - calc_V_cooling();
}

float Engine::CalcEnginePower()
{
	return cur_M * cur_V / 1000;
}
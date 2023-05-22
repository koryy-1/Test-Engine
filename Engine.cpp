#include "Engine.h"
#include <cmath>
#include <iostream>
#include <functional>

Engine::Engine(float &T_environment) {
	this->I = 10;
	this->M = new int[6] { 20, 75, 100, 105, 75, 0 };
	this->V = new int[6] { 0, 75, 150, 200, 250, 300 };

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

	this->EnignePower = 0.0f;

	// ����� � ������� �������� �������� ���������
	this->t = 0.0f;
	// �������������� ����������� ��������� ����� � ������� �������� ����
	this->increment = 0.1f;
}

void Engine::start(std::function<bool()> EndOfRunCondition)
{
	std::cout << "Cur_V" << "\t\t\t" << "Cur_M" << "\t\t"
		<< "accel" << "\t\t" << "temp engine" << "\t\t"
		<< "enigne power" << "\t\t" << "time" << std::endl;

	int index1 = 0;
	int index2 = 0;

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
			std::cout << cur_V << "\t\t\t" << cur_M << "\t\t"
				<< acceleration << "\t\t" << T_engine << "\t\t"
				<< EnignePower << "\t\t" << t << std::endl;

			T_engine += calc_delta_T_engine() * increment;

			EnignePower = CalcEnginePower();

			cur_V += acceleration * increment;

			// ��������� ����������� ��� �������� ������������
			float alpha = (cur_V - V1) / (V2 - V1);

			// ��������� �������� ��������� ������� � �������������� ������������
			cur_M = M1 + alpha * (M2 - M1);

			// ��������� �������� ���������
			acceleration = cur_M / I;

			t += increment;

			if (EndOfRunCondition())
			{
				return;
			}
		} while (cur_V + 0.0005f < V[i + 1]);
	}
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
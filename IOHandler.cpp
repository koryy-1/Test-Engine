#include "IOHandler.h"
#include <iostream>
#include <iomanip>

float IOHandler::readEnvironmentTemperature()
{
    float temperature;
    std::cout << "Enter environment temperature in °C" << std::endl;
    std::cout << ">";
    std::cin >> temperature;
    std::cout << std::endl;

    return temperature;
}

int IOHandler::chooseTestOption()
{
    int choice;
    std::cout << "Time to choose test:" << std::endl;
    std::cout << "1 - run heating test" << std::endl;
    std::cout << "2 - run maximum power test" << std::endl;
    std::cout << ">";
    std::cin >> choice;
    std::cout << std::endl;

    return choice;
}

void IOHandler::printParameters(const std::vector<std::vector<float>>& values)
{
    std::vector<std::string> headers = {
        "Cur_V", "Cur_M", "accel", "temp engine",
        "engine power", "time"
    };
    for (const auto& header : headers) {
        std::cout << std::setw(15) << std::left << header;
    }
    std::cout << std::endl;

    for (const auto& row : values) {
        for (const auto& value : row) {
            std::cout << std::setw(15) << std::left << value;
        }
        std::cout << std::endl;
    }
}

void IOHandler::printEngineRunningTime(float runningTime)
{
    std::cout << std::endl;
    std::cout << "Stopping test, engine running time is " 
        << runningTime << " seconds" << std::endl;
}

void IOHandler::printMaximumPower(float maxEnginePower, float crankshaftSpeed)
{
    std::cout << std::endl;
    std::cout << "Stopping test, max engine power is " << maxEnginePower 
        << " kW, at a crankshaft speed of " << crankshaftSpeed 
        << " radians per second" << std::endl;
}

void IOHandler::waitForEnter()
{
    std::cout << std::endl;
    std::cout << "Press enter to exit...";
    std::cin.ignore();
    std::cin.get();
}

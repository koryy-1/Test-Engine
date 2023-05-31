#include <iostream>
#include "Engine.h"
#include "Test.h"
#include "IOHandler.h"

using namespace std;

int main()
{
    std::cout << std::endl;
    std::cout << "        ______          __     ______            _          " << std::endl;
    std::cout << "       /_  __/__  _____/ /_   / ____/___  ____ _(_)___  ___ " << std::endl;
    std::cout << "        / / / _ \\/ ___/ __/  / __/ / __ \\/ __ `/ / __ \\/ _ \\" << std::endl;
    std::cout << "       / / /  __(__  ) /_   / /___/ / / / /_/ / / / / /  __/" << std::endl;
    std::cout << "      /_/  \\___/____/\\__/  /_____/_/ /_/\\__, /_/_/ /_/\\___/ " << std::endl;
    std::cout << "                                       /____/               " << std::endl;
    std::cout << std::endl;


    float T_environment = IOHandler::readEnvironmentTemperature();

    int choice = IOHandler::chooseTestOption();

    std::unique_ptr<Engine> engine = std::make_unique<Engine>(T_environment);

    std::unique_ptr<Test> test = std::make_unique<Test>(engine.get());

    if (choice == 1)
    {
        test->RunHeatingTest();
    }
    else if (choice == 2)
    {
        test->RunMaximumPowerTest();
    }
    else
    {
        std::cout << "Invalid choice. Exiting..." << std::endl;
    }

    IOHandler::waitForEnter();

    return 0;
}

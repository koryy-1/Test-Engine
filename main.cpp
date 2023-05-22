#include <iostream>
#include "Engine.h"
#include "Test.h"

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


    float T_environment;
    cout << "enter environment temperature in °C" << endl;
    cout << ">";
    cin >> T_environment;
    std::cout << std::endl;

    int choice;
    cout << "time to choose test:" << endl;
    cout << "1 - run heating test" << endl;
    cout << "2 - run maximum power test" << endl;
    cout << ">";
    cin >> choice;
    std::cout << std::endl;

    Engine* Engine1 = new Engine(T_environment);

    Test* Test1 = new Test(Engine1);

    if (choice == 1)
    {
        Test1->RunHeatingTest();
    }
    else
    {
        Test1->RunMaximumPowerTest();
    }

    system("pause");
    delete Test1;
    delete Engine1;
    return 0;
}

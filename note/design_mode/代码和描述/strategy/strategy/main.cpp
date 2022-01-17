#include <iostream>
#include "strategyinterface.h"
using namespace std;

int main()
{
    std::shared_ptr<strategyInterface> interface = std::make_shared<strategyInterface>();
    for(int i = 0; i < 5; i++)
        interface->displayInfo(std::rand() % 4);
    return 0;
}

#include <iostream>
#include <memory>
#include <ctime>
#include "concretehandlerone.h"
#include "concretehandlertwo.h"
#include "concretehandlerthree.h"
using namespace std;

int main()
{
    shared_ptr<Handlder> one = make_shared<ConcreteHandlerOne>();
    shared_ptr<Handlder> two = make_shared<ConcreteHandlerTwo>();
    shared_ptr<Handlder> three = make_shared<ConcreteHandlerThree>();

    one->setNextHandler(two.get());
    two->setNextHandler(three.get());

    int value;
    srand((int)time(0));
    for(int i = 0; i < 5 ;i++)
    {
        value = rand() %21;
        one->handleNextRequst(value);
    }
}

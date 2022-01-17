#include <iostream>
#include "concretehandlerthree.h"

ConcreteHandlerThree::ConcreteHandlerThree()
    :m_handlder(nullptr)
{

}
ConcreteHandlerThree::~ConcreteHandlerThree()
{

}

void ConcreteHandlerThree::setNextHandler(Handlder *hdl)
{
    m_handlder = hdl;
}

void ConcreteHandlerThree::handleNextRequst(int& index)
{
    if(index < levelThree)
        std::cout << "handlerThree could deal the request  current value: " << index << std::endl;
    else
        std::cout << "rejuect the request, current value: " << index << std::endl;
}

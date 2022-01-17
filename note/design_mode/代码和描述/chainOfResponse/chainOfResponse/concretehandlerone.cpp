#include <iostream>
#include "concretehandlerone.h"

ConcreteHandlerOne::ConcreteHandlerOne()
    :m_handlder(nullptr)
{

}

ConcreteHandlerOne::~ConcreteHandlerOne()
{

}

void ConcreteHandlerOne::setNextHandler(Handlder *hdl)
{
    m_handlder = hdl;
}

void ConcreteHandlerOne::handleNextRequst(int& index)
{
    if(index < levelOne)
        std::cout << "handlerOne could deal the request  current value: " << index << std::endl;
    else if(m_handlder != nullptr)
        m_handlder->handleNextRequst(index);
}

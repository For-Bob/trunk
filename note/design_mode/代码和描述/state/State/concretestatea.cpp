#include <iostream>
#include "concretestatea.h"

using namespace std;

State* ConcreteStateA::m_pInstance = nullptr;

State* ConcreteStateA::getInstance()
{
    if(m_pInstance == nullptr)
        m_pInstance = new ConcreteStateA();

    return m_pInstance;
}

ConcreteStateA::ConcreteStateA()
{

}

void ConcreteStateA::handle(Context *c)
{
    cout << "ConcreteStateA deal the event" << endl;
    c->setState(ConcreteStateB::getInstance());
}

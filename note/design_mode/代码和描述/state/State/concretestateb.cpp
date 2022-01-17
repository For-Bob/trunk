#include <iostream>
#include "concretestateb.h"
#include "concretestatea.h"

using namespace std;

State* ConcreteStateB::m_pInstance = nullptr;

State* ConcreteStateB::getInstance()
{
    if(m_pInstance == nullptr)
        m_pInstance = new ConcreteStateB();

    return m_pInstance;
}
ConcreteStateB::ConcreteStateB()
{

}

void ConcreteStateB::handle(Context *c){
    cout << "ConcreteStateB deal the event" << endl;
    c->setState(ConcreteStateA::getInstance());
}

#include "concreteobservera.h"

ConcreteObserverA::ConcreteObserverA()
{

}

void ConcreteObserverA::update(string msg)
{
    cout << "there is observer A , copy that msg: " << msg << endl;
}

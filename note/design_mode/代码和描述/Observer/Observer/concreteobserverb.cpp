#include "concreteobserverb.h"

ConcreteObserverB::ConcreteObserverB()
{

}

void ConcreteObserverB::update(string msg)
{
    cout << "there is observer B , copy that msg: " << msg << endl;
}

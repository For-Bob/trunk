#ifndef CONCRETEOBSERVERA_H
#define CONCRETEOBSERVERA_H

#include "observer.h"

class ConcreteObserverA : public Observer
{
public:
    ConcreteObserverA();
    ~ConcreteObserverA(){}
    void update(string msg);
};

#endif // CONCRETEOBSERVERA_H

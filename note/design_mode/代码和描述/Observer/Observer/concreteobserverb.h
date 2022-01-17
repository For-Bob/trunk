#ifndef CONCRETEOBSERVERB_H
#define CONCRETEOBSERVERB_H

#include "observer.h"

class ConcreteObserverB : public Observer
{
public:
    ConcreteObserverB();
    ~ConcreteObserverB(){}
    void update(string msg);
};

#endif // CONCRETEOBSERVERB_H

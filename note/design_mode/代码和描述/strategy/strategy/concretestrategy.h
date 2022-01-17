#ifndef CONCRETESTRATEGY_H
#define CONCRETESTRATEGY_H

#include "abstructstrategy.h"

class ConcreteStrategy: public AbstructStrategy
{
public:
    ConcreteStrategy();
    ~ConcreteStrategy();
    void displayInfo();
};

#endif // CONCRETESTRATEGY_H

#ifndef ABSTRUCTSTRATEGY_H
#define ABSTRUCTSTRATEGY_H

#include <iostream>

class AbstructStrategy
{
public:
    AbstructStrategy();
    virtual ~AbstructStrategy(){}
    virtual void displayInfo() = 0;
};

#endif // ABSTRUCTSTRATEGY_H

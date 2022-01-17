#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include <string>
#include "subject.h"

using namespace std;
class Observer
{
public:
    Observer();
    virtual ~Observer();
    virtual void update(string msg) = 0;

};

#endif // OBSERVER_H

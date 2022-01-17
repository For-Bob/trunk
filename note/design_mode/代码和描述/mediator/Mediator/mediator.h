#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <iostream>
#include <string>
#include "colleague.h"

using namespace std;
class Colleague;
class Mediator
{
public:
    Mediator();
    virtual ~Mediator(){}
    virtual void operation(int, string) = 0;
    virtual void setColleague(Colleague* ,int) = 0;
};

#endif // MEDIATOR_H

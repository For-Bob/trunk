#ifndef CONCRETEMEDIATOR_H
#define CONCRETEMEDIATOR_H

#include <map>
#include "mediator.h"

class ConcreteMediator : public Mediator
{
public:
    ConcreteMediator();
    ~ConcreteMediator(){}
    void operation(int, string);
    void setColleague(Colleague*, int);
private:
    map<int,Colleague*> m_MapMemeber;
};

#endif // CONCRETEMEDIATOR_H

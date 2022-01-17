#ifndef COLLEAGUE_H
#define COLLEAGUE_H

#include <iostream>
#include <string>
#include "mediator.h"

using namespace std;
class Mediator;
class Colleague
{
public:
    Colleague();
    virtual ~Colleague(){}
    virtual void receiveMsg(string) = 0;
    virtual void sendMsg(int, string) = 0;
    virtual void setMediator(Mediator*) = 0;
protected:
    Mediator* m_pMediator;
};

#endif // COLLEAGUE_H

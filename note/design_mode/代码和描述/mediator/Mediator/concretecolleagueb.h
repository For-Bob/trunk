#ifndef CONCRETECOLLEAGUEB_H
#define CONCRETECOLLEAGUEB_H

#include "colleague.h"

class ConcreteColleagueB : public Colleague
{
public:
    ConcreteColleagueB();
    ~ConcreteColleagueB(){}
    void receiveMsg(string) ;
    void sendMsg(int, string) ;
    void setMediator(Mediator*) ;
private:
//    Mediator* m_pMediator;
};

#endif // CONCRETECOLLEAGUEB_H

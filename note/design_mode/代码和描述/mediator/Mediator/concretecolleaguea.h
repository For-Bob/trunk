#ifndef CONCRETECOLLEAGUEA_H
#define CONCRETECOLLEAGUEA_H

#include "colleague.h"

class ConcreteColleagueA : public Colleague
{
public:
    ConcreteColleagueA();
    ~ConcreteColleagueA(){}
    void receiveMsg(string) ;
    void sendMsg(int, string) ;
    void setMediator(Mediator*) ;
private:
//    Mediator* m_pMediator;

};

#endif // CONCRETECOLLEAGUEA_H

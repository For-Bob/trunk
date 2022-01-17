#ifndef CONCRETESTATEB_H
#define CONCRETESTATEB_H

#include "state.h"

class ConcreteStateB: public State
{
public:
    static State* getInstance();
    ~ConcreteStateB(){}
    void handle(Context *);
private:
    ConcreteStateB();
    static State*  m_pInstance;
};
#endif // CONCRETESTATEB_H

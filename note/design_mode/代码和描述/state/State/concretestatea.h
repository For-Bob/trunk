#ifndef CONCRETESTATEA_H
#define CONCRETESTATEA_H

#include "state.h"
#include "concretestateb.h"

class ConcreteStateB;
class ConcreteStateA: public State
{
public:
    static State* getInstance();
    ~ConcreteStateA(){}
    void handle(Context *);
private:
    ConcreteStateA();
    static State*  m_pInstance;
};

#endif // CONCRETESTATEA_H

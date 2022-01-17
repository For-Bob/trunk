#ifndef CONCRETEHANDLERTHREE_H
#define CONCRETEHANDLERTHREE_H

#include "handlder.h"

class ConcreteHandlerThree : public Handlder
{
public:
    ConcreteHandlerThree();
    ~ConcreteHandlerThree();
    void setNextHandler(Handlder* hdl);
    void handleNextRequst(int& index);
private:
    Handlder*   m_handlder;
};

#endif // CONCRETEHANDLERTHREE_H

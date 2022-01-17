#ifndef CONCRETEHANDLERTWO_H
#define CONCRETEHANDLERTWO_H

#include "handlder.h"

class ConcreteHandlerTwo : public Handlder
{
public:
    ConcreteHandlerTwo();
    ~ConcreteHandlerTwo();
    void setNextHandler(Handlder* hdl);
    void handleNextRequst(int& index);
private:
    Handlder*   m_handlder;
};

#endif // CONCRETEHANDLERTWO_H

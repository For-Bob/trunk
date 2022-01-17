#ifndef CONCRETEHANDLERONE_H
#define CONCRETEHANDLERONE_H

#include "handlder.h"

class ConcreteHandlerOne : public Handlder
{
public:
    ConcreteHandlerOne();
    ~ConcreteHandlerOne();
    void setNextHandler(Handlder* hdl);
    void handleNextRequst(int& index);
private:
    Handlder*   m_handlder;
};

#endif // CONCRETEHANDLERONE_H

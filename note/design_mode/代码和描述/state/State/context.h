#ifndef CONTEXT_H
#define CONTEXT_H

#include "state.h"

class State;

class Context
{
public:
    Context();
    ~Context(){}
    void request();
    void setState(State* );
private:
    State* m_pState;
};

#endif // CONTEXT_H

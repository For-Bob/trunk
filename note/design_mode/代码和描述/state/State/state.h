#ifndef STATE_H
#define STATE_H

#include "context.h"
class Context;
class State
{
public:
    State();
    virtual ~State(){}
    virtual void handle(Context *) = 0;
};

#endif // STATE_H

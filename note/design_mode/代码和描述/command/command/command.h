#ifndef COMMAND_H
#define COMMAND_H

#include "receiver.h"

class Command
{
public:
    Command();
    virtual ~Command(){}
    virtual void execute(string com) = 0;
    virtual void setReceiver(Receiver *rev) = 0;
};

#endif // COMMAND_H

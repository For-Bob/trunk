#ifndef CONCRETECOMMAND_H
#define CONCRETECOMMAND_H

#include <map>
#include "command.h"

class Receiver;
class ConcreteCommand : public Command
{
public:
    ConcreteCommand();
    ~ConcreteCommand(){}
    void execute(string com);
    void setReceiver(Receiver* rev);
private:
    Receiver* m_pReceiver;
    map<string,string> m_StoSOrder;
};

#endif // CONCRETECOMMAND_H

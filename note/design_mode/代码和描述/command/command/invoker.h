#ifndef INVOKER_H
#define INVOKER_H
#include <string>

#include "command.h"
using namespace std;
class Invoker
{
public:
    Invoker();
    ~Invoker(){}
    void setCommand(Command* com);
    void call(string ord);
private:
    Command* m_pCommand;
};

#endif // INVOKER_H

#include <map>
#include "invoker.h"

Invoker::Invoker()
{

}

void Invoker::setCommand(Command *com)
{
    if(com != nullptr)
        m_pCommand = com;
}

void Invoker::call(string ord)
{
    cout << "root: " << ord << endl;
    m_pCommand->execute(ord);
}


#include "concretecolleaguea.h"

ConcreteColleagueA::ConcreteColleagueA()
{

}

void ConcreteColleagueA::receiveMsg(string str)
{
    cout << " ConcreteColleagueA receiveMsg :" << str << endl;
}

void ConcreteColleagueA::sendMsg(int who, string str)
{
    cout << " ConcreteColleagueA sendMsg :" << str << endl;
    m_pMediator->operation(who, str);
}

void ConcreteColleagueA::setMediator(Mediator *mdt)
{
    if(mdt != nullptr)
        m_pMediator = mdt;
}

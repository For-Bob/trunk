#include "concretecolleagueb.h"

ConcreteColleagueB::ConcreteColleagueB()
{

}

void ConcreteColleagueB::receiveMsg(string str)
{
    cout << " ConcreteColleagueB receiveMsg :" << str << endl;
}

void ConcreteColleagueB::sendMsg(int who, string str)
{
    cout << " ConcreteColleagueB sendMsg :" << str << endl;
    m_pMediator->operation(who, str);
}

void ConcreteColleagueB::setMediator(Mediator *mdt)
{
    if(mdt != nullptr)
        m_pMediator = mdt;
}

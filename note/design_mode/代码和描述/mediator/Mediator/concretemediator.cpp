#include "concretemediator.h"

ConcreteMediator::ConcreteMediator()
{

}

void ConcreteMediator::operation(int who, string msg)
{
    map<int, Colleague*>::iterator it = m_MapMemeber.find(who);
    it->second->receiveMsg(msg);
}

void ConcreteMediator::setColleague(Colleague *col,int who)
{
//    m_MapMemeber.insert(make_pair<int,Colleague*>(who,col));
    m_MapMemeber[who] = col;
}

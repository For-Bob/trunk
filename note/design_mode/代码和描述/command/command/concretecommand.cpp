#include "concretecommand.h"

ConcreteCommand::ConcreteCommand()
    :m_pReceiver(nullptr)
{
    m_StoSOrder.insert(make_pair("ls","list the file and dir of the current list"));
    m_StoSOrder.insert(make_pair("top","current situation of the cpu"));
    m_StoSOrder.insert(make_pair("pwd","current file path"));

}

void ConcreteCommand::execute(string com)
{
    map<string,string>::iterator it = m_StoSOrder.find(com);
    string msg = it->second;
    m_pReceiver->action(msg);
}

void ConcreteCommand::setReceiver(Receiver *rev)
{
    if(rev != nullptr)
        m_pReceiver = rev;
}

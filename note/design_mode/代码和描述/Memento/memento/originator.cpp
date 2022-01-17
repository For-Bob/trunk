#include "originator.h"

originator::originator()
    :m_status("")
{

}

void originator::setStatus(std::string status)
{
    m_status = status;
}

memento* originator::createMemento(){
    return new memento(m_status);
}

void originator::displayStatus()
{
    std::cout << "current status: " << m_status << std::endl;
}

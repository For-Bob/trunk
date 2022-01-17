#include "memento.h"

memento::memento(std::string state)
{
    m_state = state;
}

void memento::setState(std::string state)
{
    m_state = state;
}

std::string memento::getState()
{
    return m_state;
}

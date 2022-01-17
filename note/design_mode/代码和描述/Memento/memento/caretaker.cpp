#include "caretaker.h"

careTaker::careTaker()
    :m_Memento(nullptr)
{

}

void careTaker::setMemento(memento *me)
{
    if(m_Memento != nullptr)
    {
        delete m_Memento;
        m_Memento = nullptr;
    }
    if(m_Memento == nullptr)
    {
        m_Memento = me;
    }
}

memento* careTaker::getMemento()
{
    return m_Memento;
}

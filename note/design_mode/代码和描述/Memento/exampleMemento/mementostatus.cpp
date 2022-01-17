#include "mementostatus.h"

mementoStatus::mementoStatus()
{

}

void mementoStatus::setPerson(personInfo person)
{
    m_detail = person;
}

mementoStatus::personInfo mementoStatus::getPerson()
{
    return m_detail;
}

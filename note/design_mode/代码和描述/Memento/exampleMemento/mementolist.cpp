#include "mementolist.h"

mementoList::mementoList()    
{

}

mementoList::~mementoList()
{
    m_personList.clear();
}

void mementoList::saveProgress(mementoStatus *status)
{
    m_personList.push_back(status);
}

mementoStatus* mementoList::getProgress(unsigned int index)
{
    if(index < m_personList.size())
        return m_personList.at(index);
    else
        return nullptr;
}

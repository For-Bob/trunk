#ifndef MEMENTOLIST_H
#define MEMENTOLIST_H

#include <vector>
#include "mementostatus.h"
class mementoStatus;
class mementoList
{
public:
    mementoList();
    ~mementoList();
    void saveProgress(mementoStatus* status);
    mementoStatus* getProgress(unsigned int index);
private:
    std::vector<mementoStatus*> m_personList;
};

#endif // MEMENTOLIST_H

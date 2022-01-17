#ifndef ORIGINATOR_H
#define ORIGINATOR_H

#include "memento.h"
class memento;
class originator
{
public:
    originator();
    ~originator(){}
    void setStatus(std::string status);
    memento* createMemento();
    void displayStatus();
private:
    std::string m_status;
};

#endif // ORIGINATOR_H

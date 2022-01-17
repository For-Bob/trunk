#ifndef CARETAKER_H
#define CARETAKER_H

#include "memento.h"
class careTaker
{
public:
    careTaker();
    ~careTaker(){}
    void setMemento(memento* me);
    memento* getMemento();
private:
    memento* m_Memento;
};

#endif // CARETAKER_H

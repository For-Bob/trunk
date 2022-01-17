#ifndef MEMENTO_H
#define MEMENTO_H
#include <iostream>

class memento
{
public:
    memento(std::string state);
    ~memento(){}
    void setState(std::string state);
    std::string getState();
private:
    std::string m_state;
};

#endif // MEMENTO_H

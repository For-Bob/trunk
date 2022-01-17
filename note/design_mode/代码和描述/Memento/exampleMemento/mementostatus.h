#ifndef MEMENTOSTATUS_H
#define MEMENTOSTATUS_H

#include <iostream>

using namespace std;

class mementoStatus
{
public:
    struct personInfo
    {
        string name;
        int level;
        int damage;
        int defensive;
        int money;
        personInfo()
            :name(""), level(0), damage(0), defensive(0), money(0)
        {}
    };
public:
    mementoStatus();
    ~mementoStatus(){}
    void setPerson(personInfo person);
    personInfo getPerson();
private:
    personInfo m_detail;
};

#endif // MEMENTOSTATUS_H

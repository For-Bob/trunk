#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <memory>
#include <vector>

#include "observer.h"

using namespace std;
class Observer;
class Subject
{
public:
    Subject();
    ~Subject();
    void addObserver(Observer* ob);
    void delObserver(Observer* ob);
    void update(string msg);

private:
    vector<Observer*> m_pObserver;
//   list<Observer>* m_pObserver;
};

#endif // SUBJECT_H

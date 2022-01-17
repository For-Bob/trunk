#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>
#include <memory>

using namespace std;

class SingleTon
{
public:
    static shared_ptr<SingleTon> Instance();
    static SingleTon* normalInstance();
    ~SingleTon();

    void display(string std);

    static shared_ptr<SingleTon> m_Instance;
    static SingleTon* m_noramlInstance;
private:
    SingleTon();
};

#endif // SINGLETON_H

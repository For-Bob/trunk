#ifndef CAKE_H
#define CAKE_H

#include <iostream>
#include <string>

using namespace std;

class Cake
{
public:
    Cake();
    virtual ~Cake();
    virtual void showCake() = 0;
public:
    string m_cake;
};

#endif // CAKE_H

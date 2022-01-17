#ifndef TECENT_H
#define TECENT_H

#include <iostream>

using namespace std;

class Tecent
{
public:
    Tecent();
    virtual ~Tecent();
    virtual void login(string name, string password) = 0;
    virtual void play() = 0;
};

#endif // TECENT_H

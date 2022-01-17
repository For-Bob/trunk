#ifndef RECEIVER_H
#define RECEIVER_H

#include <iostream>
#include <string>

using namespace std;

class Receiver
{
public:
    Receiver();
    ~Receiver(){}
    void action(string msg);
};

#endif // RECEIVER_H

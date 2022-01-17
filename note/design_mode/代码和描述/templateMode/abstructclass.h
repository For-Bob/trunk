#ifndef ABSTRUCTCLASS_H
#define ABSTRUCTCLASS_H

#include <iostream>

using namespace std;

class AbstructClass
{
public:
    AbstructClass();
    virtual ~AbstructClass();
    void run();
    bool init();
    virtual void OneAndOne() = 0;
    void end();
};

#endif // ABSTRUCTCLASS_H

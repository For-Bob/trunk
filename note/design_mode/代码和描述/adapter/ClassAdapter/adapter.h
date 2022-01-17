#ifndef ADAPTER_H
#define ADAPTER_H

#include "adaptee.h"
#include "target.h"

class Adapter : public Target, private Adaptee
{
public:
    Adapter();
    ~Adapter();

    void request();

};

#endif // ADAPTER_H

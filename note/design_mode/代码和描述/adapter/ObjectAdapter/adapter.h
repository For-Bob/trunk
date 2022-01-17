#ifndef ADAPTER_H
#define ADAPTER_H

#include <iostream>
#include <memory>
#include "adaptee.h"
#include "target.h"

class Adapter: public Target
{
public:
    Adapter();
    ~Adapter();

    void request();
private:
    std::shared_ptr <Adaptee> pointer;
};

#endif // ADAPTER_H

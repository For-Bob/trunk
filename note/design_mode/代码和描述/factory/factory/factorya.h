#ifndef FACTORYA_H
#define FACTORYA_H

#include "abstructfactory.h"

class FactoryA: public AbstructFactory
{
public:
    FactoryA();
    ~FactoryA();
    shared_ptr<AbstructProduct> createProduct();
};

#endif // FACTORYA_H

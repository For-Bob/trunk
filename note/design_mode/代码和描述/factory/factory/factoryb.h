#ifndef FACTORYB_H
#define FACTORYB_H

#include "abstructfactory.h"
#include "productb.h"

class FactoryB: public AbstructFactory
{
public:
    FactoryB();
    ~FactoryB();
    shared_ptr<AbstructProduct> createProduct();
};

#endif // FACTORYB_H

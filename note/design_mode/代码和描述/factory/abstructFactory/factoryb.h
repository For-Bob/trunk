#ifndef FACTORYB_H
#define FACTORYB_H

#include "abstructfactroy.h"
#include "prokproduct.h"
#include "peanutproduct.h"

class factoryB: public abstructFactroy
{
public:
    factoryB();
    ~factoryB();
    std::shared_ptr <abstructFruitProduct> createFruitProduct();
    std::shared_ptr <abstructMeatProduct> createMeatProduct();

};

#endif // FACTORYB_H

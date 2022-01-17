#ifndef FACTORYA_H
#define FACTORYA_H

#include "abstructfactroy.h"
#include "leekproduct.h"
#include "chickenproduct.h"

class factoryA : public abstructFactroy
{
public:
    factoryA();
    ~factoryA();

    std::shared_ptr <abstructFruitProduct> createFruitProduct();
    std::shared_ptr <abstructMeatProduct> createMeatProduct();
};

#endif // FACTORYA_H

#ifndef ABSTRUCTFACTROY_H
#define ABSTRUCTFACTROY_H

#include <iostream>
#include <memory>

#include "abstructfruitproduct.h"
#include "abstructmeatproduct.h"

class abstructFactroy
{
public:
    abstructFactroy();
    virtual ~abstructFactroy();
    virtual std::shared_ptr <abstructFruitProduct> createFruitProduct() = 0;
    virtual std::shared_ptr <abstructMeatProduct> createMeatProduct() = 0;

};

#endif // ABSTRUCTFACTROY_H

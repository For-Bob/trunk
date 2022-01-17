#ifndef ABSTRUCTMEATPRODUCT_H
#define ABSTRUCTMEATPRODUCT_H

#include <qdebug.h>

class abstructMeatProduct
{
public:
    abstructMeatProduct();
    virtual ~abstructMeatProduct();
    virtual void displayProduct() = 0;
};

#endif // ABSTRUCTMEATPRODUCT_H

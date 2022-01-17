#ifndef CHICKENPRODUCT_H
#define CHICKENPRODUCT_H

#include "abstructmeatproduct.h"

class chickenProduct: public abstructMeatProduct
{
public:
    chickenProduct();
    ~chickenProduct();
    void displayProduct();
};

#endif // CHICKENPRODUCT_H

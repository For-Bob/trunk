#ifndef ABSTRUCTFRUITPRODUCT_H
#define ABSTRUCTFRUITPRODUCT_H

#include <qdebug.h>

class abstructFruitProduct
{
public:
    abstructFruitProduct();
    virtual ~abstructFruitProduct();
    virtual void displayProduct() = 0;
};

#endif // ABSTRUCTFRUITPRODUCT_H

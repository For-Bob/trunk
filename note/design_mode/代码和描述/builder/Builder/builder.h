#ifndef BUILDER_H
#define BUILDER_H

#include "product.h"

class Product;
class Builder
{
public:
    Builder();
    virtual ~Builder(){}
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;
    virtual void buildPartD() = 0;
    virtual Product* getResult() = 0;
};

#endif // BUILDER_H

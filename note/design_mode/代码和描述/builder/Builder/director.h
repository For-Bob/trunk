#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "builder.h"
#include "product.h"
class Builder;
class Product;
class Director
{
public:
    Director();
    ~Director(){}
    void setBuilder(Builder *);
    Product* constructProduct();
private:
    Builder* m_pBuilder;
};

#endif // DIRECTOR_H

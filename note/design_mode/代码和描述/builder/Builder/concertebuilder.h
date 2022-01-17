#ifndef CONCERTEBUILDER_H
#define CONCERTEBUILDER_H
#include <iostream>
#include <memory>
#include "builder.h"
using namespace std;
class Product;
class ConcerteBuilder: public Builder
{
public:
    ConcerteBuilder();
    ~ConcerteBuilder(){}
    void buildPartA();
    void buildPartB();
    void buildPartC();
    void buildPartD();
    Product* getResult();
private:
    shared_ptr<Product> m_pProduct;
};

#endif // CONCERTEBUILDER_H

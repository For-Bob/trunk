#include "factorya.h"

FactoryA::FactoryA()
{

}

FactoryA::~FactoryA(){

}

shared_ptr<AbstructProduct> FactoryA::createProduct(){
    shared_ptr<AbstructProduct> Product = make_shared<ProductA>();
    return Product;
}

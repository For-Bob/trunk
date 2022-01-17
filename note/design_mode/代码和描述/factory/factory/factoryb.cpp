#include "factoryb.h"

FactoryB::FactoryB()
{

}

FactoryB::~FactoryB(){

}

shared_ptr<AbstructProduct> FactoryB::createProduct(){
    shared_ptr<AbstructProduct> Product = make_shared<ProductB>();
    return Product;
}

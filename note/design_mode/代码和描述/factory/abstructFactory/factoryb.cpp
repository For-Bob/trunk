#include "factoryb.h"

factoryB::factoryB()
{

}

factoryB::~factoryB(){

}

std::shared_ptr<abstructFruitProduct> factoryB::createFruitProduct(){
    std::shared_ptr<abstructFruitProduct> fruit = std::make_shared<peanutProduct>();
    return  fruit;
}

std::shared_ptr<abstructMeatProduct> factoryB::createMeatProduct(){
    std::shared_ptr<abstructMeatProduct> meat = std::make_shared<prokProduct>();
    return meat;
}

#include "factorya.h"

factoryA::factoryA()
{

}

factoryA::~factoryA(){

}

std::shared_ptr <abstructFruitProduct> factoryA::createFruitProduct(){
    std::shared_ptr<abstructFruitProduct> fruitProduct = std::make_shared<leekProduct>();

    return fruitProduct;
}
std::shared_ptr <abstructMeatProduct> factoryA::createMeatProduct(){
    std::shared_ptr <abstructMeatProduct> meatProduct = std::make_shared<chickenProduct>();
    return meatProduct;
}

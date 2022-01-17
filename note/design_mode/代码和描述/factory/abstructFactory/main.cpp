#include <QCoreApplication>

#include "factorya.h"
#include "factoryb.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::shared_ptr <abstructFactroy> factory = std::make_shared<factoryA>();
    std::shared_ptr<abstructMeatProduct> meat =  factory->createMeatProduct();
    std::shared_ptr<abstructFruitProduct> fruit = factory->createFruitProduct();

    meat->displayProduct();
    fruit->displayProduct();
    factory.reset();
    factory = std::make_shared<factoryB>();
    meat =  factory->createMeatProduct();
    fruit = factory->createFruitProduct();
    meat->displayProduct();
    fruit->displayProduct();


    return a.exec();
}

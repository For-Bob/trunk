#include <QCoreApplication>
#include "factorya.h"
#include "factoryb.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    shared_ptr<AbstructFactory> factroy = make_shared<FactoryA>();
    shared_ptr<AbstructProduct> product= factroy->createProduct();
    product->showProduct();

    factroy.reset();
    product.reset();

    factroy = make_shared<FactoryB>();
    product= factroy->createProduct();
    product->showProduct();

    return a.exec();
}

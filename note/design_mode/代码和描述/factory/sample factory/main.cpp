#include <QCoreApplication>
#include "samplefactory.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    shared_ptr<SampleFactory> factory= make_shared<SampleFactory>();
    shared_ptr<AbstructProduct> product = factory->createProduct(1);
    product->showProduct();

    product = factory->createProduct(2);
    product->showProduct();

    return a.exec();
}

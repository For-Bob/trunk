#include <iostream>
#include "concertebuilder.h"
#include "director.h"
#include "product.h"
using namespace std;

int main()
{
    shared_ptr<Builder> bld = make_shared<ConcerteBuilder>();
    shared_ptr<Director> dir = make_shared<Director>();
    dir->setBuilder(bld.get());
    Product* product =  dir->constructProduct();
    product->show();
    return 0;
}

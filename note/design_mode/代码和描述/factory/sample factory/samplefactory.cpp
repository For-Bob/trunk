#include "samplefactory.h"

SampleFactory::SampleFactory(){

}

SampleFactory::~SampleFactory(){

}

shared_ptr<AbstructProduct> SampleFactory::createProduct(int type){
   shared_ptr<AbstructProduct> product;
    switch (type) {
        case 1:
//            product = new ProductA();
        product = make_shared<ProductA>();
        break;

        case 2:
        product = make_shared<ProductB>();
        break;


    }
    return product;
}

#ifndef ABSTRUCTFACTORY_H
#define ABSTRUCTFACTORY_H

#include <iostream>
#include <memory>

#include "abstructproduct.h"
#include "producta.h"
#include "productb.h"

using namespace std;

class AbstructFactory
{
public:
    AbstructFactory();
    ~AbstructFactory();
    virtual shared_ptr<AbstructProduct> createProduct();
};

#endif // ABSTRUCTFACTORY_H

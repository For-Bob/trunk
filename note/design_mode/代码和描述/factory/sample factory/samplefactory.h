#ifndef SAMPLEFACTORY_H
#define SAMPLEFACTORY_H

#include <memory>
#include <iostream>

#include "producta.h"
#include "productb.h"
using namespace std;

class SampleFactory{
public:
    SampleFactory();
    ~SampleFactory();
    shared_ptr<AbstructProduct> createProduct(int type);
};

#endif // SAMPLEFACTORY_H

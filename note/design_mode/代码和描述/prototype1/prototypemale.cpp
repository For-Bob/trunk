#include "prototypemale.h"

PrototypeMale::PrototypeMale()
{

}

PrototypeMale::~PrototypeMale(){

}

Prototype * PrototypeMale::clone(){
    Prototype * pointer = new PrototypeMale();
    *pointer = *this;
    return pointer;
}

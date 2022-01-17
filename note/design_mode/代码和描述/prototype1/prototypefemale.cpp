#include "prototypefemale.h"

PrototypeFemale::PrototypeFemale()
{

}

PrototypeFemale::~PrototypeFemale(){

}

Prototype * PrototypeFemale::clone(){
    Prototype* pointer = new PrototypeFemale();
    *pointer = *this;
    return pointer;
}

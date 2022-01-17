#ifndef PROTOTYPEMALE_H
#define PROTOTYPEMALE_H

#include "prototype.h"

class PrototypeMale: public Prototype
{
public:
    PrototypeMale();
    ~PrototypeMale();
    Prototype * clone();
};

#endif // PROTOTYPEMALE_H

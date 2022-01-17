#ifndef PROTOTYPEFEMALE_H
#define PROTOTYPEFEMALE_H

#include "prototype.h"

class PrototypeFemale: public Prototype
{
public:
    PrototypeFemale();
    ~PrototypeFemale();

    Prototype* clone();
};

#endif // PROTOTYPEFEMALE_H

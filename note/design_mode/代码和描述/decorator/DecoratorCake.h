#ifndef DECORATORCAKE_H
#define DECORATORCAKE_H

#include <memory>

#include "Cake.h"

class DecoratorCake: public Cake
{
public:
    DecoratorCake();
    virtual ~DecoratorCake();

public:
    Cake* m_pCake;
};

#endif // DECORATORCAKE_H

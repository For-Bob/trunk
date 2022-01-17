#ifndef MIKEDECORATORCAKE_H
#define MIKEDECORATORCAKE_H

#include "DecoratorCake.h"

class mikeDecoratorCake: public DecoratorCake
{
public:
    mikeDecoratorCake(Cake* pCake);
    ~mikeDecoratorCake();
    void showCake();
};

#endif // MIKEDECORATORCAKE_H

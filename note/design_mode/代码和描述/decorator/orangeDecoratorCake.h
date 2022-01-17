#ifndef ORANGEDECORATORCAKE_H
#define ORANGEDECORATORCAKE_H

#include "DecoratorCake.h"

class orangeDecoratorCake: public DecoratorCake
{
public:
    orangeDecoratorCake(Cake* pCake);
    ~orangeDecoratorCake();
    void showCake();
};

#endif // ORANGEDECORATORCAKE_H

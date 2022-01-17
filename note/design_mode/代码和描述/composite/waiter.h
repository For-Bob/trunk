#ifndef WAITER_H
#define WAITER_H

#include "compositemenu.h"

class waiter
{
public:
    waiter(compositeMenu* menu);
    ~waiter();
    void display();
private:
    compositeMenu* m_menu;
};

#endif // WAITER_H

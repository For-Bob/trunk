#ifndef COMPOSITEMENU_H
#define COMPOSITEMENU_H

#include <iostream>
#include <string>

using namespace std;

class compositeMenu
{
public:
    compositeMenu();
    virtual ~compositeMenu();
    virtual int add(compositeMenu* menu);
    virtual int remove(compositeMenu* menu);
    virtual string getName();
    virtual string getDescrible();
    virtual double getPrice();
    virtual compositeMenu* getChild(int index);
    virtual void display();
};

#endif // COMPOSITEMENU_H

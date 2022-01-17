#ifndef LEAFMENU_H
#define LEAFMENU_H

#include "compositemenu.h"

class leafMenu : public compositeMenu
{
public:
    leafMenu();
    leafMenu(string name, string describle, double price);
    ~leafMenu();
    string getName();
    string getDescrible();
    double getPrice();
    void display();
private:
    string m_name;
    string m_describle;
    double m_price;
};

#endif // LEAFMENU_H

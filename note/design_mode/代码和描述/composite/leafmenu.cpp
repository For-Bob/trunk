#include "leafmenu.h"

leafMenu::leafMenu()
{

}

leafMenu::leafMenu(string name, string describle, double price)
    :m_name(name)
    ,m_describle(describle)
    ,m_price(price)
{
}

leafMenu::~leafMenu()
{

}
string leafMenu::getName()
{
    return m_name;
}
string leafMenu::getDescrible()
{
    return m_describle;
}
double leafMenu::getPrice()
{
    return m_price;
}
void leafMenu::display()
{
    cout << "name--" << getName() << ": price--" << getPrice() << ": describle--" << getDescrible() << endl;
}

#ifndef MENUITEM_H
#define MENUITEM_H

#include <vector>
#include "compositemenu.h"

class menuItem : public compositeMenu
{
public:
    menuItem();
    menuItem(string name, string describle);
    ~menuItem();
    int add(compositeMenu* menu);
    int remove(compositeMenu* menu);
    string getName();
    string getDescrible();
    compositeMenu* getChild(int index);
    void display();
private:
    string m_name;
    string m_describle;
    vector<compositeMenu*> m_item;
};

#endif // MENUITEM_H

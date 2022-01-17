#include "menuitem.h"

menuItem::menuItem()
{
    m_item.clear();
}

menuItem::menuItem(string name, string describle)
    :m_name(name)
    ,m_describle(describle)
{
    m_item.clear();
}
menuItem::~menuItem(){
    m_item.clear();
}
int menuItem::add(compositeMenu* menu){
    m_item.push_back(menu);
    return 1;
}
int menuItem::remove(compositeMenu* menu){
    for(vector<compositeMenu*>::iterator it = m_item.begin(); it != m_item.end(); it++)
    {
        if(*it == menu){
            m_item.erase(it, it+2);//这里为什么是it到it+2，早餐，午餐和晚餐，下面都是两个种类的食物
            break;
        }
    }
    return 1;
}
string menuItem::getName(){
    return m_name;
}
string menuItem::getDescrible(){
    return m_describle;
}
compositeMenu* menuItem::getChild(int index){
    if(index < m_item.size())
        return m_item.at(index);
    else
        return nullptr;
}
void menuItem::display(){
    cout << "name--" << getName() << ": describle--" << getDescrible() << endl;
    for(vector<compositeMenu*>::iterator it = m_item.begin(); it != m_item.end(); it++)
    {
        compositeMenu* menu = *it;
        menu->display();
    }

}

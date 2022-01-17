#include "waiter.h"

waiter::waiter(compositeMenu* menu)
    :m_menu(menu)
{

}
waiter::~waiter(){

}
void waiter::display(){
    m_menu->display();
}

#include <iostream>
#include <memory>

#include "waiter.h"
#include "leafmenu.h"
#include "menuitem.h"

using namespace std;

int main()
{
    shared_ptr<compositeMenu> milk = make_shared<leafMenu>("milk","the white liquid produced by cows", 2);
    shared_ptr<compositeMenu> egg = make_shared<leafMenu>("egg", "a small oval object", 1);

    shared_ptr<compositeMenu> breakfast = make_shared<menuItem>("breakfast", "you can get enough nutrition from breakfast ");

    breakfast->add(milk.get());
    breakfast->add(egg.get());

    shared_ptr<compositeMenu> beaf = make_shared<leafMenu>("beaf","Beef is the meat of a cow", 30);
    shared_ptr<compositeMenu> beer = make_shared<leafMenu>("beer", "Beer is a bitter alcoholic drink made from grain", 5);

    shared_ptr<compositeMenu> lunch = make_shared<menuItem>("lunch", "you can get enough energe from lunch ");

    lunch->add(beaf.get());
    lunch->add(beer.get());

    shared_ptr<compositeMenu> tomatoes = make_shared<leafMenu>("tomatoes","Tomatoes are small, soft, red fruit", 1);
    shared_ptr<compositeMenu> rice = make_shared<leafMenu>("rice", "narrow white or brown grain grown on wet land in hot countries as food", 0.5);

    shared_ptr<compositeMenu> dinner = make_shared<menuItem>("dinner", "after eat dinner you can go sleep");

    dinner->add(tomatoes.get());
    dinner->add(rice.get());

    shared_ptr<compositeMenu> meun = make_shared<menuItem>("menu", "this is complete menu");
    meun->add(breakfast.get());
    meun->add(lunch.get());
    meun->add(dinner.get());

    shared_ptr<waiter> waiters = make_shared<waiter>(meun.get());
    waiters->display();

    meun->remove(lunch.get());
    meun->remove(dinner.get());

    cout << "-----only breakfast-------" << endl;
    shared_ptr<waiter> beakWaiters = make_shared<waiter>(meun.get());
    beakWaiters->display();


    return 0;

}

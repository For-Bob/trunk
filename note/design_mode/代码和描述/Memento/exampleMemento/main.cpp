#include <iostream>
#include <memory>
#include "player.h"
using namespace std;

int main()
{
    shared_ptr<player> lolPlayer = make_shared<player>();
    shared_ptr<mementoList> list = make_shared<mementoList>();
    lolPlayer->setListPointer(list.get());
    lolPlayer->setName("Bob");
    lolPlayer->setLevel(1);
    lolPlayer->setDamage(10);
    lolPlayer->setDefensive(10);
    lolPlayer->setMoney(20);
    lolPlayer->displayInfo();

    cout << " after 1 week" << endl;
    lolPlayer->setLevel(10);
    lolPlayer->setDamage(100);
    lolPlayer->setDefensive(110);
    lolPlayer->setMoney(250);
    lolPlayer->displayInfo();
    cout << " save the progress" << endl;
    lolPlayer->saveProgress();

    cout << " fight with boss , player is death, evething is drop" << endl;
    lolPlayer->death();

    cout << " get the progress 1" << endl;
    lolPlayer->getProgress(1);
    return 0;
}

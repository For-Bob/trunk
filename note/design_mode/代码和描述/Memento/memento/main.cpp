#include <iostream>
#include <memory>
#include "caretaker.h"
#include "memento.h"
#include "originator.h"
using namespace std;

int main()
{
    shared_ptr<careTaker> care = make_shared<careTaker>();
    shared_ptr<originator> ori = make_shared<originator>();

    ori->setStatus("level 100");
    ori->displayStatus();
    care->setMemento(ori->createMemento());

    std::cout << "system is error, clear all data" << endl;
    ori->setStatus("");
    ori->displayStatus();

    std::cout << "get save data" << endl;
    ori->setStatus(care->getMemento()->getState());
    ori->displayStatus();

    return 0;
}

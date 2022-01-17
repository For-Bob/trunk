#include <iostream>
#include <memory>
#include <string>
using namespace std;

#include "prototypemale.h"
#include "prototypefemale.h"

int main()
{
    shared_ptr<Prototype> person = make_shared<PrototypeMale>();

    person->setName("Programmer");
    person->setAge(26);
    person->setGender("male");
    person->setAddress("chengdu sichuan china");
    person->setID("CDE321LKJROIPCVBPOI980");
    person->setOccupation("write code");

    person->displayInfo();

    Prototype* jack = person->clone();
    jack->setName("jack");
    jack->displayInfo();

    Prototype* Anna = person->clone();
    Anna->setName("Anna");
    Anna->setGender("female");
    Anna->displayInfo();

    return 0;
}

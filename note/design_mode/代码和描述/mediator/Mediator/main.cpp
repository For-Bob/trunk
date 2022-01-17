#include <iostream>
#include <memory>
#include "concretecolleaguea.h"
#include "concretecolleagueb.h"
#include "concretemediator.h"
using namespace std;

int main()
{
    shared_ptr<Mediator> mediator = make_shared<ConcreteMediator>();
    shared_ptr<Colleague> talkA = make_shared<ConcreteColleagueA>();
    shared_ptr<Colleague> talkB = make_shared<ConcreteColleagueB>();
    mediator->setColleague(talkA.get(),1);
    mediator->setColleague(talkB.get(),2);
    talkA->setMediator(mediator.get());
    talkB->setMediator(mediator.get());

    talkA->sendMsg(1,"hello I'm talk A");
    talkA->sendMsg(2,"hello I'm talk A");

    return 0;
}

#include "concreteobservera.h"
#include "concreteobserverb.h"

int main()
{
    shared_ptr<ConcreteObserverA> ObA = make_shared<ConcreteObserverA>();
    shared_ptr<ConcreteObserverB> ObB = make_shared<ConcreteObserverB>();

    shared_ptr<Subject> sub = make_shared<Subject>();
    sub.get()->addObserver(ObA.get());
    sub.get()->addObserver(ObB.get());
    sub.get()->update("there is subject , do you copy that?");

    sub.get()->delObserver(ObA.get());
    sub.get()->update("there is subject , revmode A");

    return 0;
}

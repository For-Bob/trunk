#include <iostream>
#include <memory>
#include "context.h"
#include "concretestatea.h"
#include "concretestateb.h"

using namespace std;

int main()
{
    shared_ptr<Context> C = make_shared<Context>();
//    shared_ptr<State> A = make_shared<ConcreteStateA>();
//    shared_ptr<State> B = make_shared<ConcreteStateB>();
    C->request();
    C->request();
    C->request();
    C->request();

    return 0;
}

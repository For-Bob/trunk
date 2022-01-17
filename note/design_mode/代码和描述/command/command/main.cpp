#include <iostream>
#include <memory>
#include "concretecommand.h"
#include "invoker.h"

using namespace std;

int main()
{
    shared_ptr<Command> cmd = make_shared<ConcreteCommand>();
    shared_ptr<Invoker> inv = make_shared<Invoker>();
    shared_ptr<Receiver> rec = make_shared<Receiver>();
    inv->setCommand(cmd.get());
    cmd.get()->setReceiver(rec.get());
    inv->call("ls");
    inv->call("pwd");
    inv->call("top");

    return 0;
}

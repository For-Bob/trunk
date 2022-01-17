#include "receiver.h"

Receiver::Receiver()
{

}

void Receiver::action(string msg)
{
    cout << "root: " << msg << endl;
}

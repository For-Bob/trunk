#include <iostream>
#include <memory>
#include "TecentCF.h"
#include "TecentLeague.h"

using namespace std;

int main()
{
    shared_ptr<Tecent> user = make_shared<TecentCF>();
    user->login("985880639", "************");
    user->play();
    user.reset();

    user = make_shared<TecentLeague>();
    user->login("990454410", "************");
    user->play();

    return 0;
}

#include <iostream>
#include <memory>
#include "biology.h"
#include "normal.h"
#include "electronics.h"

using namespace std;

int main()
{
    shared_ptr<AbstructClass> nor = make_shared<Normal>();
    nor->run();

    shared_ptr<AbstructClass> bio = make_shared<Biology>();
    bio->run();

    shared_ptr<AbstructClass> ele = make_shared<Electronics>();
    ele->run();
    return 0;
}

#include <iostream>
using namespace std;

#include"singleton.h"

int main(int argc, char *argv[])
{   
    shared_ptr<SingleTon> pointer = SingleTon::Instance();
    pointer->display("intelligence");

    SingleTon *p = SingleTon::normalInstance();
    p->display("normal");
    return 0;
}

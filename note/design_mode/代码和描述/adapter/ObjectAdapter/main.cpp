#include <iostream>

#include "adapter.h"

int main(int argc, char *argv[])
{
    Target *pointer = new Adapter();
    pointer->request();

    return 0;
}

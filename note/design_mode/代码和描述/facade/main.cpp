#include <iostream>
#include "Facade.h"

using namespace std;


int main()
{
    shared_ptr<Facade> facade = make_shared<Facade>();
    facade->generateBinaryFile("main.cpp");

    cout << "-------------" << endl;
    facade->generateBinaryFile("facade.cpp");
    return 0;
}

#ifndef ASSEMBLE_H
#define ASSEMBLE_H

#include <iostream>
using namespace std;

class Assemble
{
public:
    Assemble() {}
    ~Assemble(){}
    void run(string file){
        cout << "step3 Assemble:  g++ -c "<< file <<".s -o main.o 'assemble'" << endl;
    }
};

#endif // ASSEMBLE_H

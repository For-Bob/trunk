#ifndef COMPILATION_H
#define COMPILATION_H

#include <iostream>
using namespace std;

class Compilation
{
public:
    Compilation() {}
    ~Compilation() {}
    void run(string file){
        cout << "step 2: g++ -S " << file << ".cpp -o main.s 'compilation' " << endl;
    }
};

#endif // COMPILATION_H

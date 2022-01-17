#ifndef LINKING_H
#define LINKING_H

#include <iostream>

using namespace std;

class Linking
{
public:
    Linking() {}
    ~Linking(){}
    void run(string file){
        cout << "step4: ld -o a.out " << file << ".o 'Linking'" << endl;
    }
};

#endif // LINKING_H

#ifndef PREPROCESSING_H
#define PREPROCESSING_H

#include <iostream>

using namespace std;

class Preprocessing
{
public:
    Preprocessing() {}
    ~Preprocessing(){}
    void run(string file){
        cout << " first step: g++ -E " << file << ".cpp -o main.i 'preprocess' " << endl;
    }

};


#endif // PREPROCESSING_H

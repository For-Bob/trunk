#ifndef CHESS_H
#define CHESS_H

#include <iostream>
#include <string>

using namespace std;
class chess
{
public:
    chess();
    virtual ~chess();
    virtual string place(int x, int y) = 0;
};

#endif // CHESS_H

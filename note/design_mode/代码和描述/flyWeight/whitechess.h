#ifndef WHITECHESS_H
#define WHITECHESS_H

#include "chess.h"

class whiteChess : public chess
{
public:
    whiteChess();
    ~whiteChess();
    string place(int x, int y);
};

#endif // WHITECHESS_H

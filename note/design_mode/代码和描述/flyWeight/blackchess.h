#ifndef BLACKCHESS_H
#define BLACKCHESS_H

#include "chess.h"

class blackChess : public chess
{
public:
    blackChess();
    ~blackChess();
    string place(int x, int y);
};

#endif // BLACKCHESS_H

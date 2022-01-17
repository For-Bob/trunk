#ifndef CHESSFACTORY_H
#define CHESSFACTORY_H

#include "chess.h"
#include "blackchess.h"
#include "whitechess.h"
#include <map>
#include <memory>

class chessFactory
{
public:
    chessFactory();
    ~chessFactory();
    chess* createChess(string name);

private:
    map<string, chess*> m_player;
};

#endif // CHESSFACTORY_H

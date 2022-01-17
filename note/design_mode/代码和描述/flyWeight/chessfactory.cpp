#include "chessfactory.h"

chessFactory::chessFactory()
{
    chess* black = new blackChess();
    chess* white = new whiteChess();
    m_player.insert(pair<string, chess*>("black", black));
    m_player.insert(pair<string, chess*>("white", white));
}

chessFactory::~chessFactory()
{
    m_player.clear();
}

chess* chessFactory::createChess(string name)
{
    auto it = m_player.find(name);
    if(it != m_player.end())
    {
        return it->second;
    }
    else
    {
        chess* pointer = new whiteChess();//扩展，这个用的白棋，以后可以用黄棋，其他颜色的都行
        m_player.insert(pair<string, chess*>(name, pointer));

        return this->createChess(name);
    }
}

#include "chessfactory.h"
//说明下面的场景，明和黄都是用的黑棋，一般情况下不同对象都会创建两个对象，使用享元模式，那么他们用的都是一个对象
//虎和小也是用的同一个对象，这样减少了对象的创建，节省了空间
//举个最简单的例子，网络联机下棋的时候，一台服务器连接了多个客户端（玩家），如果我们每个棋子都要创建对象，那一盘棋可能就有上百个对象产生，
//玩家多点的话，因为内存空间有限，一台服务器就难以支持了，所以这里要使用享元模式，将棋子对象减少到几个实例。
int main()
{
    shared_ptr<chessFactory> factory  = make_shared<chessFactory>();
    //明和虎下棋
    chess* ming = factory->createChess("black");
    chess* hu = factory->createChess("white");
    cout << "ming and hu play chess" << endl;
    ming->place(rand(), rand());
    hu->place(rand(), rand());
    //黄和小下棋
    cout << "huang and xiao play chess" << endl;
    chess* huang = factory->createChess("black");
    chess* xiao = factory->createChess("white");
    huang->place(rand(), rand());
    xiao->place(rand(), rand());
    return 0;
}

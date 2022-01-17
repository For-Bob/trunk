#ifndef PLAYER_H
#define PLAYER_H

#include "mementostatus.h"
#include "mementolist.h"
class mementoStatus;
class player
{
public:
    player();
    ~player(){}
    void displayInfo();
    void saveProgress();
    void getProgress(unsigned int index);
    void setListPointer(mementoList* pointer);
    void setName(string name);
    void setLevel(int level);
    void setDamage(int damage);
    void setDefensive(int defensive);
    void setMoney(int money);
    void death();
private:
    mementoStatus::personInfo m_playerDetail;
    mementoList*    m_mementoList;
};

#endif // PLAYER_H

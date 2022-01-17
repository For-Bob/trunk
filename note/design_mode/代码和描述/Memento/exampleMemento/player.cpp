#include <memory>
#include "player.h"

player::player()
    :m_mementoList(nullptr)
{

}

void player::displayInfo(){
    cout << "current info name: " << m_playerDetail.name << " level: " << m_playerDetail.level << " damage: " << m_playerDetail.damage << " defensive: " << m_playerDetail.defensive
         << " money: " << m_playerDetail.money << endl;
}

void player::saveProgress(){
    shared_ptr<mementoStatus> status = make_shared<mementoStatus>();
    status->setPerson(m_playerDetail);
    m_mementoList->saveProgress(status.get());
}

void player::getProgress(unsigned int index){
    mementoStatus* status = m_mementoList->getProgress(index - 1);
    m_playerDetail = status->getPerson();
    this->displayInfo();
}

void player::setListPointer(mementoList *pointer)
{
    m_mementoList = pointer;
}

void player::setName(string name){
    m_playerDetail.name = name;
}

void player::setLevel(int level){
    m_playerDetail.level = level;
}

void player::setDamage(int damage){
    m_playerDetail.damage = damage;
}

void player::setDefensive(int defensive){
    m_playerDetail.defensive = defensive;
}

void player::setMoney(int money){
    m_playerDetail.money = money;
}

void player::death()
{
     m_playerDetail.level = 1;
     m_playerDetail.damage = 10;
     m_playerDetail.defensive = 10;
     m_playerDetail.money = 20;
     this->displayInfo();
}

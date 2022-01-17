#include "orangeDecoratorCake.h"

orangeDecoratorCake::orangeDecoratorCake(Cake* pCake)
{    
    this->m_pCake = pCake;
}

orangeDecoratorCake::~orangeDecoratorCake(){

}

void orangeDecoratorCake::showCake(){
    cout << "current cake is " << m_pCake->m_cake << " and orange" << endl;
}

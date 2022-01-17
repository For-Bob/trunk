#include "mikeDecoratorCake.h"

mikeDecoratorCake::mikeDecoratorCake(Cake *pCake)
{
    this->m_pCake = pCake;
}

mikeDecoratorCake::~mikeDecoratorCake(){

}

void mikeDecoratorCake::showCake(){
    cout << "current cake is " << m_pCake->m_cake << " and mike" << endl;
}

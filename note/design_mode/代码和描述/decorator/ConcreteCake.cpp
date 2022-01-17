#include "ConcreteCake.h"

ConcreteCake::ConcreteCake()
{
    cout << "construct original cake " << endl;
    m_cake = "original cake";
}

ConcreteCake::~ConcreteCake(){

}

void ConcreteCake::showCake(){
    cout << "current cake is " << m_cake << endl;
}

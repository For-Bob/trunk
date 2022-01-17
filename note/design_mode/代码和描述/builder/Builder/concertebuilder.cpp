#include "concertebuilder.h"

ConcerteBuilder::ConcerteBuilder()
    :m_pProduct(new Product())
{

}

void ConcerteBuilder::buildPartA(){
    cout << " the first step: build Part of A" << endl;
}

void ConcerteBuilder::buildPartB(){
    cout << " the second step: build Part of B" << endl;
}

void ConcerteBuilder::buildPartC(){
    cout << " the thrid step: build Part of C" << endl;
}

void ConcerteBuilder::buildPartD(){
    cout << " the fourth step: build Part of D" << endl;
}

Product* ConcerteBuilder::getResult()
{
    return m_pProduct.get();
}

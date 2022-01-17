#include "director.h"

Director::Director()
    :m_pBuilder(nullptr)
{

}

void Director::setBuilder(Builder *builder){
    m_pBuilder = builder;
}

Product* Director::constructProduct()
{
    m_pBuilder->buildPartA();
    m_pBuilder->buildPartB();
    m_pBuilder->buildPartC();
    m_pBuilder->buildPartD();
    return m_pBuilder->getResult();
}

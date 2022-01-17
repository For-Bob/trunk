#include "strategyinterface.h"

strategyInterface::strategyInterface()
{
    m_pStrategy[0] = std::make_shared<ConcreteStrategy>();
    m_pStrategy[1] = std::make_shared<BuyTowGetOneFreeStrategy>();
    m_pStrategy[2] = std::make_shared<HalfStrtegy>();
}

strategyInterface::~strategyInterface()
{

}

void strategyInterface::displayInfo(int index)
{
    if(index < m_pStrategy.size())
        m_pStrategy.at(index)->displayInfo();
    else
        std::cout << "the index is illage data" << std::endl;
}

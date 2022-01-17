#ifndef STRATEGYINTERFACE_H
#define STRATEGYINTERFACE_H

#include <map>
#include <memory>
#include "buytowgetonefreestrategy.h"
#include "halfstrtegy.h"
#include "concretestrategy.h"
class strategyInterface
{
public:
    strategyInterface();
    ~strategyInterface();
    void displayInfo(int index);

private:
    std::map<int, std::shared_ptr<AbstructStrategy>> m_pStrategy;
};

#endif // STRATEGYINTERFACE_H

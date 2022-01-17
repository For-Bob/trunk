#include "context.h"
#include "concretestatea.h"
Context::Context()
{
    m_pState = ConcreteStateA::getInstance();
}

void Context::setState(State *sta)
{
    if(sta != nullptr)
        m_pState = sta;
}

void Context::request()
{
    m_pState->handle(this);
}

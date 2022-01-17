#include "subject.h"

Subject::Subject()
{

}

Subject::~Subject()
{

}

void Subject::addObserver(Observer* ob){
    if(ob != nullptr)
        m_pObserver.push_back(ob);
}
void Subject::delObserver(Observer* ob){
    if(ob != nullptr)
    {
        auto it = m_pObserver.begin();
        while (it != m_pObserver.end()) {
            if(*it == ob)
            {
                m_pObserver.erase(it);
                break;
            }
            else
                it++;
        }
    }
}
void Subject::update(string msg){
    for(int i = 0; i < m_pObserver.size(); i++)
    {
        Observer* ob = m_pObserver.at(i);
        ob->update(msg);

    }
//    for(auto ob = m_pObserver.begin(); ob != m_pObserver.end(); ob++)
//    {
//        *ob->update(msg);
//    }
}

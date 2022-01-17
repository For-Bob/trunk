#include "singleton.h"

using namespace std;

shared_ptr<SingleTon> SingleTon::m_Instance = nullptr;
SingleTon* SingleTon::m_noramlInstance = nullptr;

SingleTon::SingleTon()
{
    cout << "create singleTon constructer" << endl;
}

SingleTon::~SingleTon(){
    cout << "deconstruct singleTon constructer" << endl;
}

shared_ptr<SingleTon> SingleTon::Instance(){
    if(m_Instance == nullptr){
        m_Instance = shared_ptr<SingleTon>();
    }
    return m_Instance;
}

SingleTon* SingleTon::normalInstance(){
    if(m_noramlInstance == nullptr){
        m_noramlInstance = new SingleTon();
    }
    return m_noramlInstance;
}

void SingleTon::display(string str){
    cout << "------------display :" <<str << endl;
}

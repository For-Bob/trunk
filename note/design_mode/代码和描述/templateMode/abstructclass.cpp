#include "abstructclass.h"

AbstructClass::AbstructClass()
{

}

AbstructClass::~AbstructClass()
{

}

void AbstructClass::run()
{
    if(this->init())
    {
        this->OneAndOne();
        this->end();
    }
}

bool AbstructClass::init()
{
    cout << "------program init sucess" << endl;
    return true;
}

void AbstructClass::end()
{
    cout << "------data calcute success\n" << endl;
}

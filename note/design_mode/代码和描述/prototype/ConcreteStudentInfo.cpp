#include "ConcreteStudentInfo.h"

ConcreteStudentInfo::ConcreteStudentInfo()
{
    cout << "ContreteStudentInfo: " << endl;
}

ConcreteStudentInfo::~ConcreteStudentInfo(){

}

AbstructStudentInfo* ConcreteStudentInfo::clone()
{
//    return this;//浅拷贝
    return new ConcreteStudentInfo(*this);//深拷贝
}

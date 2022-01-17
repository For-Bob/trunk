#include "ConcreteStudentInfo.h"

int main()
{
    shared_ptr<AbstructStudentInfo> ming = make_shared<ConcreteStudentInfo>();
    ming->setName("ming");
    ming->setAge("3");
    ming->setSex("male");
    ming->setClass("class 1, grade 2");
    ming->setHobby("swim");
    ming->setSchool("3 tianfu street, Chengdu City,Sichuan Province");


    AbstructStudentInfo* hong = ming->clone();
    hong->setName("hong");
    hong->setSex("female");
    hong->dispalyStudentInfo();

    ming->dispalyStudentInfo();

    if(hong != nullptr)
    {
        delete hong;
        hong = nullptr;
    }
    return 0;
}

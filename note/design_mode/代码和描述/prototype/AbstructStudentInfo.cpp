#include "AbstructStudentInfo.h"

AbstructStudentInfo::AbstructStudentInfo()
{

}

AbstructStudentInfo::~AbstructStudentInfo()
{

}

void AbstructStudentInfo::setName(string name)
{
    m_name = name;
}

void AbstructStudentInfo::setSex(string sex)
{
    m_sex = sex;
}

void AbstructStudentInfo::setAge(string age){
    m_age = age;
}

void AbstructStudentInfo::setClass(string Class){
    m_class = Class;
}

void AbstructStudentInfo::setSchool(string address){
    m_schoolAdress = address;
}

void AbstructStudentInfo::setHobby(string hobby){
    m_hobby = hobby;
}

void AbstructStudentInfo::dispalyStudentInfo(){
    cout<< " name: " << m_name << " sex: " << m_sex << " age: " << m_age <<" class: " << m_class <<" school adress: " << m_schoolAdress << " hobby: " << m_hobby << endl;
}

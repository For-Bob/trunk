#ifndef AbstructStudentInfo_H
#define AbstructStudentInfo_H

#include <iostream>
#include <string>

using namespace std;

class AbstructStudentInfo
{
public:
    AbstructStudentInfo();
    virtual ~AbstructStudentInfo();
    virtual AbstructStudentInfo* clone() = 0;
    virtual void setName(string name);
    virtual void setSex(string sex);
    virtual void setAge(string age);
    virtual void setClass(string Class);
    virtual void setSchool(string address);
    virtual void setHobby(string hobby);
    virtual void dispalyStudentInfo();
private:
    string m_name;
    string m_sex;
    string m_age;
    string m_class;
    string m_schoolAdress;
    string m_hobby;
};

#endif // AbstructStudentInfo_H

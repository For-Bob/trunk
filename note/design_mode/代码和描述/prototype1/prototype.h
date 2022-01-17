#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <iostream>
#include <string>

using namespace std;

class Prototype
{
public:
    Prototype();
    virtual ~Prototype();
    virtual Prototype* clone() = 0;

    void setName(string name);
    void setGender(string gender);
    void setAddress(string address);
    void setID(string id);
    void setOccupation(string occupation);
    void setAge(int age);

    void displayInfo();

    string m_name;
    string m_gender;
    string m_address;
    string m_ID;
    string m_occupation;
    int  m_age;
};

#endif // PROTOTYPE_H

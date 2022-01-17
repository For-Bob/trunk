#pragma once
#include <stdio.h>
#include <iostream>
class MyString
{
public:
    MyString()
        :m_data(nullptr){
    }
    ~MyString(){
        if (m_data)
        {
            delete[] m_data;
            m_data = nullptr;
        }
    }
    MyString(MyString& str){
        if (this == &str)
            return;
        if (str.m_data == nullptr){
            m_data = new char[1];
            m_data = '\0';
        }
        else{
            m_data = new char[strlen(str.m_data) + 1];
            sprintf(m_data, str.m_data);
        }
    }
    MyString(char* data)
    {
        if(data == nullptr){
            m_data = new char[1];
            m_data = '\0';
        }
        else{
            m_data = new char[strlen(data) + 1];
            snprintf(m_data, strlen(data) + 1,data);
        }
    }
    MyString operator = (MyString str)
    {
        if (this == &str)
            return *this;

        if (m_data != nullptr)
            delete m_data;
        if (str.m_data == nullptr){
            m_data = new char[1];
            m_data = '\0';
        }
        else{
            m_data = new char[strlen(str.m_data) + 1];
            sprintf(m_data, str.m_data);
        }
        return *this;
    }
    void printData(){
        if (m_data == nullptr)
            std::cout << "m_data is nullptr ,return !!!" << std::endl;
        else
            std::cout << "m_data: " << m_data << std::endl;
    }
private:
    char *m_data;
};

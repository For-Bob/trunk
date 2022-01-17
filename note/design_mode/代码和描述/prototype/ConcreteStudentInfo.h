#ifndef ConcreteStudentInfo_H
#define ConcreteStudentInfo_H

#include <memory>
#include "AbstructStudentInfo.h"
class ConcreteStudentInfo : public AbstructStudentInfo
{
public:
    ConcreteStudentInfo();
    ~ConcreteStudentInfo();
    AbstructStudentInfo* clone();
};

#endif // ConcreteStudentInfo_H

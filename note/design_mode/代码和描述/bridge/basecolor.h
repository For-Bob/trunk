#ifndef BASECOLOR_H
#define BASECOLOR_H

#include <iostream>
#include <string>
using namespace std;

class baseColor
{
public:
    baseColor();
    virtual ~baseColor();
    virtual void drawPaint(string shape) = 0;
};

#endif // BASECOLOR_H

#ifndef BASESHAPE_H
#define BASESHAPE_H

#include "basecolor.h"

class baseShape
{
public:
    baseShape();
    ~baseShape();
    virtual void drawShape(baseColor* color) = 0;
};

#endif // BASESHAPE_H

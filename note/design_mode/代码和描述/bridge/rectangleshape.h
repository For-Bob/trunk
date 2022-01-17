#ifndef RECTANGLESHAPE_H
#define RECTANGLESHAPE_H

#include "baseshape.h"

class rectangleShape: public baseShape
{
public:
    rectangleShape();
    ~rectangleShape();
    void drawShape(baseColor* color);
};

#endif // RECTANGLESHAPE_H

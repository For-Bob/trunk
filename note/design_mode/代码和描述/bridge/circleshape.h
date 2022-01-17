#ifndef CIRCLESHAPE_H
#define CIRCLESHAPE_H

#include "baseshape.h"

class circleShape : public baseShape
{
public:
    circleShape();
    ~circleShape();
    void drawShape(baseColor* color);
};

#endif // CIRCLESHAPE_H

#ifndef REDCOLORPAINT_H
#define REDCOLORPAINT_H

#include "basecolor.h"

class redColorPaint: public baseColor
{
public:
    redColorPaint();
    ~redColorPaint();
    void drawPaint(string shape);
};

#endif // REDCOLORPAINT_H

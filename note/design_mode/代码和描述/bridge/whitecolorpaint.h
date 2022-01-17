#ifndef WHITECOLORPAINT_H
#define WHITECOLORPAINT_H

#include "basecolor.h"

class whiteColorPaint :public baseColor
{
public:
    whiteColorPaint();
    ~whiteColorPaint();
    void drawPaint(string shape);
};

#endif // WHITECOLORPAINT_H

#include "circleshape.h"

circleShape::circleShape()
{

}

circleShape::~circleShape()
{

}

void circleShape::drawShape(baseColor *color)
{
    color->drawPaint("circle");
}

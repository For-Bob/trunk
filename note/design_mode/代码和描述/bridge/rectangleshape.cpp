#include "rectangleshape.h"

rectangleShape::rectangleShape()
{

}

rectangleShape::~rectangleShape()
{

}

void rectangleShape::drawShape(baseColor *color)
{
    color->drawPaint("rectangle");
}

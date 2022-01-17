#include <iostream>
#include <memory>
#include "rectangleshape.h"
#include "circleshape.h"
#include "whitecolorpaint.h"
#include "redcolorpaint.h"

using namespace std;

int main()
{
    shared_ptr<baseShape> shape = make_shared <rectangleShape>();
    shared_ptr<baseColor> color = make_shared <redColorPaint>();
    shape->drawShape(color.get());
    color.reset();
    color = make_shared<whiteColorPaint>();
    shape->drawShape(color.get());

    cout << "=============================" << endl;
    shape.reset();
    shape = make_shared<circleShape>();
    color = make_shared <redColorPaint>();
    shape->drawShape(color.get());
    color.reset();
    color = make_shared<whiteColorPaint>();
    shape->drawShape(color.get());

    return 0;
}

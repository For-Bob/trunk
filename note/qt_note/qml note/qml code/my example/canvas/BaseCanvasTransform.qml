import QtQuick 2.2

Canvas {
    width:800;
    height:800;
    contextType: "2d";
    property var comicRole: "start.jpg";

    onPaint: {
        context.lineWidth = 2;
        context.strokeStyle = "blue";
        context.fillStyle = Qt.rgba(0.3, 0.5, 0.7, 0.5);

        context.save();
        context.translate(width/2, height/2);
        context.drawImage(comicRole, -68, -100, 137,200);
        context.restore();

        context.save();
        context.translate(width/2, 0 );
        context.shear(0, 1)
        context.drawImage(comicRole, 0, 0, 137,200);
        context.restore();

        context.save();
        context.setTransform(1,2, 0.5, 0, 0.7, 0, 0);
        context.drawImage(comicRole, 0, 0, 137,200);
        context.restore();
    }

    Component.onCompleted: loadImage(comicRole);
    onImageLoaded: requestPaint();

}


//object shear(real sh, real sv)
//在水平方向上用sh,在垂直方向上用sv剪切转换矩阵
//Shears the transformation matrix by sh in the horizontal direction and sv in the vertical direction.


//object setTransform(real a, real b, real c, real d, real e, real f)
//a is the scale factor in the horizontal (x) direction
//a是水平（x）方向的比例因子
//c is the skew factor in the x direction
//c是x方向上的斜因子
//e is the translation in the x direction
//e是x方向上的平移
//b is the skew factor in the y (vertical) direction
//b是y（垂直）方向上的斜因子
//d is the scale factor in the y direction
//d是y方向上的比例因子
//f is the translation in the y direction
//f是y方向上的平移








import QtQuick 2.0
import QtQuick 2.2

Canvas{
    width:400;
    height:240;
    contextType: "2d";

    onPaint: {
        context.lineWidth = 2;
        context.strokeStyle = "red";
        context.fillStyle = "blue";
        context.beginPath();
        context.moveTo(100, 80);
        context.lineTo(100, 200);
        context.lineTo(300, 200);
        context.closePath();//结束当前的路径，从路径终点到起点绘制一条直线来封闭路径。
        context.fill();
        context.stroke();
    }
}

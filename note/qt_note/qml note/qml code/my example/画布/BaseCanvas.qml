import QtQuick 2.0
import QtQuick 2.5

Canvas {
    width:400;
    height:300;
    /*//方式一，画图
    onPaint: {
        var ctx = getContext("2d");
        ctx.lineWidth = 5;
        ctx.strokeStyle = "red";
        ctx.fillStyle = "blue";
        ctx.beginPath();
        ctx.rect(100,80,120,80);
        ctx.fill();
        ctx.stroke();
    }*/
    //方式二，画图
    contextType: "2d";
    onPaint: {
        context.lineWidth = 5;
        context.strokeStyle = "red";
        context.fillStyle = "blue";
        context.beginPath();
        context.rect(100,80,120,80);
        context.fill();
        context.stroke();
    }
}

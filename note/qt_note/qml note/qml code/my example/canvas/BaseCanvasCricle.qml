import QtQuick 2.0
import QtQuick 2.2

Canvas {
    width:300;
    height: 300;
    contextType: "2d";

    onPaint: {
        context.lineWidth = 2;
        context.strokeStyle = "blue";
        context.fillStyle = "red";

        context.save();
        context.translate(width/2, height/2);
        context.beginPath();
        context.arc(0, 0, 30, 0, Math.PI*2);
        context.arc(0, 0, 50, 0, Math.PI*2);
        context.arc(0, 0, 70, 0, Math.PI*2);
        context.arc(0, 0, 90, 0, Math.PI*2);
        context.stroke();
        //context.restore();    //1

        //context.save();   //1
        //context.translate(width/2, 30);//1
        context.translate(0,-height/2 + 30);//2
        context.font = "26px serif";
        context.textAlign = "center";
        context.fillText("circles", 0 ,0);
        context.restore();
    }
}
/*
  1.是方法一
  2.是方法二
先使用translate将坐标系的原点(0,0)平移到了画布中心，平移变换，绘图完成后要调用restore()来恢复之前的画布状态，否则发生重绘时
（比如用户拖动窗口改变大小），就看不见绘制的图元了，而要restore()必先save(),
*/

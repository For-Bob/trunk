import QtQuick 2.0
import QtQuick 2.2

Rectangle{
    width:360;
    height:240;
    color:"#EEEEEE";
    id: rootItem;
    Rectangle{
        id: rect;
        width: 50;
        height: 150;
        anchors.centerIn: parent;
        color:"blue";

        property var animation;
        PropertyAnimation{
            id:toSquare;
            target:rect;
            property:"width";
            to:150;
            duration: 1000;
            onStarted: {
                rect.animation = toSquare;
                rect.color = "red";
            }
            onStopped: {
                rect.color = "blue";
            }
        }
        PropertyAnimation{
            id:toRect;
            target:rect;
            property:"width";
            to:50;
            duration: 1000;
            onStarted: {
                rect.animation = toRect;
                rect.color = "red";
            }
            onStopped: {
                rect.color = "blue";
            }
        }
        MouseArea{
            anchors.fill: parent;
            onClicked: {
                if(rect.animation == toRect ||
                        rect.animation == undefined){
                    toSquare.start();
                }
                else if(rect.animation == toSquare){
                    toRect.start();
                }
            }
        }

    }
}
//定义两个动画，一个将蓝色矩形变为正方形，一个反过来将正方形再变为矩形。
//收到started（）信号是改变矩形颜色并记录执行的动画，在收到stopped信号时重置矩形的颜色。
//当鼠标左键按下时我们根据上次执行的动画来决定这个该执行哪个动画

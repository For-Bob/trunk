import QtQuick 2.0
import QtQuick 2.2

Rectangle{
    width:360;
    height: 240;
    color:"#eeeeee";
    id: rootItem
    Rectangle{
        id: rect;
        width: 50;
        height: 150;
        anchors.centerIn: parent;
        color:"blue";
    }

    PropertyAnimation{
        id:animation;
        target:rect;
        properties: "width,height";
        to:220;
        duration:1000;
    }

    MouseArea{
        anchors.fill: parent;
        onClicked: animation.running = true;
    }
}
//当鼠标点击蓝色矩形是，宽度和高度同时变为220

/*
如果想同时改变多个目标对象，则可以设置targets属性，比如下面的PropertyAnimation定义同时改变了rectA，rectB的属性：
    PropertyAnimation{
        id:animation;
        targets:[rectA,rectB];
        properties: "width,height";
        to:150;
        duration:1000;
    }

*/

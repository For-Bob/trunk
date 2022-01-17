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

        MouseArea{
            anchors.fill: parent;
            onClicked: PropertyAnimation{
                target: rect;
                property: "width";
                to:150;
                duration:1000;
            }
        }
    }
}
//在信号处理器中使用：当鼠标点击蓝色矩形是，宽度变为150，

import QtQuick 2.2

Rectangle {
    width: 320;
    height: 240;
    color: "#eeeeee"

    Rectangle{
        id: rect
        color:"red";
        width: 60;
        height: 60;
        radius: width/2
        anchors.centerIn: parent
        MouseArea{
            id:mouseArea;
            anchors.fill: parent
            onClicked:
                ColorAnimation {
                target: rect
                property: "color"
                to: "green"
                duration: 3000
            }
        }
    }
}
//把圆形的红色变成绿色。

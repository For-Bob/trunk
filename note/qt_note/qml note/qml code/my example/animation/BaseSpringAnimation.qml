import QtQuick 2.2

Rectangle {
    id: rootItem
    height: 500
    width:500
    color: "#eeeeee"
    Rectangle{
        id: rect
        width: 40
        height: 40
        x:20;
        y:20
        color: "red"
    }

    SpringAnimation{
        id: springX
        target: rect
        property:"x"
        spring: 3
        damping: 0.06
        epsilon: 0.005
    }

    SpringAnimation{
        id: springY
        target: rect
        property:"y"
        spring: 3
        damping: 0.06
        epsilon: 0.005
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            springX.from = rect.x
            springX.to = mouse.x - 10
            springX.start()
            springY.from = rect.y
            springY.to = mouse.y - 10
            springY.start()
        }
    }
}
//我为x、y两个属性定义了SpringAnimation，衰减系数设置为0.06，加速度设置为3，可以看到比较明显的振荡过程。

import QtQuick 2.2

Rectangle {
    width: 360
    height: 240;
    color:"#eeeeee"

    id: rootItem

    Rectangle{
        id: rect
        color: "blue"
        width:50
        height: 50
        x: 10
        y: 95

        MouseArea{
            id: mouseArea
            anchors.fill: parent
            onClicked:{
                if(anim.paused)
                    anim.resume()
                else if(anim.running)
                    anim.pause()
                else
                    anim.start()
            }
        }

        ParallelAnimation{
            id: anim
//            loops: Animation.Infinite   //一直循环
            NumberAnimation{
                target: rect
                property: "x"
                to:310
                duration: 3000
            }

            NumberAnimation{
                target: rect
                property: "rotation"
                to:360
                duration: 1000
                loops: 3
            }

            NumberAnimation{
                target: rect
                property: "radius"
                to:25
                duration: 3000
            }
        }
    }
}
//上面代码中的ParallelAnimation会无限循环运动，它定义了三个NumberAnimation，分别改变rect对象的x、rotation、radius属性，产生旋转这沿水平向前进，随着前进菱角被磨圆的效果。
//MouseArea的onClicked方法，根据anim对象的paused、running两个属性来判断鼠标左键按下时改变anim对象的状态。最终的效果是动画可以启动，暂停，继续。

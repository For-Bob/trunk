import QtQuick 2.2
import "colorMaker.js" as ColorMaker

Rectangle {
    width :360
    height: 240

    color:"#eeeeee"
    id: rootItem

    Rectangle{
        id: colorRect
        color:"red"
        width: 150
        height: 130
        anchors.centerIn: parent

        MouseArea{
            id: mouseArea
            anchors.fill: parent
        }

        states:[
            State{
                name: "defalut"
                when: mouseArea.pressed
                StateChangeScript{
                    name:"changeColor"
                    script: ColorMaker.changeColor(colorRect)
                }
            }

        ]
    }
}

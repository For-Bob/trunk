import QtQuick 2.2

Rectangle {
    width: 360
    height: 240
    color: "#eeeeee"
    id: rootItem

    Rectangle{
        id:rect
        color:"gray"
        width: 50
        height: 50
        anchors.centerIn: parent

        MouseArea{
            id: mouseArea
            anchors.fill: parent
//            onReleased:{rect.color:"gray"}
        }
        states:[
            State{
            name: "pressed"
            when: mouseArea.pressed
            PropertyChanges{
                target:rect
                color: "green"
                scale: 2
            }
        }]

        transitions:Transition {
            to:"pressed"
            reversible: true
            SequentialAnimation{
                NumberAnimation {
                    property: "scale"
                    duration: 1000
                    easing.type: Easing.InOutQuad
                }

                ColorAnimation {
                    duration: 1000
                }
            }
        }
    }
}


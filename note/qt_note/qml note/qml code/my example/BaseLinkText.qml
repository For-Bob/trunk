import QtQuick 2.2

Rectangle {
    width: 360
    height: 240
    color: "#eeeeee"
    id: rootItem

    Text{
        id: linkText
        text:"i'm web link"
        anchors.centerIn: parent
        font.pixelSize: 24
        property var hadClicked:false

        MouseArea{
            id :mouseArea
            anchors.fill: parent
            hoverEnabled: true

            onEntered: {
                linkText.state = linkText.hadClicked == true ? "clickedHover":"hover"
            }
            onExited: {
                linkText.state = linkText.hadClicked == true ? "clicked":"initial"
            }
            onClicked: {
                if(linkText.hadClicked == false){
                    linkText.hadClicked = true
                }
                else
                    linkText.state = "clicked"
            }
        }

        states:[
            State{
                name: "initial"
                changes:[
                    PropertyChanges{target: linkText; color:"blue"}
                ]
            },
            State{
                name: "hover"
                PropertyChanges{target: linkText; color:"#87cdfa";
                    font{italic: true;pixelSize:36;underline: true}
                }
            },
            State{
                name: "clicked"
                PropertyChanges{
                    target: linkText; color:"#8b4513"
                    font{pixelSize:24}
                }
            },
            State{
                name: "clickedHover"
                    PropertyChanges{target: linkText; color:"#d2691e";
                     font{italic: true;pixelSize:36;underline: true}
                    }
                 }
            ]
        state:"initial"

        transitions: [
            Transition {
                from: "initial"
                to: "hover"// This is available in all editors.
                reversible: true
                NumberAnimation{
                    property: "font.pixelSize"
                    duration: 800
                }
                ColorAnimation {
                    duration: 800
                }
            },
            Transition {
                from: "hover"
                to: "clicked"// This is available in all editors.
                reversible: true
                NumberAnimation{
                    property: "font.pixelSize"
                    duration: 800
                }
                ColorAnimation {
                    duration: 800
                }
            },
            Transition {
                from: "clicked"
                to: "clickedHover"// This is available in all editors.
                reversible: true
                    SequentialAnimation{
                    NumberAnimation{
                        property: "font.pixelSize"
                        duration: 800
                    }
                    ColorAnimation {
                        duration: 800
                    }
                }
            }
        ]
    }
}
/*
initial,初始化，文本颜色为蓝色。
hover，未点击时鼠标进入，文本变为浅蓝色，字体放大，倾斜，加下划线。
clicked，点击后颜色变为马鞍棕色，字体恢复初始大小，没有下划线，不倾斜。
clickedHover，点击之后鼠标进入，文本变为巧克力，字体放大，倾斜，加下划线。有5条状态迁移路径。
有5条状态迁移路径：
initial与hover的相互转换，对应的Transition对象的f
*/

import QtQuick 2.2

Canvas{
    width:400;
    height:200;

    onPaint: {
        var ctx = getContext("2d");
        ctx.lineWidth = 4;
        ctx.strokeStyle = "red";
        ctx.beginPath();
        ctx.arc(200,0,160,Math.PI * 2,0,false);
        ctx.stroke();
    }

    Rectangle{
        id:rect
        width:40
        height:40
        color:"blue"
        x:20
        y:0

        MouseArea{
            anchors.fill: parent
            id:mouseArea
            onClicked: pathAnim.start()
        }
        PathAnimation{
            id:pathAnim
            target: rect
            duration:6000
            anchorPoint: "20,20"    //路径起位置
            orientationEntryDuration: 200 //进入到路径200ms
            orientationExitDuration: 200    //退出路径200ms
            easing.type: Easing.InOutCubic
            orientation: PathAnimation.TopFirst;
            path:Path{
                startX: 40;//x起点
                startY: 0   //y起点
                PathArc{
                    x:360   //x结束点
                    y:0     //y结束点
                    useLargeArc: true
                    radiusX: 160    //x角度路径
                    radiusY: 160    //y角度路径
                    direction: PathArc.Counterclockwise
                }
            }
        }
    }
}
//正方形沿半圆运动。

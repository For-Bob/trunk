import QtQuick 2.2
import QtQuick.Controls 1.2

Rectangle {
    width: 360
    height: 240
    color: "#e0e0e0"
    id: root
    focus: true

    Row{
        id: bubbles
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        spacing:2
        property var diedCount: 0

        Component.onCompleted: {
            var i = 0
            var qmlStringBegin = "import QtQuick 2.2; Image{width: 30; height: 30; property var died: false; source:\"res/bubble_";

            for(; i < 8; i++){
                var qmlString = qmlStringBegin + (i + 1) + ".png\";}";
                bubbles.children[i] = Qt.createQmlObject(qmlString,bubbles, "DynamicImage")
            }
        }

        function allDie(){
            return diedCount == children.length;
        }

        function reset(){
            diedCount = 0;
            var i = 0;
            var bubble;
            for(; i < bubbles.children.length; i++){
                bubble = bubbles.children[i];
                bubble.died = false;
                bubble.source = "res/bubble_" +(i + 1) + ".png";
                bubble.opacity = 1.0;

            }
        }
    }
    Text{
        id: scoreInfo;
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: bubbles.bottom
        anchors.topMargin: 4
        font.pixelSize: 26
        font.bold: true
        color: "blue"
    }
    Image{
        id: turret;
        width: 50
        height: 80
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        source: "res/turret.png"
        transformOrigin: Item.Bottom
    }
    Image{
        id: bullet;
        width: 40
        height: 40
        source: "res/knife.png"
        z:2
        visible: false
    }
    NumberAnimation{
        property var rotateAngle: 0

        function rotate(angle){
            rotateAngle += angle;
            if(running == false){
                rotateTurret();
            }
        }
        function rotateTurret(){
            if(rotateAngle != 0){
                from = tuttet.rotation;
                to = turret.rotation + rotateAngle;
                if(to > 80)
                    to = 80;
                else if(to < -80)
                    to = -80;
                var distance = to - from;
                duration = Math.min(100 * Math.abs(distance /3), 800);
                start();
                rotateAngle = 0;
            }
        }
        id: animateTurret;
        target: turret
        property: "rotation"
        onStopped: {
            rotateTurret();
        }
    }
    NumberAnimation{
        id: aboutDie;
        property: "opacity"
        duration: 400
        from: 1.0
        to: 0
        onStopped: {
            showDie.start();
        }
    }
    NumberAnimation{
        id: showDie;
        property: "opacity"
        duration: 400
        from: 0
        to: 0.6
        property var diedImage;
        onStarted: {
            target.source = diedImage
        }

        onStopped: {
            root.resetBullet()
            bubbles.diedCount++;
            if(bubbles.allDie() == true){
                passed.showPass(true)
                deadline.stop()
                root.showScore()
            }
        }
    }
    ParallelAnimation{
        id:animateBullet
        property var fire: 0
        property var diedBibble: -1

        function caculateDiedBubble(){
            var crossX = turret.rotation == 0 ?
                        (root.width /2 - bullet.width/2):
                        (root.width /2 - bullet.width/2) +
                        (15 - (root.height - root.height/2))/
                        Math.tan((90 + turret.rotation)* 0.017453293)
        }
    }
}
